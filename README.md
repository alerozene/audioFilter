# Filter Audio signals

## Program structure
The best way for me to learn is by trying. When trying is too hard, the best thing to do is to follow a tutorial. With this set of instructions I wish to show the process I went through to build this app with little qt background. 

## Resources and where I stand now 

In process of making the Qwidget application following partly the [first tutorial](https://doc.qt.io/qtcreator/creator-writing-program.html) for window creation and now stuck at browsing the file following [this post](https://stackoverflow.com/questions/5602798/how-to-launch-a-file-browser-in-a-qt-application). The stuck part was because I wasnt't rebuilding...

Then I added a plain text widget in the ui and set it to display the path

Next, create a new ui.h for the plot and access it from the button clicked function


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