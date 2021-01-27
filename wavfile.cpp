/**
 * ------------
 * References:
 *  - fread function https://cplusplus.com/reference/cstdio/fread/
 *  - WAV1 https://stackoverflow.com/questions/13660777/c-reading-the-data-part-of-a-wav-file
 *  - Source of the info http://soundfile.sapp.org/doc/WaveFormat/
 *  - An even better one https://www.lightlink.com/tjweber/StripWav/WAVE.html
 *  - A dude with code https://rogerchansdigitalworld.blogspot.com/2010/05/how-to-read-wav-format-file-in-c.html
 *
 *
 **/

#include "wavfile.h"

WavFile::WavFile(): x(101),y(101)
{
    setValues(x,y);
}

WavFile::WavFile(QString f ): fname(f)
{
    readWav();
    setAudio();
}

void WavFile::readWav(){

    // open file as read only "rb"
    std::string strfname = fname.toStdString();
    const char *charfname = strfname.c_str();
    pFile = fopen (charfname,"rb");


    if (pFile==NULL){fprintf(stderr, "Null file");}
    else
    {
        // obtain file size:
        fseek (pFile , 0 , SEEK_END);
        lSize = ftell (pFile);
        rewind (pFile);

        //RIFF chunk descriptor.
        //fstream functions move the pointer
        fread(&chunkID,sizeof(uint8_t) ,4, pFile);
        fread(&chunkSize,sizeof(uint32_t),1,pFile);
        fread(&fmt,sizeof(uint8_t),4,pFile);

        // format desribing subchunk
        fread(&subCh1ID,sizeof(uint8_t),4,pFile);
        fread(&sChnk1Size,sizeof(uint32_t),1,pFile);
        fread(&audFmt,sizeof(uint16_t),1,pFile);
        fread(&numChannel,sizeof(uint16_t),1,pFile);
        fread(&sampleRate,sizeof(uint32_t),1,pFile);
        fread(&byRt,sizeof(uint32_t),1,pFile);
        fread(&blckAlign,sizeof(uint16_t),1,pFile);
        fread(&bitsPsample,sizeof(uint16_t),1,pFile);

        // Data subchunk
        fread(&subCh2ID,sizeof(uint8_t),4,pFile);
        fread(&subCh2Size,sizeof(uint32_t),1,pFile);

        //Set data
        data = (uint16_t*) malloc(sizeof(uint16_t)*(lSize-44));
        fread(data ,sizeof(uint16_t),(lSize-44),pFile);
        fclose(pFile);
        uint16_t data1;
        for (int i = 4995; i < 5000; i++)
                {
                    data1 = data[i];
                }







    }
}

void WavFile::setValues(QVector<double> &x, QVector<double> &y)
{

    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }

}

void WavFile::setAudio()
{
    if(numChannel==2)
    {
        pcm_y.reserve((lSize-44)/2);
        pcm_y.append(5);
        int data1;
        for(int ii=0;ii<lSize-44;ii=ii+2)
        {
            pcm_y.append((double)data[ii]);
            if(ii==4900){
                data1 = data[ii];
            }
        }
    }




    t_x.resize(pcm_y.size());
    t_x[0] = 0;
    for(int j=1;j<t_x.size();j++)
    {
        t_x[j] = j;//sampleRate;
    }
}

