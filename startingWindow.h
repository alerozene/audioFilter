#ifndef AUDIOFILTER_H
#define AUDIOFILTER_H


#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class StartingWindow; }
QT_END_NAMESPACE

class StartingWindow : public QWidget
{
    Q_OBJECT

public:
    StartingWindow(QWidget *parent = nullptr);
    ~StartingWindow();

    // this are passed to plotter, wavfile and filter
    int noise;
    int filter_index;
    double sigma;
    QString fileName;

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
    Ui::StartingWindow *ui;
};
#endif // AUDIOFILTER_H
