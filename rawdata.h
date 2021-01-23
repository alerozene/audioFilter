#ifndef RAWDATA_H
#define RAWDATA_H

//#include<QVector>
#include <QtCore/QVector>

class Rawdata
{

public:

    // Method 1: Declare constructor in .cpp
    QVector<double> x, y;
    Rawdata();
    void setValues(QVector<double> &, QVector<double> &);


    // Method 2: declare constructor here (comment out the declaration in .cpp file)
    //QVector<double> x, y;
    //Rawdata(): x(101),y(101){}

    /* Method 3
    QVector<double> x(101), y(101);
    Rawdata()
    {}
    https://stackoverflow.com/questions/39560277/vector-declaration-expected-parameter-declarator
    */

};

#endif // RAWDATA_H
