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


    // create graph and assign data to it:
    ui->customPlot->addGraph();

    ui->customPlot->graph(0)->setData(song.t_pltx,song.pcm_plty);

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("time [s]");
    ui->customPlot->yAxis->setLabel("PCM");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, vecutils::max(song.t_pltx));
    ui->customPlot->yAxis->setRange(vecutils::min(song.pcm_plty), vecutils::max(song.pcm_plty));
    // zoom and drag options
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->replot();
}

void Plotter::setPathString(QString pathread)
{

    pathname = pathread;
}
