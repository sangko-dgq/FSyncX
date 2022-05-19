/********************************************************************************
** Form generated from reading UI file 'SettingWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QGroupBox *groupBox;
    QComboBox *CBox_SwitchTheme;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QString::fromUtf8("SettingWindow"));
        SettingWindow->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code"));
        font.setBold(false);
        font.setWeight(50);
        SettingWindow->setFont(font);
        SettingWindow->setWindowOpacity(0.940000000000000);
        groupBox = new QGroupBox(SettingWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 381, 241));
        CBox_SwitchTheme = new QComboBox(groupBox);
        CBox_SwitchTheme->addItem(QString());
        CBox_SwitchTheme->addItem(QString());
        CBox_SwitchTheme->addItem(QString());
        CBox_SwitchTheme->addItem(QString());
        CBox_SwitchTheme->setObjectName(QString::fromUtf8("CBox_SwitchTheme"));
        CBox_SwitchTheme->setGeometry(QRect(50, 70, 279, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 279, 16));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 160, 281, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 110, 281, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pushButton_5 = new QPushButton(layoutWidget1);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);

        layoutWidget2 = new QWidget(SettingWindow);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(150, 260, 239, 31));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);


        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingWindow)
    {
        SettingWindow->setWindowTitle(QCoreApplication::translate("SettingWindow", "Form", nullptr));
        groupBox->setTitle(QString());
        CBox_SwitchTheme->setItemText(0, QCoreApplication::translate("SettingWindow", "Default", nullptr));
        CBox_SwitchTheme->setItemText(1, QCoreApplication::translate("SettingWindow", "MacOS", nullptr));
        CBox_SwitchTheme->setItemText(2, QCoreApplication::translate("SettingWindow", "Aqua", nullptr));
        CBox_SwitchTheme->setItemText(3, QCoreApplication::translate("SettingWindow", "ConsoleStyle", nullptr));

        label->setText(QCoreApplication::translate("SettingWindow", "Theme", nullptr));
        label_3->setText(QCoreApplication::translate("SettingWindow", "Check Update", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SettingWindow", "CHECK UPDATE", nullptr));
        label_2->setText(QCoreApplication::translate("SettingWindow", "Open Config File", nullptr));
        pushButton_5->setText(QCoreApplication::translate("SettingWindow", "Config.ini", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SettingWindow", "Reset", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SettingWindow", "Cancel", nullptr));
        pushButton->setText(QCoreApplication::translate("SettingWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
