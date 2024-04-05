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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QRadioButton *life;
    QRadioButton *diffussion;
    QRadioButton *personal;
    QGroupBox *groupBox_4;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *difucion;
    QPushButton *inicio;
    QPushButton *limpiar;
    QPushButton *arboles;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(612, 431);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(-20, 10, 581, 31));
        life = new QRadioButton(groupBox_3);
        life->setObjectName(QStringLiteral("life"));
        life->setGeometry(QRect(30, 0, 102, 22));
        diffussion = new QRadioButton(groupBox_3);
        diffussion->setObjectName(QStringLiteral("diffussion"));
        diffussion->setGeometry(QRect(150, 0, 121, 22));
        personal = new QRadioButton(groupBox_3);
        personal->setObjectName(QStringLiteral("personal"));
        personal->setGeometry(QRect(300, 0, 111, 22));

        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        doubleSpinBox = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(10, 10, 63, 27));
        doubleSpinBox->setMaximum(100);
        doubleSpinBox->setSingleStep(0.01);
        difucion = new QPushButton(groupBox_4);
        difucion->setObjectName(QStringLiteral("difucion"));
        difucion->setGeometry(QRect(80, 10, 85, 27));
        inicio = new QPushButton(groupBox_4);
        inicio->setObjectName(QStringLiteral("inicio"));
        inicio->setGeometry(QRect(180, 10, 85, 27));
        limpiar = new QPushButton(groupBox_4);
        limpiar->setObjectName(QStringLiteral("limpiar"));
        limpiar->setGeometry(QRect(280, 10, 85, 27));
        arboles = new QPushButton(groupBox_4);
        arboles->setObjectName(QStringLiteral("arboles"));
        arboles->setGeometry(QRect(380, 10, 85, 27));

        gridLayout->addWidget(groupBox_4, 1, 0, 1, 3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 612, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QString());
        groupBox_3->setTitle(QString());
        life->setText(QApplication::translate("MainWindow", "Game of Life", 0));
        diffussion->setText(QApplication::translate("MainWindow", "Diffussion Rule", 0));
        personal->setText(QApplication::translate("MainWindow", "Personalisada", 0));
        groupBox_4->setTitle(QString());
        difucion->setText(QApplication::translate("MainWindow", "Dispercion", 0));
        inicio->setText(QApplication::translate("MainWindow", "Inicio", 0));
        limpiar->setText(QApplication::translate("MainWindow", "Limpiar", 0));
        arboles->setText(QApplication::translate("MainWindow", "Arboles", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
