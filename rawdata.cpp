#include "rawdata.h"

Rawdata::Rawdata(): x(101),y(101)
{
    setValues(x,y);

}

void Rawdata::setValues(QVector<double>& x, QVector<double> &y)
{

    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }

}
