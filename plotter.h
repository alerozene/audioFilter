#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

namespace Ui {
class Plotter;
}

class Plotter : public QWidget
{
    Q_OBJECT

public:
    explicit Plotter(QWidget *parent = nullptr);
    ~Plotter();

private:
    Ui::Plotter *ui;
};

#endif // PLOTTER_H
