#ifndef AUDIOFILTER_H
#define AUDIOFILTER_H


#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class audioFilter; }
QT_END_NAMESPACE

class audioFilter : public QWidget
{
    Q_OBJECT

public:
    audioFilter(QWidget *parent = nullptr);
    ~audioFilter();

private slots:
    void on_loadFile_clicked();

private:
    Ui::audioFilter *ui;
};
#endif // AUDIOFILTER_H
