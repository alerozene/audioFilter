
#include "globals.h"
#include "audiofilter.h"
#include "ui_audiofilter.h"
#include "plotter.h"
#include <QFileDialog>
#include<iostream>

// variables defined in globals.h and in their respective slots. Used by wavFile.cpp and Filter.cpp
int noise;

audioFilter::audioFilter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::audioFilter)
{
    ui->setupUi(this);
    noise = 0;
    filter_index = 0;
}

audioFilter::~audioFilter()
{
    delete ui;
}


void audioFilter::on_loadFile_clicked()
{
    // open a navigator window to load a file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "C:/",
                                                    tr("Audio (*.wav)"));
    // Write the text back to the widget
    ui->plainTextEdit->setPlainText(fileName);

    std::cout<<noise<<std::endl;
    std::cout<<filter_index<<std::endl;


    // Prompt plot window: approach 1 heap
    Plotter *graph = new Plotter();
    graph->setPathString(fileName);
    graph->setupPlot();
    graph->show();
    // alternatively, modal approach which uses stack and freezes the first window. requires
    // set.modal and an include header at the top of this file
    // Plotter graph;
    // graph.setModal()
    // graph.exec;

}

void audioFilter::on_cleanButton_clicked()
{
    noise = 0;
    //ui->cleanButton->setStyleSheet("QPushButton{ background-color: yellow }");
}

void audioFilter::on_noisyButton_clicked()
{
    noise = 1;
    //ui->noisyButton->setStyleSheet("QPushButton{ background-color: yellow }");
}


// Find a better way to do this and also change in .h
void audioFilter::on_lowpass1_clicked()    {filter_index = 0;}
void audioFilter::on_lowpass2_clicked()    {filter_index = 1;}
void audioFilter::on_highpass1_clicked()   {filter_index = 2;}
void audioFilter::on_highpass2_clicked()   {filter_index = 3;}
void audioFilter::on_bandpass_clicked()    {filter_index = 4;}
void audioFilter::on_pushButton_8_clicked(){filter_index = 5;}
