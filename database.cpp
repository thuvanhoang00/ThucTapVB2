#include "database.h"

Database::Database(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open()){
        qDebug() << "Error: connection with database failed";
    }
    else{
        qDebug() << "Connection ok!";
    }
}

Database::~Database()
{
    if(m_db.isOpen()){
        m_db.close();
    }
}

bool Database::createTable(const QString &tb)
{
    bool ret = true;
    QSqlQuery query;
    query.prepare("CREATE TABLE books(id INTEGER PRIMARY KEY, name TEXT);");

    if(query.exec()){
        qDebug() << "Couldnt create the table " << tb;
    }
    else{
        ret = true;
    }
    return ret;
}

bool Database::addBook(const QString &name)
{
    bool ret = false;

    QSqlQuery query;
    query.prepare("INSERT INTO books (name) VALUES (:name)");
    query.bindValue(":name", name);
    if(query.exec()){
        ret = true;
    }
    else {
        qDebug() << "addBook error: " << query.lastError();
    }
    return ret;
}

bool Database::addAllInfo(const QString &name, const QString& author, const QString& year)
{
    bool ret = false;

    QSqlQuery query{m_db};
    if(!query.exec("CREATE TABLE IF NOT EXISTS books(name VARCHAR(200) NOT NULL, author VARCHAR(200) NOT NULL, year VARCHAR(5) NOT NULL)")){
        qDebug() << query.lastError();

    }
    query.prepare("INSERT INTO books(name, author, year)"
                  "VALUES (:name, :author, :year)");
    query.bindValue(":name", name);
    query.bindValue(":author", author);
    query.bindValue(":year", year);

    if(query.exec()){
        ret = true;
    }
    else{
        qDebug() << "addAllInfo error: " << query.lastError();
    }

    return ret;
}

bool Database::isExists(const QString &name)
{
    bool ret = false;

    QSqlQuery query;
    query.prepare("SELECT name FROM books WHERE name = (:name_");
    query.bindValue(":name", name);

    if(query.exec()){
        if(query.next()){
            ret = true;
        }
    }
    else {
        qDebug() << "Not exists! " << query.lastError();
    }
    return ret;
}

bool Database::removeBook(const QString &name)
{
    bool ret = false;
    if(isExists(name)){
        QSqlQuery delQuery;
        delQuery.prepare("DELETE FROM books WHERE name = (:name)");
        delQuery.bindValue(":name", name);
        ret = delQuery.exec();
        if(ret == false){
            qDebug() << "remove failed " << delQuery.lastError();
        }
    }
    return ret;
}

bool Database::removeAllBooks()
{
    bool ret = false;
    QSqlQuery query;
    query.prepare("DELETE FROM books");

    if(query.exec()){
        ret = true;
    }
    else {
        qDebug() << "remove all books failed " << query.lastError();
    }
    return ret;
}

void Database::printAllBooks()
{
    QSqlQuery query("SELECT * FROM books");
    int idName = query.record().indexOf("name");
    while(query.next()){
        QString name = query.value(idName).toString();
        qDebug() << name;
    }
}
