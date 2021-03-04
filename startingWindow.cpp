

#include "startingWindow.h"
#include "ui_startingWindow.h"
#include "plotter.h"
#include <QFileDialog>
#include<iostream>


StartingWindow::StartingWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartingWindow)
{
    ui->setupUi(this);
    fileNoise = false;
    filter_index = 0;
}

StartingWindow::~StartingWindow()
{
    delete ui;
}


void StartingWindow::on_loadFile_clicked()
{
    // open a navigator window to load a file
    StartingWindow::fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "C:/",
                                                    tr("Audio (*.wav)"));

    if(fileName!=nullptr){
        // Write the text back to the widget
        ui->plainTextEdit->setPlainText(StartingWindow::fileName);
        // Prompt plot window: approach 1 heap
        Plotter *graph = new Plotter();
        graph->setupPlot(this);
        //graph->show();
    }
}

void StartingWindow::on_cleanButton_clicked()
{
    fileNoise = false;
    //ui->cleanButton->setStyleSheet("QPushButton{ background-color: yellow }");
}

void StartingWindow::on_noisyButton_clicked()
{
    fileNoise = true;
    //ui->noisyButton->setStyleSheet("QPushButton{ background-color: yellow }");
}


// Find a better way to do this and also change in .h
// https://doc.qt.io/qt-5/qmessagebox.html this is a better way

void StartingWindow::on_lowpass1_clicked()    {filter_index = 0;}
void StartingWindow::on_lowpass2_clicked()    {filter_index = 1;}
void StartingWindow::on_highpass1_clicked()   {filter_index = 2;}
void StartingWindow::on_highpass2_clicked()   {filter_index = 3;}
void StartingWindow::on_bandpass_clicked()    {filter_index = 4;}
void StartingWindow::on_pushButton_8_clicked(){filter_index = 5;}
