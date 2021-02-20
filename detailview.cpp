#include "detailview.h"
#include "ui_detailview.h"

Detailview::Detailview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Detailview)

{
    ui->setupUi(this);




}

Detailview::~Detailview()
{
    delete ui;
}

void Detailview::passvecs(WavFile *raw, Filter *filt){

    QVector<double> mintx, minraw, minfilt;
    mintx = adjustRange(&raw->t_x);
    minraw = adjustRange(&raw->pcm_y);
    minfilt = adjustRange(&filt->filtered);

    ui->rawfilt->addGraph();
    ui->rawfilt->addGraph();
    ui->rawfilt->graph(0)->setPen(QPen(Qt::red));
    ui->rawfilt->graph(1)->setPen(QPen(Qt::blue));
    ui->rawfilt->graph(0)->setData(mintx,minraw);
    ui->rawfilt->graph(1)->setData(mintx,minfilt);

}


QVector<double> Detailview::adjustRange(QVector<double>* raw){

    int samplelen = 150;
    QVector<double> sml;
    sml.reserve(samplelen);
    int stp = raw->size()/2;
    for(int i = 0; i<samplelen;i++){
        sml.append(raw[stp+i]);
    }
    return sml;
}
