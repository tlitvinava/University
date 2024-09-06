#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTreeView>
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>

#include "binarysearchtree.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_findButton_clicked();

    void on_orderButton_clicked();

    void on_reverseButton_clicked();

    void on_byValueButton_clicked();

    void on_balanceButton_clicked();

private:
    Ui::MainWindow *ui;

    BinarySearchTree* tree;
    void showT(QStandardItem*, Node*);
    QStandardItemModel* model;
};
#endif // MAINWINDOW_H
