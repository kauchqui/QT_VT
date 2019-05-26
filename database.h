#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QtSql/QSqlDatabase>

class database
{
private:


protected:

public:
    database();
    QSqlDatabase connect();
    QSqlQuery login(QString username, QString password);
    QSqlDatabase activeDBConnection;
    QSqlQuery query;


};

#endif // DATABASE_H
