#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QMessageBox>
#include "database.h"
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

//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setUserName("testuser");
//    db.setPassword("Rained99!Dusty1!");
//    db.setDatabaseName("qt");
    database database;
    QSqlDatabase db = database.connect();
    QString username = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_password->text();
    QSqlQuery query;
    QSqlQuery loginQuery(db);
    loginQuery = database.login(username,password);

//    if(!loginQuery.exec()){
//        qDebug() <<loginQuery.lastError().text();
//    }
//    else{
//        while(loginQuery.next()){
//            int id = loginQuery.value(0).toInt();
//            qDebug() << id;
//        }
//    }


//    if( !query.exec("SELECT * FROM users"))   //"select ID from users where username = 'username' and password = 'password'"))
//    {
//        qDebug() << query.lastError().text();
//    }
//    else{
//        qDebug() << "queried";
//        while(query.next()){
//            int id = query.value(0).toInt();
//            qDebug() << id;
//        }
//    }



}
