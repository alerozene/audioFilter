#ifndef PLOTTER_H
#define PLOTTER_H

#include "filter.h"
#include "wavfile.h"
#include "startingWindow.h"
#include <QWidget>
#include "qcustomplot.h"


namespace Ui {
class Plotter;
}

class Plotter : public QWidget
{
    Q_OBJECT


public:
    explicit Plotter(QWidget *parent = nullptr);
    ~Plotter();

    void setupPlot(StartingWindow *);



private:
    Ui::Plotter *ui;
    StartingWindow *mainWidget;



};

#endif // PLOTTER_H
