
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

#include <iostream>
#include <stdio.h>  // fopen and fseek
#include <stdlib.h> // malloc
using namespace std;

class WavFile{

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
    void readWav(const char *fname);
    //function with Qvector return type

};


// Read content of wavfile: 
void WavFile::readWav(const char *fname){
   
    // open file as read only "rb"        
    pFile = fopen (fname,"rb");

    if (pFile==NULL){fprintf(stderr, "Null file");}
    else
    {
        // obtain file size:
        fseek (pFile , 0 , SEEK_END);
        lSize = ftell (pFile);
        rewind (pFile);
        cout<<lSize<<endl;

        // set last char to 0
        chunkID[4] = '\0';
        fmt[4] = '\0';
        subCh1ID[4] = '\0';

        //RIFF chunk descriptor. 
        //fstream functions move the pointer
        fread(&chunkID,sizeof(uint8_t) ,4, pFile);
        fread(&chunkSize,sizeof(uint32_t),1,pFile);
        fread(&fmt,sizeof(uint8_t),4,pFile);
        
        // Format subchunk
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
        cout<<"size of file = "<<lSize<<endl;
        cout<<"Chunk ID: "<<chunkID<<endl;
        cout<<"Chunk size: "<<chunkSize<<endl;
        cout<<"Format: "<<fmt<<endl;
        cout<<"Sub chunk 1 ID: " <<subCh1ID<<endl;
        cout<<"PCM "<< sChnk1Size<< " bit"<<endl;
        cout<<"Quantization = "<< audFmt<< " PCM = 1, other is compression"<<endl;
        cout<<"# channels = "<< numChannel<<endl;
        cout<<"Sample rate = "<< sampleRate<<endl;
        cout<<"Byte rate = "<< byRt<<endl;
        cout<<"NumChannels * BitsPerSample/8 = "<< blckAlign<<endl;
        cout<<"BitsPerSample (8 or 16) = "<< bitsPsample<<endl;
        cout<<"Sub chunk 2 ID: "<<subCh2ID<<endl;
        cout<<" == NumSamples * NumChannels * BitsPerSample/8: "<<subCh2Size<<endl;
        for (int i = 4995; i < 5000; i++)
        {
            cout<<data[i]<<endl;
        }
        
    }
}



void readWavSimple(char *fname){

    FILE * pFile;
    long lSize;
    short metdata = 44;
    int *buffer;

    pFile = fopen (fname,"rb");

    if (pFile==NULL){fprintf(stderr, "Null file");}
    else
    {
        // obtain file size:
        fseek (pFile , 0 , SEEK_END);
        lSize = ftell (pFile);
        rewind (pFile);

       // skip firsrt 44bits
       lSize -=metdata;
       
       buffer = (int*) malloc (sizeof(int)*lSize);

       fseek( pFile, metdata, SEEK_SET );
       fread ( buffer, sizeof(int), sizeof(int), pFile );

       // You may pring every value
       //for(int i=0; i<lSize;i++){cout<<buffer[i]<<endl;} 
       cout<<buffer[5000]<<endl;

       fclose (pFile);
       free (buffer);
    }
}


int main()
{
    WavFile an;
    an.readWav("C:/Users/Alex/Documents/cpp/audioFilter/gong.wav");
    //readWavSimple("C:/Users/Alex/Documents/cpp/vsgeneric/gong.wav");
    cout << "\n Hello World" << endl;
}