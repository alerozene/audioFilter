#ifndef VECUTILS_H
#define VECUTILS_H

#include <algorithm>
#include <QtCore/QVector>

namespace vecutils {

template<typename T>
T min(QVector<T> & vec)
{
    T mn;
    return mn = *std::min_element(vec.constBegin(), vec.constEnd());
}

template<typename S>
S max(QVector<S> & vec)
{
    S max;
    return max = *std::max_element(vec.constBegin(), vec.constEnd());
}
}



#endif // VECUTILS_H
