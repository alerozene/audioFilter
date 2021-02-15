#ifndef OPTIONS_FILTERWINDOW_H
#define OPTIONS_FILTERWINDOW_H

#include <QDialog>

namespace Ui {
class Options_filterWindow;
}

class Options_filterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Options_filterWindow(QWidget *parent = nullptr);
    ~Options_filterWindow();

private:
    Ui::Options_filterWindow *ui;
};

#endif // OPTIONS_FILTERWINDOW_H
