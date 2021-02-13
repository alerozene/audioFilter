
#include "globals.h"
#include "filter.h"
#include <QtCore/QVector>

int filter_index;

Filter::Filter()
{

}

Filter::Filter(QVector<double> &rwsg): rawsig(rwsg)
{
    apply_filter();
}

void Filter::apply_filter()
{
    int fi = filter_index;
    switch (fi)
    {
        case 0: Filter::lowPass_1st() ; break;
        case 1: Filter::lowPass_2nd() ; break;
        case 2: Filter::highPass_1st(); break;
        case 3: Filter::highPass_2nd(); break;
        case 4: Filter::bandPass_2nd(); break;
        case 5: Filter::paramEQ_2nd() ; break;

    }
    filtered.reserve(rawsig.size());


    // ////////////////////////////////
    // i cannot get a fifo structure with the qvector, re-write with custom vector

    int i(0);

    while(i<rawsig.size())

    {
        correlation1(rawsig[i]);

        // passing rawsing now seems a bit stupid
        // append is nice since it is o(1) https://en.wikipedia.org/wiki/Dynamic_array
        filtered.append(correlation2(rawsig[i]));
        i+=1;

    }
}




//Cascade structure: non-recursive part
void Filter::correlation1(double x)
{
    double acc = x*b0 + z[0]*b1 - z[1]*a1;
    z[1] = acc;
    z[0] = x;
}

// recursive part
double Filter::correlation2(double x)
{
    double acc = x*b0 + z[0]*b1 + z[1]*b2-z[2]*a1-z[3]*a2;
    z[3] = z[2];
    z[2] = acc;
    z[1] = z[0];
    z[0] = x;
    return z[2];
}

void Filter::lowPass_1st()
{
    double n = 1/(1+w);
    b0 = n*w;
    b1 = b0;
    a1 = n*(w-1);
    // set everything else to 0
    a2 = b2 = 0.0;

}

void Filter::lowPass_2nd()
{
    double n = 1/(1+w+pow(w,2.0)+w/q);
    b0 = n*pow(w,2.0);
    b1 = 2.0*b0;
    b2 = b0;
    a1 = 2.0*n*(pow(w,2.0)-1);
    a2 = n*(pow(w,2.0)-w/q+1);
}

void Filter::highPass_1st()
{
    Filter::lowPass_1st();
    b0 = b0/w;
    b1 = -b1;
}

void Filter::highPass_2nd()
{
    Filter::lowPass_2nd();
    b0 = b0/pow(w,2.0);
    b1 = -2.0*b0;
}

void Filter::bandPass_2nd()
{
    double n = 1/(1+w+pow(w,2.0)+w/q);
    b0 = n*w/q;
    b1 = 0.0;
    b2 = -b0;
    a1 = 2.0*n*(pow(w,2.0)-1);
    a2 = n*(pow(w,2.0)-w/q+1);
}

void Filter::paramEQ_2nd()
{
    //double bnd_wdth = fc/q;
    if(g<1){q = q*g;}
    double a = g/q;
    double n = 1/(1+w+pow(w,2.0)+w/q);
    b0 = n*(pow(w,2.0)+w*a+1);
    b1 = 2*n*(pow(w,2.0)-1);
    b2 = n*(pow(w,2.0)-w*a+1);
    a1 = b1;
    a2 = n*(pow(w,2.0)-w/q+1);
}
