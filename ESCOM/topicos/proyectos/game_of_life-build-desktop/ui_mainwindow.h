/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Apr 20 03:27:31 2015
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpinBox *propagacion;
    QLabel *label_2;
    QPushButton *ini_pau;
    QPushButton *limpia;
    QGroupBox *reglas;
    QRadioButton *life;
    QRadioButton *Diffussion;
    QRadioButton *personal;
    QComboBox *comboX;
    QComboBox *comboY;
    QComboBox *comboW;
    QComboBox *comboZ;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *imagen;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        propagacion = new QSpinBox(centralWidget);
        propagacion->setObjectName(QString::fromUtf8("propagacion"));
        propagacion->setMaximum(100);

        gridLayout->addWidget(propagacion, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        ini_pau = new QPushButton(centralWidget);
        ini_pau->setObjectName(QString::fromUtf8("ini_pau"));

        gridLayout->addWidget(ini_pau, 1, 2, 1, 1);

        limpia = new QPushButton(centralWidget);
        limpia->setObjectName(QString::fromUtf8("limpia"));

        gridLayout->addWidget(limpia, 1, 3, 1, 1);

        reglas = new QGroupBox(centralWidget);
        reglas->setObjectName(QString::fromUtf8("reglas"));
        life = new QRadioButton(reglas);
        life->setObjectName(QString::fromUtf8("life"));
        life->setGeometry(QRect(40, 30, 116, 22));
        Diffussion = new QRadioButton(reglas);
        Diffussion->setObjectName(QString::fromUtf8("Diffussion"));
        Diffussion->setGeometry(QRect(180, 30, 131, 22));
        personal = new QRadioButton(reglas);
        personal->setObjectName(QString::fromUtf8("personal"));
        personal->setGeometry(QRect(340, 30, 171, 22));
        comboX = new QComboBox(reglas);
        comboX->setObjectName(QString::fromUtf8("comboX"));
        comboX->setGeometry(QRect(560, 30, 85, 27));
        comboY = new QComboBox(reglas);
        comboY->setObjectName(QString::fromUtf8("comboY"));
        comboY->setGeometry(QRect(660, 30, 85, 27));
        comboW = new QComboBox(reglas);
        comboW->setObjectName(QString::fromUtf8("comboW"));
        comboW->setGeometry(QRect(760, 30, 85, 27));
        comboZ = new QComboBox(reglas);
        comboZ->setObjectName(QString::fromUtf8("comboZ"));
        comboZ->setGeometry(QRect(860, 30, 85, 27));
        label = new QLabel(reglas);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(510, 6, 451, 21));
        scrollArea = new QScrollArea(reglas);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 74, 971, 511));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 969, 509));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        imagen = new QLabel(scrollAreaWidgetContents);
        imagen->setObjectName(QString::fromUtf8("imagen"));
        imagen->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(imagen, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(reglas, 0, 0, 1, 4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Propagacion", 0, QApplication::UnicodeUTF8));
        ini_pau->setText(QApplication::translate("MainWindow", "Propagacion/Inicio/Pausa", 0, QApplication::UnicodeUTF8));
        limpia->setText(QApplication::translate("MainWindow", "Limpiar", 0, QApplication::UnicodeUTF8));
        reglas->setTitle(QString());
        life->setText(QApplication::translate("MainWindow", "Game of Life", 0, QApplication::UnicodeUTF8));
        Diffussion->setText(QApplication::translate("MainWindow", "Diffussion Rule", 0, QApplication::UnicodeUTF8));
        personal->setText(QApplication::translate("MainWindow", "Regla Personalizada", 0, QApplication::UnicodeUTF8));
        comboX->clear();
        comboX->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
        );
        comboY->clear();
        comboY->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
        );
        comboW->clear();
        comboW->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
        );
        comboZ->clear();
        comboZ->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "R      (                 X                               Y                             W                               Z               )", 0, QApplication::UnicodeUTF8));
        imagen->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
