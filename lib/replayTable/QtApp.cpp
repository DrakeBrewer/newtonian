#include "QtApp.hpp"
#include <QTableWidgetItem>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QMessageBox>

ReplayTableWidget::ReplayTableWidget(QWidget *parent)
    : QWidget(parent)
{
    tableWidget = new QTableWidget(this); // table widget
    updateButton = new QPushButton("Update Table", this);
    exportButton = new QPushButton("Export to CSV", this);
    frequencySpinBox = new QSpinBox(this);
    frequencySpinBox->setMinimum(1);
    frequencySpinBox->setMaximum(100);
    frequencySpinBox->setValue(1);

    QLabel* frequencyLabel = new QLabel("Update Frequency (ticks):", this);
    attributeListWidget = new QListWidget(this);  
    QVBoxLayout *layout = new QVBoxLayout(); // not implemented yet
    layout->addWidget(attributeListWidget);  // widget for selecting attributes, not really set up yet 
    layout->addWidget(tableWidget);
    layout->addWidget(updateButton);
    layout->addWidget(exportButton);
    layout->addWidget(frequencySpinBox);
    layout->addWidget(frequencyLabel);
    setLayout(layout);

    tableData = new replayTable(); // make a replaytable
    RigidBody* obj = nullptr; // set the rigidbody to null for now
    tableUpdater = nullptr; // table updater to null

    // Connect all wigits up
    // updateButton calls updateTable
    connect(updateButton, &QPushButton::clicked, this, &ReplayTableWidget::updateTable);
    connect(exportButton, &QPushButton::clicked, this, &ReplayTableWidget::exportTableToCSV);
    // Get what attributes to check
    connect(attributeListWidget, &QListWidget::itemChanged, this, &ReplayTableWidget::updateAttributes);
    connect(frequencySpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &ReplayTableWidget::onFrequencyChanged);
    initTable();
}

// deconstructor
ReplayTableWidget::~ReplayTableWidget()
{
    delete tableWidget;
    delete updateButton;
    delete exportButton;
    delete tableData;
    delete tableUpdater;
    delete frequencySpinBox;
    delete frequencyLabel;
}

// Set up the inital table
void ReplayTableWidget::initTable()
{
    const auto& table = tableData->getTable();
    if (table.empty()) return;

    const auto& firstRow = table.front();
    tableWidget->setColumnCount(firstRow.size());

    int col = 0;
    // Set up the header
    for (const auto& elem : firstRow) {
        tableWidget->setHorizontalHeaderItem(col++, new QTableWidgetItem(QString::fromStdString(elem.first)));
    }
    // Get the actual data.
    tableWidget->setRowCount(table.size());
    for (int row = 0; row < table.size(); ++row) {
        const auto& rowData = table[row];
        int col = 0;
        for (const auto& elem : rowData) {
            // need to convert from variant data to string
            tableWidget->setItem(row, col++, new QTableWidgetItem(QString::fromStdString(variantToString(elem.second))));
        }
    }
}


// Works mostly the same as initTable. Reuses a lot of logic from
// exportCSV in replayTableData
void ReplayTableWidget::updateTable()
{
    if(!tableUpdater) return;
    tableUpdater->update(); // update the table data first

    const auto& table = tableData->getTable();
    if (table.empty()) return;

    const auto& firstRow = table.front();
    std::vector<std::string> columnNames;
    for(const auto& elem : firstRow)
    {
        columnNames.push_back(elem.first);
    }
    // Compiler got mad if i didn't static cast
    tableWidget->setColumnCount(static_cast<int>(columnNames.size()));
    for (int col = 0; col < columnNames.size(); ++col)
    {
        tableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem(QString::fromStdString(columnNames[col])));
    }
    // get data
    tableWidget->setRowCount(static_cast<int>(table.size()));
    int rowIndex = 0;
    for (const auto& row : table) 
    {
        int colIndex = 0;
        for (const auto& elem : row) 
        {
            tableWidget->setItem(rowIndex, colIndex++, new QTableWidgetItem(QString::fromStdString(variantToString(elem.second))));
        }
        rowIndex++;
    }
}

void ReplayTableWidget::updateAttributes()
{
    selectedAttributes.clear();

    for (int row = 0; row < attributeListWidget->count(); ++row) {
        QListWidgetItem *item = attributeListWidget->item(row);
        if (item->checkState() == Qt::Checked) {
            selectedAttributes.push_back(item->text().toStdString());  // add the selected attribute
        }
    }
    // update tracked attributes
    if (tableUpdater) tableUpdater->setTrackedAttributes(selectedAttributes);
}

// makes a window show up to select where to put the file
void ReplayTableWidget::exportTableToCSV()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save Table as CSV", "", "CSV Files (*.csv)");
    if (filename.isEmpty()) return;

    tableData->exportCSV(filename.toStdString());  // Export to CSV
}

void ReplayTableWidget::updateListWidget()
{
    if (!rigidBody) return;
    attributeListWidget->clear();

    const auto& attributes = rigidBody->getAttributes();  
    for (const auto& attr : attributes) {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(attr.first));
        item->setCheckState(Qt::Unchecked);
        attributeListWidget->addItem(item);
    }
}

void ReplayTableWidget::setRigidBody(RigidBody *body)
{
    rigidBody = body;
    if (!tableUpdater) {
        int freq = frequencySpinBox->value();
        tableUpdater = new replayTableUpdater(rigidBody, tableData, selectedAttributes, freq);
    }

    updateListWidget();  
    updateAttributes();
}

void ReplayTableWidget::onFrequencyChanged(int freq)
{
    if (tableUpdater) tableUpdater->updateFrequency = freq;
}
