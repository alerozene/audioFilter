#include "plotter.h"
#include "ui_plotter.h"

Plotter::Plotter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plotter)
{
    ui->setupUi(this);
    setupPlot();


}

Plotter::~Plotter()
{
    delete ui;
}

void Plotter::setupPlot()
{
    Rawdata rwrw;

    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(rwrw.x,rwrw.y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);
    ui->customPlot->replot();
}
