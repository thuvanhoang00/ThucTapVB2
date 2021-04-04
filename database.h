#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QtSql>
#include <QSqlQuery>

class Database
{
public:
    Database(const QString &path);
    ~Database();

    bool createTable(const QString& tb);
    bool addBook(const QString& name);
    bool addAllInfo(const QString &name, const QString& author, const QString& year);
    bool addYear(const QString& year);
    bool isExists(const QString& name);
    bool removeBook(const QString& name);
    bool removeAllBooks();
    void printAllBooks();

private:
    QSqlDatabase m_db;
};

#endif // DATABASE_H
