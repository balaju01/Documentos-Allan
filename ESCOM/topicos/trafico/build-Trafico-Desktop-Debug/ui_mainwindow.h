/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *areaDibujo;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QSpinBox *Propagacion;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QSpinBox *spinBox_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *Dibujar;
    QPushButton *limpia;
    QPushButton *salir;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1366, 117);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        areaDibujo = new QVBoxLayout();
        areaDibujo->setSpacing(6);
        areaDibujo->setObjectName(QStringLiteral("areaDibujo"));

        verticalLayout->addLayout(areaDibujo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        Propagacion = new QSpinBox(centralWidget);
        Propagacion->setObjectName(QStringLiteral("Propagacion"));
        Propagacion->setMinimum(2);
        Propagacion->setMaximum(100);
        Propagacion->setSingleStep(5);

        horizontalLayout->addWidget(Propagacion);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(1000);
        spinBox->setSingleStep(1);

        horizontalLayout->addWidget(spinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(100);

        horizontalLayout->addWidget(spinBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        spinBox_3 = new QSpinBox(centralWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(2700);
        spinBox_3->setSingleStep(27);

        horizontalLayout->addWidget(spinBox_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Dibujar = new QPushButton(centralWidget);
        Dibujar->setObjectName(QStringLiteral("Dibujar"));

        horizontalLayout->addWidget(Dibujar);

        limpia = new QPushButton(centralWidget);
        limpia->setObjectName(QStringLiteral("limpia"));

        horizontalLayout->addWidget(limpia);

        salir = new QPushButton(centralWidget);
        salir->setObjectName(QStringLiteral("salir"));

        horizontalLayout->addWidget(salir);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1366, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(salir, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Propagacion", 0));
        label_2->setText(QApplication::translate("MainWindow", "Velocidad", 0));
        label_3->setText(QApplication::translate("MainWindow", "Probabilidad", 0));
        label_4->setText(QApplication::translate("MainWindow", "Vmax", 0));
        Dibujar->setText(QApplication::translate("MainWindow", "&Pintar", 0));
        limpia->setText(QApplication::translate("MainWindow", "&Limpiar", 0));
        salir->setText(QApplication::translate("MainWindow", "&Cerrar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
