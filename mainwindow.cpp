#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduino = new QSerialPort(this);
    arduino->setPortName("COM9");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connect_clicked()
{

    if(arduino->open(QIODevice::ReadWrite))
    {
        arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            // Skipping hw/sw control
            arduino->setFlowControl(QSerialPort::NoFlowControl);

    }
}

void MainWindow::on_ledOn_clicked()
{
    arduino->write("O");

}

void MainWindow::on_ledOff_clicked()
{
    arduino->write("N");
}
