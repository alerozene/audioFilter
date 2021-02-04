# Filter Audio signals

## Program structure
The best way for me to learn is by trying. When trying is too hard, the best thing to do is to follow a tutorial. With this set of instructions I wish to show the process I went through to build this app with little qt background. Following the philosophy of incremental programming, I give the steps that I followed in building this piece of software

## How to use


## Resources and where I stand now 


### `audiofilter.cpp`

I got started with the Qwidget application partly following the [first Qt tutorial](https://doc.qt.io/qtcreator/creator-writing-program.html) for window creation. The file browsing was assembled following [this post](https://stackoverflow.com/questions/5602798/how-to-launch-a-file-browser-in-a-qt-application). 


Then I added a plain text widget in the ui and set it to display the path

Next, create a new ui.h for the plot and access it from the button clicked function
a

### `plotter.cpp`

## plot form
Add the form by typing...
qCustom plot tutorial
https://www.qcustomplot.com/index.php/tutorials/settingup

## Structure of the program development

1. I started by following the [first tutorial](https://doc.qt.io/qtcreator/creator-writing-program.html) for creating a QWidget in order to create a window, a button and a slot with funcionality 

`audiofilter.cpp`

`on_clicked_()` 


2. For obtaining the string to load the audio file, I followed [this post](https://stackoverflow.com/questions/5602798/how-to-launch-a-file-browser-in-a-qt-application). I then added a plain text widget in the ui to display the path
3. I added a new ui.h which I connected to 

4. Another point were I got stuck is, after changing the name of the proted customPlot widget, was: Plotter has no member...
This is because after re-naming the widget, the little red button on the picture needs to be clicked
![err2](/images/error_2.jpg)

### Qcustomplot
To learn how to use this library, just follow the [setting up](https://www.qcustomplot.com/index.php/tutorials/settingup) tutorial. For creating a plot: [this](https://www.qcustomplot.com/index.php/tutorials/basicplotting)

`rawdata.h and .cpp`
This class sets the data to be filtered and plotted. The objects need to be of type QVector [line 5102 of qcustomplot.h]





Some errors 
`No rule to make target '../../qcustomplot.h', needed by 'ui_plotter.h'.  Stop` This error was caused by an automatic update in the path to the qcustomplot file. Fixed by renaming as seen in the image below
[!norulemaketarget](/images/err_no_rule_to_make_target.jpg)

Sometimes it is also necessary to do: clean all runqmake (re)build all

`SIGSEGV segmentation fault (signal received qt dialog)`: I get this at fopen(fname) in wavfile.cpp the reason being that I convert the QString as follows: 

QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "C:/",
                                                    tr("Audio (*.wav)"));
    // Write the text back to the widget
    ui->plainTextEdit->setPlainText(fileName);

    // Prompt plot window: approach 1 heap
    Plotter *graph = new Plotter();
    graph->setPathString(fileName);
    ....

plotter.cpp

void Plotter::setPathString(QString pathread)
{
    pathname = pathread.toStdString().c_str();
}

...
And then when I want to access it from the fname there is that error

According to:

https://stackoverflow.com/questions/2523765/qstring-to-char-conversion


## `audiofilter.cpp`



## To do:
- [ ] Make template with raw data so that not only int16 is accepted
- [] Issue: wavfile.cpp t_x is stored as an int, therefore all the thousands of samples are mapped to seconds