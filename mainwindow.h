#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include "nivel_inicial.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    menu *inicio;
    nivel_inicial * nivel_1;
    ~MainWindow();

private slots:
    void menu_inicial();
    void inicia_principal();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
