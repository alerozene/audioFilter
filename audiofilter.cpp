#include "audiofilter.h"
#include "ui_audiofilter.h"
#include <QFileDialog>

audioFilter::audioFilter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::audioFilter)
{
    ui->setupUi(this);
}

audioFilter::~audioFilter()
{
    delete ui;
}


void audioFilter::on_loadFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "C:/",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    //ui->listWidget->addItems(fileName);
}
