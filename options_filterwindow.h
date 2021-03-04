#ifndef OPTIONS_FILTERWINDOW_H
#define OPTIONS_FILTERWINDOW_H

#include "filter.h"
#include "plotter.h"
#include <QDialog>

namespace Ui {
class Options_filterWindow;
}

class Options_filterWindow : public QDialog
{
    Q_OBJECT

public:

    explicit Options_filterWindow(QWidget *parent = nullptr);
    ~Options_filterWindow();

    void setvals(double, bool);


    double fs;
    double sigma;
    double fc;
    double q;
    double g;

    double *fcptr;

private slots:
    void on_buttonBox_accepted();
    void on_edit_q_textChanged(const QString &arg1);

    void on_edit_g_textChanged(const QString &arg1);

public slots:

    void on_edit_fc_textChanged(const QString &arg1);
signals:
    void fc_chngd(double);
    void q_chngd(double);
    void g_chngd(double);



private:
    Ui::Options_filterWindow *ui;
};

#endif // OPTIONS_FILTERWINDOW_H
