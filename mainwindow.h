#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include "arraydatamodel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_removeButton_clicked();
    void on_swapButton_clicked();
    void on_insertButton_clicked();
    void on_populateButton_clicked();
    void on_replaceButton_clicked();
    void on_clearButton_clicked();

    
private:
    Ui::MainWindow *ui;
    ArrayDataModel * mModel;
};

#endif // MAINWINDOW_H
