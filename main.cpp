#include "audiofilter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    audioFilter w;
    w.show();
    return a.exec();
}
