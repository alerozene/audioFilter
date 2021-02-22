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


template<typename U>
U maxmax(QVector<U> &vec1, QVector<U> &vec2)
{
    U q1 = std::max(vecutils::max(vec1),vecutils::max(vec2));
    return q1;
}

template<typename V>
V minmin(QVector<V> &vec1, QVector<V> &vec2)
{
    V q2 = std::min(vecutils::min(vec1),vecutils::min(vec2));
    return q2;
}

}
#endif // VECUTILS_H
