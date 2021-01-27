#ifndef RAWDATA_H
#define RAWDATA_H

#include <iostream>
#include <stdio.h>  // fopen and fseek
#include <stdlib.h> // malloc

//#include<QVector>
#include <QtCore/QVector>

using namespace std;


class WavFile
{
    QString fname;

    FILE * pFile;
    uint32_t lSize;
    uint8_t chunkID[4];
    uint32_t chunkSize;
    uint8_t fmt[4], subCh1ID[4];
    uint32_t sChnk1Size;
    uint16_t audFmt, numChannel;
    uint32_t sampleRate, byRt;
    uint16_t blckAlign, bitsPsample;
    uint8_t subCh2ID[4];
    uint32_t subCh2Size;
    uint16_t* data;

public:
    WavFile();
    WavFile(QString);

    QVector<double> t_x,pcm_y;
    QVector<double> x,y;

    void readWav();
    void setValues(QVector<double> &, QVector<double> &);
    void setAudio();
};

#endif // RAWDATA_H
