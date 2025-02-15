#include "examplewindow.hpp"

example_window::example_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::example_window)
{
    ui->setupUi(this);
    // Code to connect horizontal slider to progress bar using slots
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
}

example_window::~example_window()
{
    delete ui;
}

// Update label to the current value of the horizontal slider
void example_window::on_pushButton_clicked()
{
    int sliderVal = ui->horizontalSlider->value();
    ui->label->setText(QString("Current Value: %1").arg(sliderVal));
}
