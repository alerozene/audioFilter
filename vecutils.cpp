#include "vecutils.h"

double vecutils::min(QVector<double> & vec)
{
    double min;
    return min = *std::min_element(vec.constBegin(), vec.constEnd());
}

double vecutils::max(QVector<double> & vec)
{
    double max;
    return max = *std::max_element(vec.constBegin(), vec.constEnd());
}
