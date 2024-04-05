/********************************************************************************
** Form generated from reading UI file 'imag.ui'
**
** Created: Sun Apr 19 00:10:02 2015
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAG_H
#define UI_IMAG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imag
{
public:

    void setupUi(QWidget *imag)
    {
        if (imag->objectName().isEmpty())
            imag->setObjectName(QString::fromUtf8("imag"));
        imag->resize(320, 240);

        retranslateUi(imag);

        QMetaObject::connectSlotsByName(imag);
    } // setupUi

    void retranslateUi(QWidget *imag)
    {
        imag->setWindowTitle(QApplication::translate("imag", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class imag: public Ui_imag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAG_H
