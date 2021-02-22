#ifndef DETAILVIEW_H
#define DETAILVIEW_H

#include "wavfile.h"
#include "filter.h"
#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class Detailview;
}

class Detailview : public QWidget
{
    Q_OBJECT

public:
    explicit Detailview(QWidget *parent = nullptr);
    ~Detailview();

    void passvecs(WavFile *, Filter *);

private:
    Ui::Detailview *ui;
    QVector<double> adjustRange(QVector<double>&);
};

#endif // DETAILVIEW_H
