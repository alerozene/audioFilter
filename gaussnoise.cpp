/*
 * Create additive noise and add it to a signal.
 *
 * https://en.cppreference.com/w/cpp/numeric/random/normal_distribution
 * https://stackoverflow.com/questions/32889309/adding-gaussian-noise
 *
*/
#include "gaussnoise.h"

GaussNoise::GaussNoise(double std): sigma(std)
{

}

void GaussNoise::add_zmwn(QVector<double> & rawsig)
{

    long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution (0.0,sigma);

    for (int i=0; i<rawsig.size(); ++i)
      rawsig+= distribution(generator);

}
