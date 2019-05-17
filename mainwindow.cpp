#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked(){

}

void MainWindow::on_pushButton_login_clicked()
{
    qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("Rained99!Dusty1!");
    db.setDatabaseName("qt");
    if(db.isDriverAvailable("QMYSQL")){
        QMessageBox::information(this,"connection","driver is available");

    }
    if(db.isValid()){
        QMessageBox::information(this,"connection","database valid");

    }else{
        QMessageBox::information(this,"connection","database not valid");

    }

    if(db.open("root","Rained99!Dusty1!")){
        QMessageBox::information(this,"connection","database connected successfully");
    }
    else{
        QMessageBox::information(this, "not connected", "db no connect");
        QMessageBox::information(this,"connection",db.lastError().text());

    }
    QString username = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_password->text();



}
