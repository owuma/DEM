/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot_widget;
    QPushButton *load_pb;
    QPushButton *buildProfile_pb;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1055, 667);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        customPlot_widget = new QCustomPlot(Widget);
        customPlot_widget->setObjectName("customPlot_widget");

        verticalLayout_3->addWidget(customPlot_widget);


        verticalLayout_2->addLayout(verticalLayout_3);

        load_pb = new QPushButton(Widget);
        load_pb->setObjectName("load_pb");

        verticalLayout_2->addWidget(load_pb);

        buildProfile_pb = new QPushButton(Widget);
        buildProfile_pb->setObjectName("buildProfile_pb");

        verticalLayout_2->addWidget(buildProfile_pb);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        load_pb->setText(QCoreApplication::translate("Widget", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273 \320\246\320\234\320\240", nullptr));
        buildProfile_pb->setText(QCoreApplication::translate("Widget", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\277\321\200\320\276\321\204\320\270\320\273\321\214 \321\200\320\265\320\273\321\214\320\265\321\204\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
