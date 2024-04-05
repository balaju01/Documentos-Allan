#ifndef IMAG_H
#define IMAG_H

#include <QWidget>

namespace Ui {
    class imag;
}

class imag : public QWidget
{
    Q_OBJECT

public:
    explicit imag(QWidget *parent = 0);
    ~imag();

private:
    Ui::imag *ui;
};

#endif // IMAG_H
