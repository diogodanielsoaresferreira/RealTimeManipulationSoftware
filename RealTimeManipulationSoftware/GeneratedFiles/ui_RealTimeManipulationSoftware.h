/********************************************************************************
** Form generated from reading UI file 'RealTimeManipulationSoftware.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMEMANIPULATIONSOFTWARE_H
#define UI_REALTIMEMANIPULATIONSOFTWARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RealTimeManipulationSoftwareClass
{
public:
    QAction *actionChange_Brightness;
    QAction *actionChange_Contrast;
    QAction *actionRed_Image;
    QAction *actionGreen_Image;
    QAction *actionBlue_Image;
    QAction *actionDraw_Grid;
    QAction *actionConvert_to_Color;
    QAction *actionChange_Color_Space;
    QAction *actionInvert_Image;
    QAction *actionCreate_Segmentation;
    QAction *actionBackground_subtraction_using_KNN;
    QAction *actionBackground_subtraction_using_MOG2;
    QAction *actionMean_Blur;
    QAction *actionMedian_Blur;
    QAction *actionGaussian_Blur;
    QAction *actionContrast_Streching;
    QAction *actionEqualize_histogram;
    QAction *actionBrightness_and_Contrast_Auto;
    QAction *actionBack_Projection;
    QAction *actionErode;
    QAction *actionDilate;
    QAction *actionOpening;
    QAction *actionClosing;
    QAction *actionMorphological_Gradient;
    QAction *actionTop_Hat;
    QAction *actionBlack_Hat;
    QAction *actionThreshold_Binary;
    QAction *actionThreshold_Binary_Inverted;
    QAction *actionTruncate;
    QAction *actionThreshold_to_Zero;
    QAction *actionThreshold_to_Zero_Inverted;
    QAction *actionSobel_Operator;
    QAction *actionCanny_Detector;
    QAction *actionDetect_edges_with_Dilate;
    QAction *actionLaplace_Operator;
    QAction *actionFind_and_Draw_Contours;
    QAction *actionHarris_Corner_Detection;
    QAction *actionShi_Tomasi_Corner_Detection;
    QWidget *centralWidget;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *loadVideoButton;
    QPushButton *stopVideoButton;
    QPushButton *saveVideo;
    QListWidget *transformationList;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QMenu *menuBasics;
    QMenu *menuSegmentation;
    QMenu *menuVideo_operations;
    QMenu *menuSmoothing_images;
    QMenu *menuAutomatic_operations;
    QMenu *menuMorphologic_Transformations;
    QMenu *menuThresholding_operations;
    QMenu *menuEdge_detectors;
    QMenu *menuCorner_detection;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RealTimeManipulationSoftwareClass)
    {
        if (RealTimeManipulationSoftwareClass->objectName().isEmpty())
            RealTimeManipulationSoftwareClass->setObjectName(QStringLiteral("RealTimeManipulationSoftwareClass"));
        RealTimeManipulationSoftwareClass->resize(1401, 848);
        RealTimeManipulationSoftwareClass->setMinimumSize(QSize(0, 0));
        RealTimeManipulationSoftwareClass->setTabShape(QTabWidget::Rounded);
        actionChange_Brightness = new QAction(RealTimeManipulationSoftwareClass);
        actionChange_Brightness->setObjectName(QStringLiteral("actionChange_Brightness"));
        actionChange_Contrast = new QAction(RealTimeManipulationSoftwareClass);
        actionChange_Contrast->setObjectName(QStringLiteral("actionChange_Contrast"));
        actionChange_Contrast->setCheckable(false);
        actionRed_Image = new QAction(RealTimeManipulationSoftwareClass);
        actionRed_Image->setObjectName(QStringLiteral("actionRed_Image"));
        actionRed_Image->setCheckable(false);
        actionGreen_Image = new QAction(RealTimeManipulationSoftwareClass);
        actionGreen_Image->setObjectName(QStringLiteral("actionGreen_Image"));
        actionGreen_Image->setCheckable(false);
        actionBlue_Image = new QAction(RealTimeManipulationSoftwareClass);
        actionBlue_Image->setObjectName(QStringLiteral("actionBlue_Image"));
        actionBlue_Image->setCheckable(false);
        actionDraw_Grid = new QAction(RealTimeManipulationSoftwareClass);
        actionDraw_Grid->setObjectName(QStringLiteral("actionDraw_Grid"));
        actionDraw_Grid->setCheckable(true);
        actionConvert_to_Color = new QAction(RealTimeManipulationSoftwareClass);
        actionConvert_to_Color->setObjectName(QStringLiteral("actionConvert_to_Color"));
        actionConvert_to_Color->setCheckable(false);
        actionChange_Color_Space = new QAction(RealTimeManipulationSoftwareClass);
        actionChange_Color_Space->setObjectName(QStringLiteral("actionChange_Color_Space"));
        actionChange_Color_Space->setCheckable(false);
        actionInvert_Image = new QAction(RealTimeManipulationSoftwareClass);
        actionInvert_Image->setObjectName(QStringLiteral("actionInvert_Image"));
        actionInvert_Image->setCheckable(false);
        actionCreate_Segmentation = new QAction(RealTimeManipulationSoftwareClass);
        actionCreate_Segmentation->setObjectName(QStringLiteral("actionCreate_Segmentation"));
        actionCreate_Segmentation->setCheckable(false);
        actionBackground_subtraction_using_KNN = new QAction(RealTimeManipulationSoftwareClass);
        actionBackground_subtraction_using_KNN->setObjectName(QStringLiteral("actionBackground_subtraction_using_KNN"));
        actionBackground_subtraction_using_KNN->setCheckable(false);
        actionBackground_subtraction_using_MOG2 = new QAction(RealTimeManipulationSoftwareClass);
        actionBackground_subtraction_using_MOG2->setObjectName(QStringLiteral("actionBackground_subtraction_using_MOG2"));
        actionBackground_subtraction_using_MOG2->setCheckable(false);
        actionMean_Blur = new QAction(RealTimeManipulationSoftwareClass);
        actionMean_Blur->setObjectName(QStringLiteral("actionMean_Blur"));
        actionMean_Blur->setCheckable(false);
        actionMedian_Blur = new QAction(RealTimeManipulationSoftwareClass);
        actionMedian_Blur->setObjectName(QStringLiteral("actionMedian_Blur"));
        actionMedian_Blur->setCheckable(false);
        actionGaussian_Blur = new QAction(RealTimeManipulationSoftwareClass);
        actionGaussian_Blur->setObjectName(QStringLiteral("actionGaussian_Blur"));
        actionGaussian_Blur->setCheckable(false);
        actionContrast_Streching = new QAction(RealTimeManipulationSoftwareClass);
        actionContrast_Streching->setObjectName(QStringLiteral("actionContrast_Streching"));
        actionContrast_Streching->setCheckable(false);
        actionEqualize_histogram = new QAction(RealTimeManipulationSoftwareClass);
        actionEqualize_histogram->setObjectName(QStringLiteral("actionEqualize_histogram"));
        actionEqualize_histogram->setCheckable(false);
        actionBrightness_and_Contrast_Auto = new QAction(RealTimeManipulationSoftwareClass);
        actionBrightness_and_Contrast_Auto->setObjectName(QStringLiteral("actionBrightness_and_Contrast_Auto"));
        actionBrightness_and_Contrast_Auto->setCheckable(false);
        actionBack_Projection = new QAction(RealTimeManipulationSoftwareClass);
        actionBack_Projection->setObjectName(QStringLiteral("actionBack_Projection"));
        actionBack_Projection->setCheckable(false);
        actionErode = new QAction(RealTimeManipulationSoftwareClass);
        actionErode->setObjectName(QStringLiteral("actionErode"));
        actionErode->setCheckable(false);
        actionDilate = new QAction(RealTimeManipulationSoftwareClass);
        actionDilate->setObjectName(QStringLiteral("actionDilate"));
        actionDilate->setCheckable(false);
        actionOpening = new QAction(RealTimeManipulationSoftwareClass);
        actionOpening->setObjectName(QStringLiteral("actionOpening"));
        actionOpening->setCheckable(false);
        actionClosing = new QAction(RealTimeManipulationSoftwareClass);
        actionClosing->setObjectName(QStringLiteral("actionClosing"));
        actionClosing->setCheckable(false);
        actionMorphological_Gradient = new QAction(RealTimeManipulationSoftwareClass);
        actionMorphological_Gradient->setObjectName(QStringLiteral("actionMorphological_Gradient"));
        actionMorphological_Gradient->setCheckable(false);
        actionTop_Hat = new QAction(RealTimeManipulationSoftwareClass);
        actionTop_Hat->setObjectName(QStringLiteral("actionTop_Hat"));
        actionTop_Hat->setCheckable(false);
        actionBlack_Hat = new QAction(RealTimeManipulationSoftwareClass);
        actionBlack_Hat->setObjectName(QStringLiteral("actionBlack_Hat"));
        actionBlack_Hat->setCheckable(false);
        actionThreshold_Binary = new QAction(RealTimeManipulationSoftwareClass);
        actionThreshold_Binary->setObjectName(QStringLiteral("actionThreshold_Binary"));
        actionThreshold_Binary->setCheckable(false);
        actionThreshold_Binary_Inverted = new QAction(RealTimeManipulationSoftwareClass);
        actionThreshold_Binary_Inverted->setObjectName(QStringLiteral("actionThreshold_Binary_Inverted"));
        actionThreshold_Binary_Inverted->setCheckable(false);
        actionTruncate = new QAction(RealTimeManipulationSoftwareClass);
        actionTruncate->setObjectName(QStringLiteral("actionTruncate"));
        actionTruncate->setCheckable(false);
        actionThreshold_to_Zero = new QAction(RealTimeManipulationSoftwareClass);
        actionThreshold_to_Zero->setObjectName(QStringLiteral("actionThreshold_to_Zero"));
        actionThreshold_to_Zero->setCheckable(false);
        actionThreshold_to_Zero_Inverted = new QAction(RealTimeManipulationSoftwareClass);
        actionThreshold_to_Zero_Inverted->setObjectName(QStringLiteral("actionThreshold_to_Zero_Inverted"));
        actionThreshold_to_Zero_Inverted->setCheckable(false);
        actionSobel_Operator = new QAction(RealTimeManipulationSoftwareClass);
        actionSobel_Operator->setObjectName(QStringLiteral("actionSobel_Operator"));
        actionSobel_Operator->setCheckable(false);
        actionCanny_Detector = new QAction(RealTimeManipulationSoftwareClass);
        actionCanny_Detector->setObjectName(QStringLiteral("actionCanny_Detector"));
        actionCanny_Detector->setCheckable(false);
        actionDetect_edges_with_Dilate = new QAction(RealTimeManipulationSoftwareClass);
        actionDetect_edges_with_Dilate->setObjectName(QStringLiteral("actionDetect_edges_with_Dilate"));
        actionDetect_edges_with_Dilate->setCheckable(false);
        actionLaplace_Operator = new QAction(RealTimeManipulationSoftwareClass);
        actionLaplace_Operator->setObjectName(QStringLiteral("actionLaplace_Operator"));
        actionLaplace_Operator->setCheckable(false);
        actionFind_and_Draw_Contours = new QAction(RealTimeManipulationSoftwareClass);
        actionFind_and_Draw_Contours->setObjectName(QStringLiteral("actionFind_and_Draw_Contours"));
        actionFind_and_Draw_Contours->setCheckable(false);
        actionHarris_Corner_Detection = new QAction(RealTimeManipulationSoftwareClass);
        actionHarris_Corner_Detection->setObjectName(QStringLiteral("actionHarris_Corner_Detection"));
        actionHarris_Corner_Detection->setCheckable(false);
        actionShi_Tomasi_Corner_Detection = new QAction(RealTimeManipulationSoftwareClass);
        actionShi_Tomasi_Corner_Detection->setObjectName(QStringLiteral("actionShi_Tomasi_Corner_Detection"));
        actionShi_Tomasi_Corner_Detection->setCheckable(false);
        centralWidget = new QWidget(RealTimeManipulationSoftwareClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(740, 480, 311, 101));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 551, 361));
        label->setStyleSheet(QStringLiteral("Background-color: #000;"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(830, 30, 551, 361));
        label_2->setStyleSheet(QStringLiteral("Background-color: #000;"));
        loadVideoButton = new QPushButton(centralWidget);
        loadVideoButton->setObjectName(QStringLiteral("loadVideoButton"));
        loadVideoButton->setGeometry(QRect(1080, 480, 311, 101));
        stopVideoButton = new QPushButton(centralWidget);
        stopVideoButton->setObjectName(QStringLiteral("stopVideoButton"));
        stopVideoButton->setGeometry(QRect(740, 610, 311, 101));
        saveVideo = new QPushButton(centralWidget);
        saveVideo->setObjectName(QStringLiteral("saveVideo"));
        saveVideo->setGeometry(QRect(1080, 610, 311, 101));
        transformationList = new QListWidget(centralWidget);
        transformationList->setObjectName(QStringLiteral("transformationList"));
        transformationList->setGeometry(QRect(10, 430, 551, 351));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(830, 10, 71, 16));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 71, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 410, 311, 16));
        RealTimeManipulationSoftwareClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RealTimeManipulationSoftwareClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1401, 26));
        menuBasics = new QMenu(menuBar);
        menuBasics->setObjectName(QStringLiteral("menuBasics"));
        menuSegmentation = new QMenu(menuBar);
        menuSegmentation->setObjectName(QStringLiteral("menuSegmentation"));
        menuVideo_operations = new QMenu(menuBar);
        menuVideo_operations->setObjectName(QStringLiteral("menuVideo_operations"));
        menuSmoothing_images = new QMenu(menuBar);
        menuSmoothing_images->setObjectName(QStringLiteral("menuSmoothing_images"));
        menuAutomatic_operations = new QMenu(menuBar);
        menuAutomatic_operations->setObjectName(QStringLiteral("menuAutomatic_operations"));
        menuMorphologic_Transformations = new QMenu(menuBar);
        menuMorphologic_Transformations->setObjectName(QStringLiteral("menuMorphologic_Transformations"));
        menuThresholding_operations = new QMenu(menuBar);
        menuThresholding_operations->setObjectName(QStringLiteral("menuThresholding_operations"));
        menuEdge_detectors = new QMenu(menuBar);
        menuEdge_detectors->setObjectName(QStringLiteral("menuEdge_detectors"));
        menuCorner_detection = new QMenu(menuBar);
        menuCorner_detection->setObjectName(QStringLiteral("menuCorner_detection"));
        RealTimeManipulationSoftwareClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RealTimeManipulationSoftwareClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RealTimeManipulationSoftwareClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RealTimeManipulationSoftwareClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RealTimeManipulationSoftwareClass->setStatusBar(statusBar);

        menuBar->addAction(menuBasics->menuAction());
        menuBar->addAction(menuSegmentation->menuAction());
        menuBar->addAction(menuVideo_operations->menuAction());
        menuBar->addAction(menuSmoothing_images->menuAction());
        menuBar->addAction(menuAutomatic_operations->menuAction());
        menuBar->addAction(menuMorphologic_Transformations->menuAction());
        menuBar->addAction(menuThresholding_operations->menuAction());
        menuBar->addAction(menuEdge_detectors->menuAction());
        menuBar->addAction(menuCorner_detection->menuAction());
        menuBasics->addAction(actionRed_Image);
        menuBasics->addAction(actionGreen_Image);
        menuBasics->addAction(actionBlue_Image);
        menuBasics->addAction(actionChange_Color_Space);
        menuBasics->addAction(actionInvert_Image);
        menuBasics->addAction(actionConvert_to_Color);
        menuBasics->addAction(actionChange_Contrast);
        menuSegmentation->addAction(actionCreate_Segmentation);
        menuVideo_operations->addAction(actionBackground_subtraction_using_KNN);
        menuVideo_operations->addAction(actionBackground_subtraction_using_MOG2);
        menuSmoothing_images->addAction(actionMean_Blur);
        menuSmoothing_images->addAction(actionMedian_Blur);
        menuSmoothing_images->addAction(actionGaussian_Blur);
        menuAutomatic_operations->addAction(actionContrast_Streching);
        menuAutomatic_operations->addAction(actionEqualize_histogram);
        menuAutomatic_operations->addAction(actionBrightness_and_Contrast_Auto);
        menuAutomatic_operations->addAction(actionBack_Projection);
        menuMorphologic_Transformations->addAction(actionErode);
        menuMorphologic_Transformations->addAction(actionDilate);
        menuMorphologic_Transformations->addAction(actionOpening);
        menuMorphologic_Transformations->addAction(actionClosing);
        menuMorphologic_Transformations->addAction(actionMorphological_Gradient);
        menuMorphologic_Transformations->addAction(actionTop_Hat);
        menuMorphologic_Transformations->addAction(actionBlack_Hat);
        menuThresholding_operations->addAction(actionThreshold_Binary);
        menuThresholding_operations->addAction(actionThreshold_Binary_Inverted);
        menuThresholding_operations->addAction(actionTruncate);
        menuThresholding_operations->addAction(actionThreshold_to_Zero);
        menuThresholding_operations->addAction(actionThreshold_to_Zero_Inverted);
        menuEdge_detectors->addAction(actionSobel_Operator);
        menuEdge_detectors->addAction(actionCanny_Detector);
        menuEdge_detectors->addAction(actionDetect_edges_with_Dilate);
        menuEdge_detectors->addAction(actionLaplace_Operator);
        menuEdge_detectors->addAction(actionFind_and_Draw_Contours);
        menuCorner_detection->addAction(actionHarris_Corner_Detection);
        menuCorner_detection->addAction(actionShi_Tomasi_Corner_Detection);

        retranslateUi(RealTimeManipulationSoftwareClass);
        QObject::connect(actionChange_Contrast, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(setBrightnessContrast()));
        QObject::connect(actionGreen_Image, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(setGreenImage()));
        QObject::connect(actionRed_Image, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(setRedImage()));
        QObject::connect(actionBlue_Image, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(setBlueImage()));
        QObject::connect(actionDraw_Grid, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(drawGrid()));
        QObject::connect(actionConvert_to_Color, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_changeColor()));
        QObject::connect(actionChange_Color_Space, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(setColor()));
        QObject::connect(actionInvert_Image, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_invertImage()));
        QObject::connect(loadVideoButton, SIGNAL(clicked()), RealTimeManipulationSoftwareClass, SLOT(action_loadFromFile()));
        QObject::connect(stopVideoButton, SIGNAL(clicked()), RealTimeManipulationSoftwareClass, SLOT(action_stopVideoButton()));
        QObject::connect(saveVideo, SIGNAL(clicked()), RealTimeManipulationSoftwareClass, SLOT(action_saveVideo()));
        QObject::connect(actionCreate_Segmentation, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_createSegmentation()));
        QObject::connect(actionBackground_subtraction_using_KNN, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_backgroundSubtractionKNN()));
        QObject::connect(actionBackground_subtraction_using_MOG2, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_backgroundSubtractionMOG2()));
        QObject::connect(actionMean_Blur, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_meanBlur()));
        QObject::connect(actionMedian_Blur, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_medianBlur()));
        QObject::connect(actionGaussian_Blur, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_gaussianBlur()));
        QObject::connect(actionBack_Projection, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_backProj()));
        QObject::connect(actionEqualize_histogram, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_equalizeHist()));
        QObject::connect(actionContrast_Streching, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_contrastStreching()));
        QObject::connect(actionBrightness_and_Contrast_Auto, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_brightContAuto()));
        QObject::connect(actionErode, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_erode()));
        QObject::connect(actionDilate, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_dilate()));
        QObject::connect(actionOpening, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_opening()));
        QObject::connect(actionClosing, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_closing()));
        QObject::connect(actionMorphological_Gradient, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_morphologicalGradient()));
        QObject::connect(actionBlack_Hat, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_blackHat()));
        QObject::connect(actionTop_Hat, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_topHat()));
        QObject::connect(actionThreshold_Binary, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_thresBinary()));
        QObject::connect(actionThreshold_Binary_Inverted, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_thresBinaryInv()));
        QObject::connect(actionTruncate, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_truncate()));
        QObject::connect(actionThreshold_to_Zero, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_thresZero()));
        QObject::connect(actionThreshold_to_Zero_Inverted, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_thresZeroInv()));
        QObject::connect(actionCanny_Detector, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_cannyOperator()));
        QObject::connect(actionSobel_Operator, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_sobelOperator()));
        QObject::connect(actionDetect_edges_with_Dilate, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_detectEdgesDilate()));
        QObject::connect(actionFind_and_Draw_Contours, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_drawContours()));
        QObject::connect(actionLaplace_Operator, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_laplaceOperator()));
        QObject::connect(actionHarris_Corner_Detection, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_harrisCornerDetection()));
        QObject::connect(actionShi_Tomasi_Corner_Detection, SIGNAL(triggered()), RealTimeManipulationSoftwareClass, SLOT(action_shiTomasiCornerDetection()));
        QObject::connect(transformationList, SIGNAL(itemClicked(QListWidgetItem*)), RealTimeManipulationSoftwareClass, SLOT(action_transformationClicked(QListWidgetItem*)));

        QMetaObject::connectSlotsByName(RealTimeManipulationSoftwareClass);
    } // setupUi

    void retranslateUi(QMainWindow *RealTimeManipulationSoftwareClass)
    {
        RealTimeManipulationSoftwareClass->setWindowTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "RealTimeManipulationSoftware", nullptr));
        actionChange_Brightness->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Change Brightness", nullptr));
        actionChange_Contrast->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Change Brightness and Contrast", nullptr));
        actionRed_Image->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Red Image", nullptr));
        actionGreen_Image->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Green Image", nullptr));
        actionBlue_Image->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Blue Image", nullptr));
        actionDraw_Grid->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Draw Grid", nullptr));
        actionConvert_to_Color->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Change Color...", nullptr));
        actionChange_Color_Space->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Grey Image", nullptr));
        actionInvert_Image->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Invert Image", nullptr));
        actionCreate_Segmentation->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Create Segmentation", nullptr));
        actionBackground_subtraction_using_KNN->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Background subtraction using KNN", nullptr));
        actionBackground_subtraction_using_MOG2->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Backgorund subtraction using MOG2", nullptr));
        actionMean_Blur->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Mean Blur", nullptr));
        actionMedian_Blur->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Median Blur", nullptr));
        actionGaussian_Blur->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Gaussian Blur", nullptr));
        actionContrast_Streching->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Contrast Streching", nullptr));
        actionEqualize_histogram->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Equalize histogram", nullptr));
        actionBrightness_and_Contrast_Auto->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Brightness and Contrast Auto", nullptr));
        actionBack_Projection->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Back Projection", nullptr));
        actionErode->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Erode", nullptr));
        actionDilate->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Dilate", nullptr));
        actionOpening->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Opening", nullptr));
        actionClosing->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Closing", nullptr));
        actionMorphological_Gradient->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Morphological Gradient", nullptr));
        actionTop_Hat->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Top Hat", nullptr));
        actionBlack_Hat->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Black Hat", nullptr));
        actionThreshold_Binary->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Threshold Binary", nullptr));
        actionThreshold_Binary_Inverted->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Threshold Binary Inverted", nullptr));
        actionTruncate->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Truncate", nullptr));
        actionThreshold_to_Zero->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Threshold to Zero", nullptr));
        actionThreshold_to_Zero_Inverted->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Threshold to Zero Inverted", nullptr));
        actionSobel_Operator->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Sobel Operator", nullptr));
        actionCanny_Detector->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Canny Detector", nullptr));
        actionDetect_edges_with_Dilate->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Detect edges with Dilate", nullptr));
        actionLaplace_Operator->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Laplace Operator", nullptr));
        actionFind_and_Draw_Contours->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Find and Draw Contours", nullptr));
        actionHarris_Corner_Detection->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Harris Corner Detection", nullptr));
        actionShi_Tomasi_Corner_Detection->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Shi-Tomasi Corner Detection", nullptr));
        pushButton_2->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Start capture", nullptr));
        label->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "TextLabel", nullptr));
        loadVideoButton->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Load video from file", nullptr));
        stopVideoButton->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Stop video", nullptr));
        saveVideo->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Save video", nullptr));
        label_3->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Manipulated", nullptr));
        label_4->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Original", nullptr));
        label_5->setText(QApplication::translate("RealTimeManipulationSoftwareClass", "Effects applied in order (click on the effect to delete)", nullptr));
        menuBasics->setTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "Basics", nullptr));
        menuSegmentation->setTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "Segmentation", nullptr));
        menuVideo_operations->setTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "Video operations", nullptr));
        menuSmoothing_images->setTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "Smoothing", nullptr));
        menuAutomatic_operations->setTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "Automatic operations", nullptr));
        menuMorphologic_Transformations->setTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "Morphologic Transformations", nullptr));
        menuThresholding_operations->setTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "Thresholding operations", nullptr));
        menuEdge_detectors->setTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "Edge detectors", nullptr));
        menuCorner_detection->setTitle(QApplication::translate("RealTimeManipulationSoftwareClass", "Corner detection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RealTimeManipulationSoftwareClass: public Ui_RealTimeManipulationSoftwareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMEMANIPULATIONSOFTWARE_H
