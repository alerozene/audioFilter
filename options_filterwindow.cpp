

#include "options_filterwindow.h"
#include "ui_options_filterwindow.h"

Options_filterWindow::Options_filterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options_filterWindow)
{
    ui->setupUi(this);





}

Options_filterWindow::~Options_filterWindow()
{
    delete ui;
}

void Options_filterWindow::setvals(double smth)
{
    fs = smth;
    sigma = 5000.0;

    g = 1.0;
    q = 0.5;
    fc = fs*2.0;

    ui->edit_fs->setText(QString::number(fs));
    ui->edit_g->setText(QString::number(g));
    ui->edit_q->setText(QString::number(q));
    ui->edit_fc->setText(QString::number(fc));
    ui->edit_sigma->setText(QString::number(sigma));
}


//https://forum.qt.io/topic/75874/want-to-make-the-qlineedit-as-readonly-and-color-the-text-as-grey-to-show-it-is-disabled/6

void Options_filterWindow::on_edit_fc_textChanged(const QString &arg2){ emit fc_chngd(arg2.toDouble()); }

void Options_filterWindow::on_edit_q_textChanged(const QString &arg3)
{
    emit q_chngd(arg3.toDouble());

}

void Options_filterWindow::on_edit_g_textChanged(const QString &arg1)
{
    emit g_chngd(arg1.toDouble());
}

void Options_filterWindow::on_buttonBox_accepted()
{

    this->close();

}


