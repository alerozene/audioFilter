#ifndef GLOBALS_H
#define GLOBALS_H

extern const int VNOISE;
// sampling frequency, cutoff, gain and quality factor
extern double fs;

extern int noise,lwpass1, lwpass2, hpass1, hpass2, bndpass, parameq;
extern int filter_index;
#define DISPOINTS 1000



#endif // GLOBALS_H
