#include "audiofilter.h"
#include "ui_audiofilter.h"
#include <QFileDialog>


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
    // reads
    // Plotter graph;
    // graph.setModal()
    // graph.exec;

}
