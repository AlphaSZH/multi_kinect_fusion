/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *camera1;
    QLineEdit *camera2;
    QLineEdit *camera3;
    QVBoxLayout *verticalLayout;
    QPushButton *c1btn;
    QPushButton *c2btn;
    QPushButton *c3btn;
    QGroupBox *groupBox_2;
    QPlainTextEdit *log;
    QGroupBox *groupBox_3;
    GLwidget *camera1gl;
    GLwidget *camera2gl;
    GLwidget *camera3gl;
    GLwidget *camera4gl;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *fusion_btn;
    QPushButton *pausebtn;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1161, 850);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 50, 421, 118));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        groupBox->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font1);

        verticalLayout_2->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        camera1 = new QLineEdit(groupBox);
        camera1->setObjectName(QStringLiteral("camera1"));

        verticalLayout_3->addWidget(camera1);

        camera2 = new QLineEdit(groupBox);
        camera2->setObjectName(QStringLiteral("camera2"));

        verticalLayout_3->addWidget(camera2);

        camera3 = new QLineEdit(groupBox);
        camera3->setObjectName(QStringLiteral("camera3"));

        verticalLayout_3->addWidget(camera3);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        c1btn = new QPushButton(groupBox);
        c1btn->setObjectName(QStringLiteral("c1btn"));

        verticalLayout->addWidget(c1btn);

        c2btn = new QPushButton(groupBox);
        c2btn->setObjectName(QStringLiteral("c2btn"));

        verticalLayout->addWidget(c2btn);

        c3btn = new QPushButton(groupBox);
        c3btn->setObjectName(QStringLiteral("c3btn"));

        verticalLayout->addWidget(c3btn);


        horizontalLayout_2->addLayout(verticalLayout);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 270, 421, 251));
        QFont font2;
        font2.setPointSize(11);
        groupBox_2->setFont(font2);
        log = new QPlainTextEdit(groupBox_2);
        log->setObjectName(QStringLiteral("log"));
        log->setGeometry(QRect(20, 20, 381, 221));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(470, 30, 951, 791));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        groupBox_3->setFont(font3);
        camera1gl = new GLwidget(groupBox_3);
        camera1gl->setObjectName(QStringLiteral("camera1gl"));
        camera1gl->setGeometry(QRect(30, 60, 281, 351));
        sizePolicy.setHeightForWidth(camera1gl->sizePolicy().hasHeightForWidth());
        camera1gl->setSizePolicy(sizePolicy);
        camera2gl = new GLwidget(groupBox_3);
        camera2gl->setObjectName(QStringLiteral("camera2gl"));
        camera2gl->setGeometry(QRect(380, 60, 281, 351));
        camera3gl = new GLwidget(groupBox_3);
        camera3gl->setObjectName(QStringLiteral("camera3gl"));
        camera3gl->setGeometry(QRect(30, 450, 281, 351));
        camera4gl = new GLwidget(groupBox_3);
        camera4gl->setObjectName(QStringLiteral("camera4gl"));
        camera4gl->setGeometry(QRect(380, 450, 281, 351));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(660, 10, 111, 16));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 640, 401, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        fusion_btn = new QPushButton(gridLayoutWidget);
        fusion_btn->setObjectName(QStringLiteral("fusion_btn"));

        gridLayout->addWidget(fusion_btn, 0, 1, 1, 1);

        pausebtn = new QPushButton(gridLayoutWidget);
        pausebtn->setObjectName(QStringLiteral("pausebtn"));

        gridLayout->addWidget(pausebtn, 0, 3, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 4, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1161, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);
        QObject::connect(fusion_btn, SIGNAL(clicked()), MainWindow, SLOT(fusion()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(onLoadBtn()));
        QObject::connect(pausebtn, SIGNAL(clicked()), MainWindow, SLOT(onClickedPauseBtn()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(reset()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Kinect Stream Server", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Camera 1 location:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Camera 2 location:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Camera 3 location:", Q_NULLPTR));
        c1btn->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        c2btn->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        c3btn->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Log", Q_NULLPTR));
        log->setPlainText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Result", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "load", Q_NULLPTR));
        fusion_btn->setText(QApplication::translate("MainWindow", "fusion", Q_NULLPTR));
        pausebtn->setText(QApplication::translate("MainWindow", "pause", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "reset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
