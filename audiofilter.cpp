#include "audiofilter.h"
#include "ui_audiofilter.h"
#include <QFileDialog>
#include "plotter.h"

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
    //
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "C:/",
                                                    tr("Audio (*.wav)"));
    ui->plainTextEdit->setPlainText(fileName);

    // approach 1 heap
    Plotter *graph = new Plotter();
    graph->show();

    // alternatively, modal approach which uses stack and freezes the first window. requires
    // set.modal and an include header at the top of this file
    // reads
    // Plotter graph;
    // graph.setModal()
    // graph.exec;

}
