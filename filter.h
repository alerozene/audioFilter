#ifndef FILTER_H
#define FILTER_H

#include "wavfile.h"
#include <QtCore/QVector>
#include <math.h>







class Filter
{

    int filter_index;

    // this should be somehow inherited from the main window
    double g = 1.0;
    double q = 1.0/2.0;
    double fc = 1000.0;
    double fs;

    // fs was defined in globals.h
    double w = tan(M_PI*fc/fs);

    QVector<double> rawsig;
    double b0, b1, b2;
    double a1, a2;
    double z[4];

    void apply_filter();
    void correlation1(double);
    double correlation2(double);

    // different IIR filters
    void lowPass_1st() ;
    void lowPass_2nd() ;
    void highPass_1st();
    void highPass_2nd();
    void bandPass_2nd();
    void paramEQ_2nd() ;



public:
    QVector<double> filtered;
    Filter();
    Filter( WavFile *wv, int);
};

#endif // FILTER_H
