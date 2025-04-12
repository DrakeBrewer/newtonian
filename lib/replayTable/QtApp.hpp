#ifndef REPLAYTABLEWIDGET_H
#define REPLAYTABLEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QListWidget>
#include <QFileDialog>
#include <QString>
#include <QApplication>
#include <QSpinBox>
#include <QLabel>
#include "replayTable.hpp"
#include "engine.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class ReplayTableWidget;
}

QT_END_NAMESPACE

class ReplayTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReplayTableWidget(QWidget *parent = nullptr);
    ~ReplayTableWidget();

    void setRigidBody(RigidBody *body);

private:
    Ui::ReplayTableWidget *ui;
    QTableWidget *tableWidget;
    QPushButton *updateButton;
    QPushButton *exportButton;
    QListWidget *attributeListWidget;
    QSpinBox *frequencySpinBox;
    QLabel *frequencyLabel; 

    replayTable *tableData = nullptr;
    replayTableUpdater *tableUpdater = nullptr;
    RigidBody *rigidBody = nullptr;

    std::vector<std::string> selectedAttributes;

    void updateTable();
    void initTable();
    void updateListWidget();
    void updateAttributes();

private slots:
    void exportTableToCSV();
    void onFrequencyChanged(int freq);
};

#endif // REPLAYTABLEWIDGET_H
