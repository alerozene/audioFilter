#include "vecutils.h"
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
    mintx = adjustRange(raw->t_x);
    minraw = adjustRange(raw->pcm_y);
    minfilt = adjustRange(filt->filtered);

    ui->rawfilt->addGraph();
    ui->rawfilt->addGraph();
    ui->rawfilt->graph(0)->setPen(QPen(Qt::red));
    ui->rawfilt->graph(1)->setPen(QPen(Qt::blue));
    ui->rawfilt->graph(0)->setData(mintx,minraw);
    ui->rawfilt->graph(1)->setData(mintx,minfilt);
    ui->rawfilt->xAxis->setRange(mintx.first(),mintx.last());
    ui->rawfilt->yAxis->setRange(std::min(vecutils::min(minraw),vecutils::min(minfilt)),
                                 std::max(vecutils::max(minraw),vecutils::max(minfilt)));
    ui->rawfilt->replot();


    std::cout<<vecutils::min(minraw) <<std::endl;
    std::cout<<vecutils::min(minfilt) <<std::endl;
    std::cout<<std::min(vecutils::min(minraw),vecutils::min(minfilt)) <<std::endl;
    std::cout<<vecutils::max(minraw) <<std::endl;
    std::cout<<vecutils::max(minfilt) <<std::endl;
    std::cout<<std::max(vecutils::max(minraw),vecutils::max(minfilt)) <<std::endl;
    std::cout<<" fda" <<std::endl;



}


QVector<double> Detailview::adjustRange(QVector<double>& rw){

    int samplelen = 1000;
    QVector<double> sml;
    sml.reserve(samplelen);
    int stp = rw.size()/8;

    for(int i = 0; i<samplelen;i++){
        sml.append(rw[stp+i]);
    }
    return sml;
}
