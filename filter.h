#ifndef FILTER_H
#define FILTER_H

#include "wavfile.h"
#include <QtCore/QVector>
#include <math.h>
#include <QObject>

// for slots and sigs, define as qobject class
class Filter: public QObject
{
    Q_OBJECT

    int filter_index;

    // this should be somehow inherited from the main window
    double w = tan(M_PI*fc/fs);

    QVector<double> rawsig;
    double b0, b1, b2;
    double a1, a2;
    double z[4];


    void correlation1(double);
    double correlation2(double);

    // different IIR filters
    void lowPass_1st() ;
    void lowPass_2nd() ;
    void highPass_1st();
    void highPass_2nd();
    void bandPass_2nd();
    void paramEQ_2nd() ;



public slots:
    void rec_fc(double ffc);
    void rec_q(double ffc);
    void rec_g(double ffc);


public:
    QVector<double> filtered;
    Filter();
    Filter( WavFile *, int);
    void apply_filter();
    double fs;
    double fc = fs*2.0;
    double g = 1.0;
    double q = 0.5;

};

#endif // FILTER_H
