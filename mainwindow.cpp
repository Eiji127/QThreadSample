#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QDebug>
#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    configureGraphicView();
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configureGraphicView() {

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(300, 300);
    ui->graphicsView->setSceneRect(0, 0, 300, 300);
    ui->graphicsView->rotate(270);

//    ui->aLineEdit->setPlaceholderText("2.0");
     ui->aLineEdit->text()="2.0";

//    QGraphicsTextItem * text = scene->addText("Hello world");

    QPen * dashedLine {new QPen(QBrush(Qt::gray), 1, Qt::DotLine)};

    int x = 0;
    for (int n = 0; n < 10; n++) {
        QGraphicsLineItem *xAxis {scene->addLine(0, x, 600, x, *dashedLine)};
        QGraphicsLineItem *yAxis {scene->addLine(x, 0, x, 600, *dashedLine)};
        x+= 30;
    }
}

int calculate(int a, int b, int x)  {
//    qDebug() << "DEBUG: calculate coordinate...";
    int y = a*x + b;
//    qDebug() << y;
    return y;
}

//void MainWindow::plotCoordinate(int a, int b) {
//    scene->addEllipse(a, b, 5, 5, QPen(Qt::blue), QBrush(Qt::blue));
//    for (int t = 0; t<200; t++) {
////        qDebug() << "DEBUG: plot " << t << " coordinate...";
//        int y = calculate(a, b, t);
////        qDebug() << y;
//        scene->addEllipse(t, y, 5, 5, QPen(Qt::red), QBrush(Qt::red));
////        scene.update();
//    }
//    qDebug() << scene;
//}

void MainWindow::plotCoordinate(double a, double b, double t) {

    double y = calculate(a, b, t);
    scene->addEllipse(t, y, 5, 5, QPen(Qt::red), QBrush(Qt::red));
    qDebug() << scene;

}


void MainWindow::on_startPlotButton_clicked()
{
//    qDebug() << "DEBUG: pushed start button...";
    ui->startPlotButton->setVisible(false);
    double a = ui->aLineEdit->text().toDouble();
    double b = ui->bLineEdit->text().toDouble();
    double loopCount = 0;
    maxLoopCount = 150;
    while (loopCount<maxLoopCount) {
        QCoreApplication::processEvents();
        plotCoordinate(a, b, loopCount);
        loopCount+=0.03;
    }
    ui->startPlotButton->setVisible(true);
}


void MainWindow::on_pushButton_4_clicked()
{
    scene->clear();
//    QGraphicsScene * newScene = new QGraphicsScene();
    QPen * dashedLine {new QPen(QBrush(Qt::gray), 1, Qt::DotLine)};
    int x = 0;
    for (int n = 0; n < 10; n++) {
        QGraphicsLineItem *xAxis {scene->addLine(0, x, 600, x, *dashedLine)};
        QGraphicsLineItem *yAxis {scene->addLine(x, 0, x, 600, *dashedLine)};
//        QGraphicsLineItem *line {scene->addLine(0, 0, 400, 300, *graphLine)};
        x+=30;
        //        QGraphicsPixmapItem *pointer {scene->addPixmap(QPixmap(50, 50))};
        //        scene->update();
    }
//    scene = newScene;
}


void MainWindow::on_stopPlotButton_clicked()
{
    maxLoopCount = 101;
}

