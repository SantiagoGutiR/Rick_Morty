#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inicio = new menu();
    nivel_1 = new nivel_inicial();

    ui->graphicsView->setScene(inicio->getEscena());
    connect(inicio->getJugar(), SIGNAL(clicked(bool)), this, SLOT(menu_inicial()));
    connect(nivel_1, SIGNAL(cambio_nivel()), this, SLOT(inicia_principal()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete inicio;
    delete nivel_1;
}

void MainWindow::menu_inicial() //PENDIENTE POR CUADRAR
{//slot
    ui->graphicsView->setScene(nivel_1->getEscena());
}

void MainWindow::inicia_principal()
{
    ui->graphicsView->hide();
}
