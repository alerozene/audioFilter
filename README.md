# Filter Audio signals using different IIR techniques

## Program description

This piece of software allows you to read a .wav file and perform IIR filtering on it. You may load a noisy signal or choose to add virtual noise to your file. The interface was developed using Qtcreator and qcustomplot for graph display. 


<<<<<<< HEAD
<<<<<<< HEAD
![sample_1](images/sample1.JPG)
=======
![sample](/images/sample1.jpg)
>>>>>>> parent of ab33a96 (addsampleimage)
=======
![sample](/images/sample1.jpg)
>>>>>>> parent of ab33a96 (addsampleimage)


To view the program source from qt, go to qtcreator->File->Open File or project... and select `audioFilter.pro` from this (repository) directory.



## Program structure
---
Overview of the files (other than `main.cpp`):

### `audiofilter.cpp/h`
Instantiates a form which opens a navigator window and allows to select a file with .wav extension. It then writes the string to the form. Afterwards, the program instantiates a `plotter.cpp` object and it passes the path-string to it. The plotter form is called using the heap approach, that is: reserving heap memory by calling like this:  `new Plotter();...`. Alternatively, one could use the modal approach which freezes the first window as described in [this video tutorial](https://www.youtube.com/watch?v=VigUMAfE2q4&ab_channel=ProgrammingKnowledge)

### `plotter.cpp/h`
Displays a form containing a qcustom plot widget (see qcustomplot), followed by a call to `wavfile.cpp`. This creates a wavfile object which reads the audio from the string passed to this class. Then, the graph for the plot gets displayed.  

### `wavfile.cpp/h`
The functionality of this script is better reflected in the [standalone version](wav_standalone/wav_standalone.cpp). The class takes the string and reads the Audio file contents into a QVector file

### `filter.cpp/h`

### Other files:
- `globals.h` sets global variables such as number of display samples, filter type, noise added or intrinsic...
- `vecutils.h` Vector operations for QVector class
- `qcustomplot.cpp/h` -> see program development section












## Structure of the program development

I got started with the Qwidget application partly following the [first Qt tutorial](https://doc.qt.io/qtcreator/creator-writing-program.html) for window creation. The file browsing was assembled following [this post](https://stackoverflow.com/questions/5602798/how-to-launch-a-file-browser-in-a-qt-application). 
Then I added a plain text widget in the ui and set it to display the path
Next, create a new ui.h for the plot and access it from the button clicked function
a

1. I started by following the [first tutorial](https://doc.qt.io/qtcreator/creator-writing-program.html) for creating a QWidget in order to create a window, a button and a slot with funcionality 


2. plot form
Add the form by typing...
qCustom plot tutorial
https://www.qcustomplot.com/index.php/tutorials/settingup



2. For obtaining the string to load the audio file, I followed [this post](https://stackoverflow.com/questions/5602798/how-to-launch-a-file-browser-in-a-qt-application). I then added a plain text widget in the ui to display the path
3. I added a new ui.h which I connected to 

4. Make buttons checkable (properties, bottom right of the design window). Group them inside a widget and click on autoexclusive

### Program development
For creating the qt widget structure, I followed the [setting up](https://www.qcustomplot.com/index.php/tutorials/settingup) tutorial.

The graph uses the qcustomplot, wich  [this](https://www.qcustomplot.com/index.php/tutorials/basicplotting)

`rawdata.h and .cpp`
This class sets the data to be filtered and plotted. The objects need to be of type QVector [line 5102 of qcustomplot.h]





## Collection of non-soverflow errors

|error message|error described|solved|
|:---:|:---:|:---:|
| `No rule to make target '../../qcustomplot.h', needed by 'ui_plotter.h'.  Stop`|This error was caused by an automatic update in the path to the qcustomplot file. Fixed by renaming as seen in the image below [!norulemaketarget](/images/err_no_rule_to_make_target.jpg) | YES |
| `SIGSEGV segmentation fault (signal received qt dialog)` | I get this at fopen(fname) in wavfile.cpp the reason being that I convert the QString as follows | QString to char conversion should be done properly [see](https://stackoverflow.com/questions/2523765/qstring-to-char-conversion) |
| Plotter has no member... | After changing the name of the promoted customPlot widget. When re-naming the widget, the little red button on the picture needs to be clicked ![err2](/images/error_2.jpg) | YES |  
| `...\moc_audiofilter.cpp:83: error: undefined reference to audioFilter::on_pushButton_2_clicked()` | Forgot to delete function for that slot in the header| YES |


## To do:
- [x] Make template with raw data so that not only int16 is accepted: actually this cannot be done since the selection happens at compile time; [this](https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file?rq=1) may be a solution 
- [ ] Create a live audio version of this software where microphone data can also be read and filtered
- [ ] Find a way to make all buttons in the group of filter options the same size
- [ ] In audiofilter.cpp (and .h) change the way teh filter option is selected. Now there is one function per click, there should be an easier way to do this
- [ ] Maybe abandon globals and pass the classes across each other
- [ ] re-scaling of the main widget does not work
- [ ] Put the contents of onfileclicked into onokayclicked and prevent the program from progressing if the path to the wavfile is null pointer
- [ ] ? support for mp3


### Current bugs
---
- [ ] The "noisy" option does not work
- [ ] 










http://freeverb3vst.osdn.jp/tips/iir_filter.shtml
