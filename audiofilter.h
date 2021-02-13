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

    int noise = 1;
    int lwpass1 = 1;
    int lwpass2 = 0;
    int hpass1 = 0;
    int hpass2 = 0;
    int bndpass = 0;
    int parameq =0;

private slots:
    void on_loadFile_clicked();

    void on_cleanButton_clicked();

    void on_noisyButton_clicked();

    void on_lowpass1_clicked();

    void on_lowpass2_clicked();

    void on_highpass1_clicked();

    void on_highpass2_clicked();

    void on_bandpass_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::audioFilter *ui;
};
#endif // AUDIOFILTER_H
