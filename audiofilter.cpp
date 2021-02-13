#include "audiofilter.h"
#include "ui_audiofilter.h"
#include "plotter.h"
#include <QFileDialog>
#include<iostream>


audioFilter::audioFilter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::audioFilter)
{
    ui->setupUi(this);
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
    audioFilter::noise = 0;
    ui->cleanButton->setStyleSheet("QPushButton{ background-color: yellow }");
}

void audioFilter::on_noisyButton_clicked()
{
    audioFilter::noise = 1;
    ui->cleanButton->setStyleSheet("QPushButton{ background-color: yellow }");
}


// Find a better way to do this and also change in .h

void audioFilter::on_lowpass1_clicked()
{
    audioFilter::lwpass1 = 1;
    audioFilter::lwpass2 = 0;
    audioFilter::hpass1 = 0;
    audioFilter::hpass2 = 0;
    audioFilter::bndpass = 0;
    audioFilter::parameq = 0;

}

void audioFilter::on_lowpass2_clicked()
{
    audioFilter::lwpass1 = 0;
    audioFilter::lwpass2 = 1;
    audioFilter::hpass1 = 0;
    audioFilter::hpass2 = 0;
    audioFilter::bndpass = 0;
    audioFilter::parameq = 0;

}

void audioFilter::on_highpass1_clicked()
{
    audioFilter::lwpass1 = 0;
    audioFilter::lwpass2 = 0;
    audioFilter::hpass1 = 1;
    audioFilter::hpass2 = 0;
    audioFilter::bndpass = 0;
    audioFilter::parameq = 0;

}

void audioFilter::on_highpass2_clicked()
{
    audioFilter::lwpass1 = 0;
    audioFilter::lwpass2 = 0;
    audioFilter::hpass1 = 0;
    audioFilter::hpass2 = 1;
    audioFilter::bndpass = 0;
    audioFilter::parameq = 0;
}

void audioFilter::on_bandpass_clicked()
{
    audioFilter::lwpass1 = 0;
    audioFilter::lwpass2 = 0;
    audioFilter::hpass1 = 0;
    audioFilter::hpass2 = 0;
    audioFilter::bndpass = 1;
    audioFilter::parameq = 0;
}

void audioFilter::on_pushButton_8_clicked()
{
    audioFilter::lwpass1 = 0;
    audioFilter::lwpass2 = 0;
    audioFilter::hpass1 = 0;
    audioFilter::hpass2 = 0;
    audioFilter::bndpass = 0;
    audioFilter::parameq = 1;
}
