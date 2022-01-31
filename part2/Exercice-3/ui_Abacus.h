/********************************************************************************
** Form generated from reading UI file 'Abacus.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABACUS_H
#define UI_ABACUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mylabel.h"
#include "mynumber.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    mylabel *label_7;
    QSpacerItem *horizontalSpacer;
    mylabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    mylabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    mylabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    mylabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    mylabel *label_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    mynumber *lcdNumber;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 53, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new mylabel(Form);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);
        label_7->setMinimumSize(QSize(100, 20));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new mylabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new mylabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 20));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new mylabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 20));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_5 = new mylabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(100, 20));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_6 = new mylabel(Form);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(100, 20));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_6);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 53, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        lcdNumber = new mynumber(Form);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(150, 100));
        lcdNumber->setDigitCount(2);
        lcdNumber->setMode(QLCDNumber::Dec);

        horizontalLayout_3->addWidget(lcdNumber);

        horizontalSpacer_5 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);


        retranslateUi(Form);
        QObject::connect(label_6, SIGNAL(increaseNext()), label_5, SLOT(increase()));
        QObject::connect(label_5, SIGNAL(increaseNext()), label_4, SLOT(increase()));
        QObject::connect(label_4, SIGNAL(increaseNext()), label_3, SLOT(increase()));
        QObject::connect(label_3, SIGNAL(increaseNext()), label_2, SLOT(increase()));
        QObject::connect(label_2, SIGNAL(increaseNext()), label_7, SLOT(increase()));
        QObject::connect(label_5, SIGNAL(sendValue(int)), lcdNumber, SLOT(getResult(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lcdNumber, SLOT(resetResult()));
        QObject::connect(label_7, SIGNAL(sendValue(int)), lcdNumber, SLOT(getResult(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_6, SLOT(labelToZero()));
        QObject::connect(pushButton, SIGNAL(clicked()), lcdNumber, SLOT(newResult()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_2, SLOT(labelToZero()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_7, SLOT(labelToZero()));
        QObject::connect(pushButton, SIGNAL(clicked()), label_6, SLOT(increase()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_4, SLOT(labelToZero()));
        QObject::connect(label_2, SIGNAL(sendValue(int)), lcdNumber, SLOT(getResult(int)));
        QObject::connect(label_4, SIGNAL(sendValue(int)), lcdNumber, SLOT(getResult(int)));
        QObject::connect(label_3, SIGNAL(sendValue(int)), lcdNumber, SLOT(getResult(int)));
        QObject::connect(label_6, SIGNAL(sendValue(int)), lcdNumber, SLOT(getResult(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_3, SLOT(labelToZero()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label_5, SLOT(labelToZero()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        label_7->setText(QApplication::translate("Form", "0", nullptr));
        label_2->setText(QApplication::translate("Form", "0", nullptr));
        label_3->setText(QApplication::translate("Form", "0", nullptr));
        label_4->setText(QApplication::translate("Form", "0", nullptr));
        label_5->setText(QApplication::translate("Form", "0", nullptr));
        label_6->setText(QApplication::translate("Form", "0", nullptr));
        pushButton->setText(QApplication::translate("Form", "&Increase", nullptr));
        pushButton_2->setText(QApplication::translate("Form", "&Restart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABACUS_H
