#ifndef WAVFILE_H
#define WAVFILE_H

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
    int32_t lSize;
    uint8_t chunkID[4];
    uint32_t chunkSize;
    uint8_t fmt[4], subCh1ID[4];
    uint32_t sChnk1Size;
    uint16_t audFmt, numChannel;
    uint32_t sampleRate, byRt;
    uint16_t blckAlign, bitsPsample;
    uint8_t subCh2ID[4];
    uint32_t subCh2Size;
    int16_t* data;

public:
    WavFile();
    WavFile(QString);

    double fs;

    QVector<double> t_x,pcm_y;
    QVector<double> x,y;
    QVector<double> t_pltx, pcm_plty;

    void readWav();
    void setDummy(QVector<double> &, QVector<double> &);
    void setAudio();
    void displayDownsample();
};

#endif // WAVFILE_H
