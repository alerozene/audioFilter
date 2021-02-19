
#include "options_filterwindow.h"
#include "gaussnoise.h"
#include "plotter.h"
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

void Plotter::setupPlot(StartingWindow *startwin)
{
    mainWidget = startwin;


    WavFile song(mainWidget->fileName);

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(song.t_x,song.pcm_y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("time [s]");
    ui->customPlot->yAxis->setLabel("PCM");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, vecutils::max(song.t_x));
    ui->customPlot->yAxis->setRange(vecutils::min(song.pcm_y), vecutils::max(song.pcm_y));
    // zoom and drag options
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->replot();
    this->show();



    Filter shavesig( &song  , mainWidget->filter_index);

    //----------------------------------------------------------------------------------
    Options_filterWindow options;
    options.setvals(song.fs);
    options.exec();
    //------------------------------------------------------------------------------------

    if(mainWidget->noise){
        GaussNoise distort(options.sigma);
        distort.add_zmwn(song.pcm_y);
    }

/*
    QObject::connect(&options,&Options_filterWindow::fc_chngd,&shavesig,
                     &Filter::rec_fc);
    QObject::connect(&options,&Options_filterWindow::q_chngd,&shavesig,
                     &Filter::rec_q);
    QObject::connect(&options,&Options_filterWindow::g_chngd,&shavesig,
                     &Filter::rec_g);
*/

    shavesig.apply_filter();
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->graph(1)->setData(song.t_x,shavesig.filtered);
    ui->customPlot->replot();
}
