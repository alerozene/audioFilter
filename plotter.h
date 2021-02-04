#ifndef PLOTTER_H
#define PLOTTER_H

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

    void setupPlot();
    void setPathString(QString);



private:
    Ui::Plotter *ui;
    QString pathname;

};

#endif // PLOTTER_H
