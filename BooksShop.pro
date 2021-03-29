QT += quick sql

CONFIG += c++17

CONFIG += felgo
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        administrator.cpp \
        customer.cpp \
        main.cpp \
        user.cpp

RESOURCES += Qml/main.qml

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD/Qml/main.qml
QML_IMPORT_PATH += $$PWD/Qml/LoginPage.qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += Qml\main.qml

DEFINES += SOURCE_PATH=$$PWD

#DISTFILES += \
#    LoginPage.qml

DISTFILES += \
    Database/user.db \
    Qml/LoginPage.qml

SUBDIRS += $$PWD/Database

HEADERS += \
    administrator.h \
    customer.h \
    user.h
