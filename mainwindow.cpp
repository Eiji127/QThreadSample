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
    QGraphicsScene * scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(300, 300);
    ui->graphicsView->setSceneRect(0, 0, 300, 300);
    ui->graphicsView->rotate(270);

//    QGraphicsTextItem * text = scene->addText("Hello world");
    numStr = ui->aLineEdit->text();

    QPen * dashedLine {new QPen(QBrush(Qt::gray), 1, Qt::DotLine)};
    QPen * graphLine {new QPen(QBrush(Qt::red), 1, Qt::SolidLine)};

    int x = 0;
    for (int n = 0; n < 10; n++) {
        QGraphicsLineItem *xAxis {scene->addLine(0, x, 600, x, *dashedLine)};
        QGraphicsLineItem *yAxis {scene->addLine(x, 0, x, 600, *dashedLine)};
        QGraphicsLineItem *line {scene->addLine(0, 0, 400, 300, *graphLine)};
        x+=30;
//        QGraphicsPixmapItem *pointer {scene->addPixmap(QPixmap(50, 50))};
        scene->update();
    }

//    QGraphicsItem * item {new};

//    scene->addItem(QGraphicsItem);
//    xAxis->setVisible(true);

    scene->update();
}

int calculate(int a, int b)  {

}


void MainWindow::on_pushButton_clicked()
{
//    numStr = "123";
//    int num = numStr.toInt();
//    qDebug() << num;
    a = numStr.toInt();
     qDebug() << "a is : " << ui->aLineEdit->text();
    qDebug() << "a number is : " << a;
}

