#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QDebug>


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
//    QGraphicsScene * scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(300, 300);
    ui->graphicsView->setSceneRect(0, 0, 300, 300);
    ui->graphicsView->rotate(270);

//    QGraphicsTextItem * text = scene->addText("Hello world");

    QPen * dashedLine {new QPen(QBrush(Qt::gray), 1, Qt::DotLine)};
    QPen * graphLine {new QPen(QBrush(Qt::red), 1, Qt::SolidLine)};

    int x = 0;
    for (int n = 0; n < 10; n++) {
        QGraphicsLineItem *xAxis {scene->addLine(0, x, 600, x, *dashedLine)};
        QGraphicsLineItem *yAxis {scene->addLine(x, 0, x, 600, *dashedLine)};
//        QGraphicsLineItem *line {scene->addLine(0, 0, 400, 300, *graphLine)};
        x+=30;
        //        QGraphicsPixmapItem *pointer {scene->addPixmap(QPixmap(50, 50))};
        //        scene->update();
    }

    //    QGraphicsItem * item {new};

    //    scene->addItem(QGraphicsItem);
    //    xAxis->setVisible(true);
    scene->addEllipse(30, 30, 5, 5, QPen(Qt::white), QBrush(Qt::white));
//    scene->update();
}

int calculate(int a, int b, int x)  {
    qDebug() << "DEBUG: calculate coordinate...";
    int y = a*x + b;
//    qDebug() << y;
    return y;
}

void MainWindow::plotCoordinate(int a, int b) {
    scene->addEllipse(a, b, 5, 5, QPen(Qt::blue), QBrush(Qt::blue));
    for (int t = 0; t<200; t++) {
//        qDebug() << "DEBUG: plot " << t << " coordinate...";
        int y = calculate(a, b, t);
//        qDebug() << y;
        scene->addEllipse(t, y, 5, 5, QPen(Qt::red), QBrush(Qt::red));
//        scene.update();
    }
    qDebug() << scene;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "DEBUG: pushed start button...";
//    scene->clear();
    int a = ui->aLineEdit->text().toInt();
    int b = ui->bLineEdit->text().toInt();
//    QGraphicsScene * scene = ui->graphicsView->scene();
    plotCoordinate(a, b);
//    qApp->processEvents();
//    scene->update();
//    ui->graphicsView->update();
}

