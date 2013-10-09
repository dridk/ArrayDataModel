#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModel = new ArrayDataModel;

    ui->listView->setModel(mModel);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_removeButton_clicked()
{
    qDebug()<<"remove";
    QList <int> rows;
    if (ui->listView->selectionModel()->selectedRows().count() > 0) {
        foreach ( QModelIndex index, ui->listView->selectionModel()->selectedRows())
            rows.append(index.row());

        for (int i=rows.size()-1; i>=0; i--)
        {
            qDebug()<<rows[i];
            mModel->removeAt(rows[i]);
        }
    }

    else
    {
        QMessageBox::information(this,"error", "select one or more rows");
    }

}

void MainWindow::on_swapButton_clicked()
{
    qDebug()<<"swap";
    if ( ui->listView->selectionModel()->selectedRows().count() == 2)
    {
        int i  = ui->listView->selectionModel()->selectedRows().first().row();
        int j = ui->listView->selectionModel()->selectedRows().last().row();
        mModel->swap(i,j);
    }

    else
    {
        QMessageBox::information(this,"error","Select two rows");
    }

}

void MainWindow::on_insertButton_clicked()
{
    qDebug()<<"insert";

    QVariantList list;
    list.append("pineapple");
    list.append("kiwi");

    mModel->insert(0,list);

}

void MainWindow::on_populateButton_clicked()
{
    qDebug()<<"populate";
    mModel->append("Apple");
    mModel->append("Orange");
    mModel->append("peach");
    mModel->append("Banana");
    mModel->append("Cherry");


}

void MainWindow::on_replaceButton_clicked()
{
    qDebug()<<"replace";
    if (( ui->listView->selectionModel()->selectedRows().count() == 1) && mModel->size() > 0 )
    {
        QVariant fruit = "Lemon";
        mModel->replace(ui->listView->currentIndex().row(), fruit);

    }

    else
    {
        QMessageBox::information(this,"error","Select one row");
    }

}

void MainWindow::on_clearButton_clicked()
{
    qDebug()<<"remove";
    mModel->clear();

}
