/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *OpenBtn;
    QPushButton *PlayBtn;
    QLabel *labelIntroduction;
    QGraphicsView *GraphicsView;
    QLabel *imageLabel;
    QPushButton *StopBtn;
    QPushButton *DrawBtn;
    QPushButton *ExitBtn;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(990, 694);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        OpenBtn = new QPushButton(centralWidget);
        OpenBtn->setObjectName(QString::fromUtf8("OpenBtn"));
        OpenBtn->setGeometry(QRect(840, 290, 91, 41));
        PlayBtn = new QPushButton(centralWidget);
        PlayBtn->setObjectName(QString::fromUtf8("PlayBtn"));
        PlayBtn->setGeometry(QRect(840, 340, 91, 41));
        labelIntroduction = new QLabel(centralWidget);
        labelIntroduction->setObjectName(QString::fromUtf8("labelIntroduction"));
        labelIntroduction->setGeometry(QRect(820, 160, 151, 121));
        GraphicsView = new QGraphicsView(centralWidget);
        GraphicsView->setObjectName(QString::fromUtf8("GraphicsView"));
        GraphicsView->setGeometry(QRect(0, 20, 811, 551));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(820, 20, 151, 121));
        imageLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        imageLabel->setWordWrap(false);
        StopBtn = new QPushButton(centralWidget);
        StopBtn->setObjectName(QString::fromUtf8("StopBtn"));
        StopBtn->setGeometry(QRect(840, 440, 91, 41));
        DrawBtn = new QPushButton(centralWidget);
        DrawBtn->setObjectName(QString::fromUtf8("DrawBtn"));
        DrawBtn->setGeometry(QRect(840, 390, 91, 41));
        ExitBtn = new QPushButton(centralWidget);
        ExitBtn->setObjectName(QString::fromUtf8("ExitBtn"));
        ExitBtn->setGeometry(QRect(840, 490, 91, 41));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(820, 150, 151, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(960, 160, 20, 121));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(810, 160, 20, 121));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(820, 270, 151, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(960, 20, 20, 121));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(820, 10, 151, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(820, 130, 151, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(810, 20, 20, 121));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 990, 25));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        OpenBtn->setText(QApplication::translate("MainWindowClass", "Choose", 0, QApplication::UnicodeUTF8));
        PlayBtn->setText(QApplication::translate("MainWindowClass", "Play", 0, QApplication::UnicodeUTF8));
        labelIntroduction->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\345\224\220\351\233\250\346\223\215\345\210\266\344\275\234</span></p><p align=\"center\"><a href=\"https://github.com/812015941\"><span style=\" font-size:10pt; font-weight:600; text-decoration: underline; color:#0000ff;\">https://github.com</span></a></p><p align=\"center\"><a href=\"https://github.com/812015941\"><span style=\" font-size:10pt; font-weight:600; text-decoration: underline; color:#0000ff;\">/812015941</span></a></p><p align=\"center\"><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        StopBtn->setText(QApplication::translate("MainWindowClass", "Stop", 0, QApplication::UnicodeUTF8));
        DrawBtn->setText(QApplication::translate("MainWindowClass", "DrawLine", 0, QApplication::UnicodeUTF8));
        ExitBtn->setText(QApplication::translate("MainWindowClass", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
