#ifndef USER_H
#define USER_H
#include <QString>
#include <string>

enum class Role : int{
    ADMIN = 0,
    CUSTOMER = 1
};

class User
{
public:
    User(QString id, QString name, QString password, QString email, Role role);
    QString getUserName();
    QString getPassword();
    QString getEmail();
    Role getRole();
private:
    QString userID;
    QString userName;
    QString userPassword;
    QString userEmail;
    Role userRole;
};

#endif // USER_H
