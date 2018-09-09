/********************************************************************************
** Form generated from reading UI file 'ParameterInserting.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERINSERTING_H
#define UI_PARAMETERINSERTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTextEdit *arg1;
    QTextEdit *arg2;
    QTextEdit *arg3;
    QTextEdit *arg4;
    QTextEdit *arg5;
    QTextEdit *arg6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *helper;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(537, 381);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 330, 351, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        arg1 = new QTextEdit(Dialog);
        arg1->setObjectName(QStringLiteral("arg1"));
        arg1->setGeometry(QRect(210, 30, 311, 31));
        arg2 = new QTextEdit(Dialog);
        arg2->setObjectName(QStringLiteral("arg2"));
        arg2->setGeometry(QRect(210, 80, 311, 31));
        arg3 = new QTextEdit(Dialog);
        arg3->setObjectName(QStringLiteral("arg3"));
        arg3->setGeometry(QRect(210, 130, 311, 31));
        arg4 = new QTextEdit(Dialog);
        arg4->setObjectName(QStringLiteral("arg4"));
        arg4->setGeometry(QRect(210, 180, 311, 31));
        arg5 = new QTextEdit(Dialog);
        arg5->setObjectName(QStringLiteral("arg5"));
        arg5->setGeometry(QRect(210, 230, 311, 31));
        arg6 = new QTextEdit(Dialog);
        arg6->setObjectName(QStringLiteral("arg6"));
        arg6->setEnabled(true);
        arg6->setGeometry(QRect(210, 280, 311, 31));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 201, 20));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 86, 201, 20));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 137, 201, 20));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 186, 201, 20));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 235, 201, 20));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 284, 201, 20));
        helper = new QLabel(Dialog);
        helper->setObjectName(QStringLiteral("helper"));
        helper->setGeometry(QRect(10, 0, 521, 20));
        helper->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Insert the parameters", nullptr));
        okButton->setText(QApplication::translate("Dialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", nullptr));
        label->setText(QApplication::translate("Dialog", "Arg1", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Arg2", nullptr));
        label_3->setText(QApplication::translate("Dialog", "Arg3", nullptr));
        label_4->setText(QApplication::translate("Dialog", "Arg4", nullptr));
        label_5->setText(QApplication::translate("Dialog", "Arg5", nullptr));
        label_6->setText(QApplication::translate("Dialog", "Arg6", nullptr));
        helper->setText(QApplication::translate("Dialog", "Arg1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERINSERTING_H
