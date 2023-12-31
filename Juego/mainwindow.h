#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "menu.h"
#include "nivel_inicial.h"
#include "nivel_principal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();

private slots:
    void menu_inicial();
    void inicial_principal(int bonus);
private:
    Ui::MainWindow *ui;
    menu *inicio;
    nivel_inicial *nivel_1;
    nivel_principal *nivel_2;
};
#endif // MAINWINDOW_H
