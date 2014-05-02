#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *modeMenu;
    QPushButton *play;
    QPushButton *changeSequence;
    QPushButton *changeWords;
    QPushButton *clearTraining;
    QPushButton *prefs;
    QLabel *helpBar;
    QHBoxLayout *horizontalLayout_5;
    QLabel *letter;
    QLabel *WPM;
    QHBoxLayout *forModes;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QPushButton *homeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 300);
        MainWindow->setMinimumSize(QSize(0, 300));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 781, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        modeMenu = new QPushButton(verticalLayoutWidget);
        modeMenu->setObjectName(QString::fromUtf8("modeMenu"));

        horizontalLayout->addWidget(modeMenu);

        play = new QPushButton(verticalLayoutWidget);
        play->setObjectName(QString::fromUtf8("play"));

        horizontalLayout->addWidget(play);

        changeSequence = new QPushButton(verticalLayoutWidget);
        changeSequence->setObjectName(QString::fromUtf8("changeSequence"));

        horizontalLayout->addWidget(changeSequence);

        changeWords = new QPushButton(verticalLayoutWidget);
        changeWords->setObjectName(QString::fromUtf8("changeWords"));

        horizontalLayout->addWidget(changeWords);

        clearTraining = new QPushButton(verticalLayoutWidget);
        clearTraining->setObjectName(QString::fromUtf8("clearTraining"));

        horizontalLayout->addWidget(clearTraining);

        prefs = new QPushButton(verticalLayoutWidget);
        prefs->setObjectName(QString::fromUtf8("prefs"));

        horizontalLayout->addWidget(prefs);


        verticalLayout->addLayout(horizontalLayout);

        helpBar = new QLabel(verticalLayoutWidget);
        helpBar->setObjectName(QString::fromUtf8("helpBar"));
        QFont font;
        font.setPointSize(14);
        font.setItalic(false);
        helpBar->setFont(font);
        helpBar->setWordWrap(true);

        verticalLayout->addWidget(helpBar);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));     letter = new QLabel(verticalLayoutWidget);
        letter->setObjectName(QString::fromUtf8("letter"));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        letter->setFont(font1);

        horizontalLayout_5->addWidget(letter);

        WPM = new QLabel(verticalLayoutWidget);
        WPM->setObjectName(QString::fromUtf8("WPM"));
        WPM->setFont(font1);

        horizontalLayout_5->addWidget(WPM);


        verticalLayout->addLayout(horizontalLayout_5);

        forModes = new QHBoxLayout();
        forModes->setSpacing(6);
        forModes->setObjectName(QString::fromUtf8("forModes"));
        forModes->setSizeConstraint(QLayout::SetNoConstraint);

        verticalLayout->addLayout(forModes);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(200, 0));

        horizontalLayout_6->addWidget(label_2);

        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Cute CW"));
        modeMenu->setText(QApplication::translate("MainWindow", "Mode"));
        play->setText(QApplication::translate("MainWindow", "Play"));
        changeSequence->setText(QApplication::translate("MainWindow", "Sequence"));
        changeWords->setText(QApplication::translate("MainWindow", "Change Words"));
        clearTraining->setText(QApplication::translate("MainWindow", "Clear Training"));
        prefs->setText(QApplication::translate("MainWindow", "Preferences"));
        helpBar->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Average WPM:"));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
