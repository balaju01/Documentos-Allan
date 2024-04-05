#include "imag.h"
#include "ui_imag.h"

imag::imag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::imag)
{
    ui->setupUi(this);
}

imag::~imag()
{
    delete ui;
}
