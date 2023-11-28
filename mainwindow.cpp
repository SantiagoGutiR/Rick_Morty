#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inicio = new menu();
    nivel_1 = new nivel_inicial();
    nivel_2 = new nivel_principal();


    ui->graphicsView->setScene(nivel_2->getEscena());
    nivel_2->getTiempo_disparo()->start(10);

    //ui->graphicsView->setScene(inicio->getEscena());
    connect(inicio, SIGNAL(cambio_escena()), this, SLOT(menu_inicial()));
    connect(nivel_1, SIGNAL(cambio_nivel(int)), this, SLOT(inicial_principal(int)));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    nivel_2->moviento_personaje(event);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete inicio;
    delete nivel_1;
    delete nivel_2;
}

void MainWindow::menu_inicial()
{//Slot
    nivel_1->getTiempo_limite()->start(20000);
    ui->graphicsView->setScene(nivel_1->getEscena());
}

void MainWindow::inicial_principal(int bonus)
{//Slot
    ui->graphicsView->setScene(nivel_2->getEscena());
}
