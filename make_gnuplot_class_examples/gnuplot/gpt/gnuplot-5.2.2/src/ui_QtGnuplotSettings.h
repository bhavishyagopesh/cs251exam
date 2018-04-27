/********************************************************************************
** Form generated from reading UI file 'QtGnuplotSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGNUPLOTSETTINGS_H
#define UI_QTGNUPLOTSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_settingsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *backgroundButton;
    QSpacerItem *horizontalSpacer;
    QLabel *sampleColorLabel;
    QCheckBox *antialiasCheckBox;
    QCheckBox *replotOnResizeCheckBox;
    QCheckBox *roundedCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *mouseLabelComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *settingsDialog)
    {
        if (settingsDialog->objectName().isEmpty())
            settingsDialog->setObjectName(QStringLiteral("settingsDialog"));
        settingsDialog->resize(269, 186);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/settings"), QSize(), QIcon::Normal, QIcon::Off);
        settingsDialog->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(settingsDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        backgroundButton = new QPushButton(settingsDialog);
        backgroundButton->setObjectName(QStringLiteral("backgroundButton"));

        horizontalLayout->addWidget(backgroundButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sampleColorLabel = new QLabel(settingsDialog);
        sampleColorLabel->setObjectName(QStringLiteral("sampleColorLabel"));

        horizontalLayout->addWidget(sampleColorLabel);


        verticalLayout->addLayout(horizontalLayout);

        antialiasCheckBox = new QCheckBox(settingsDialog);
        antialiasCheckBox->setObjectName(QStringLiteral("antialiasCheckBox"));

        verticalLayout->addWidget(antialiasCheckBox);

        replotOnResizeCheckBox = new QCheckBox(settingsDialog);
        replotOnResizeCheckBox->setObjectName(QStringLiteral("replotOnResizeCheckBox"));

        verticalLayout->addWidget(replotOnResizeCheckBox);

        roundedCheckBox = new QCheckBox(settingsDialog);
        roundedCheckBox->setObjectName(QStringLiteral("roundedCheckBox"));

        verticalLayout->addWidget(roundedCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(settingsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        mouseLabelComboBox = new QComboBox(settingsDialog);
        mouseLabelComboBox->addItem(QString());
        mouseLabelComboBox->addItem(QString());
        mouseLabelComboBox->addItem(QString());
        mouseLabelComboBox->addItem(QString());
        mouseLabelComboBox->setObjectName(QStringLiteral("mouseLabelComboBox"));

        horizontalLayout_2->addWidget(mouseLabelComboBox);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(settingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(settingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), settingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), settingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(settingsDialog);
    } // setupUi

    void retranslateUi(QDialog *settingsDialog)
    {
        settingsDialog->setWindowTitle(QApplication::translate("settingsDialog", "Terminal configuration", nullptr));
        backgroundButton->setText(QApplication::translate("settingsDialog", "Select background color", nullptr));
        sampleColorLabel->setText(QApplication::translate("settingsDialog", "Sample", nullptr));
        antialiasCheckBox->setText(QApplication::translate("settingsDialog", "Antialias", nullptr));
        replotOnResizeCheckBox->setText(QApplication::translate("settingsDialog", "Replot on resize", nullptr));
        roundedCheckBox->setText(QApplication::translate("settingsDialog", "Rounded line ends", nullptr));
        label->setText(QApplication::translate("settingsDialog", "Mouse label", nullptr));
        mouseLabelComboBox->setItemText(0, QApplication::translate("settingsDialog", "Status bar", nullptr));
        mouseLabelComboBox->setItemText(1, QApplication::translate("settingsDialog", "Tool bar", nullptr));
        mouseLabelComboBox->setItemText(2, QApplication::translate("settingsDialog", "Above plot", nullptr));
        mouseLabelComboBox->setItemText(3, QApplication::translate("settingsDialog", "None", nullptr));

    } // retranslateUi

};

namespace Ui {
    class settingsDialog: public Ui_settingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGNUPLOTSETTINGS_H
