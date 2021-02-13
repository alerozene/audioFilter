#include "filter.h"
#include "plotter.h"
#include "wavfile.h"
#include "vecutils.h"
#include "ui_plotter.h"

Plotter::Plotter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plotter)

{
    ui->setupUi(this);



}

Plotter::~Plotter()
{
    delete ui;
}

void Plotter::setupPlot()
{

    WavFile song(pathname);
    Filter shavesig(song.pcm_y);


    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(song.t_x,song.pcm_y);

    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->graph(1)->setData(song.t_x,shavesig.filtered);

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("time [s]");
    ui->customPlot->yAxis->setLabel("PCM");

    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, vecutils::max(song.t_x));
    ui->customPlot->yAxis->setRange(vecutils::min(song.pcm_y), vecutils::max(song.pcm_y));

    // zoom and drag options
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->replot();
}



void Plotter::setPathString(QString pathread)
{

    pathname = pathread;
}
