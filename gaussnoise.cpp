/*
 * https://stackoverflow.com/questions/32889309/adding-gaussian-noise
 *
*/
#include "gaussnoise.h"

GaussNoise::GaussNoise()
{

}

void GaussNoise::add_zmwn(QVector<double> & rawsig)
{

    long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution (0.0,1.0);

    for (int i=0; i<rawsig.size(); ++i)
      rawsig+= distribution(generator);

}
