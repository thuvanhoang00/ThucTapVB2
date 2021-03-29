#include "user.h"

User::User(QString id, QString name, QString password, QString email, Role role)
{
    userID = id;
    userName = name;
    userPassword = password;
    userEmail = email;
    userRole = role;
}

QString User::getUserName()
{
    return userName;
}

QString User::getPassword()
{
    return userPassword;
}

QString User::getEmail()
{
    return userEmail;
}

Role User::getRole()
{
    return userRole;
}
