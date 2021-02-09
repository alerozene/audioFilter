#ifndef GAUSSNOISE_H
#define GAUSSNOISE_H

#include "wavfile.h"
#include <random>
#include <chrono>

class GaussNoise
{
public:
    GaussNoise();
    void add_zmwn(QVector<double> &);
};

#endif // GAUSSNOISE_H

