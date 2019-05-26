#include "database.h"

database::database()
{

}

//Function to connect to the database and return the active connection
QSqlDatabase database::connect(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("testuser");
    db.setPassword("Rained99!Dusty1!");
    db.setDatabaseName("qt");
    db.open();
    if(db.isOpen()){
        qDebug() << "database class connection success";
        activeDBConnection = db;
        return db;
    }
    else{
        qDebug() << "database class connection failed";
        return db;
    }
}

QSqlQuery database::login(QString username, QString password){
    QSqlQuery queryDB(activeDBConnection);
    queryDB.prepare("SELECT users.ID from users where username = :username and password = :password");
    queryDB.bindValue(":username", username);
    queryDB.bindValue(":password", password);
   // queryDB.prepare("select * from users");

    if(!queryDB.exec()){
        qDebug()<<queryDB.lastError().text();
    }
    else{
            qDebug() << "queried";
            while(queryDB.next()){
                int id = queryDB.value(0).toInt();
                qDebug() << id;
            }
        }
    return queryDB;
}
