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


//https://forum.qt.io/topic/75874/want-to-make-the-qlineedit-as-readonly-and-color-the-text-as-grey-to-show-it-is-disabled/6
