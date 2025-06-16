QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += controllers \
               models \
               views
# Sorgenti principali
SOURCES += main.cpp \
           globals.cpp \
           views/initialFileSelector.cpp \
           controllers/viewcontroller.cpp \
           controllers/usercontroller.cpp \
           controllers/bibliotecacontroller.cpp \
           models/usermodel.cpp \
           models/bibliotecamodel.cpp \
           models/itemmodel.cpp \
           models/bookmodel.cpp \
           models/filmmodel.cpp \
           models/musicmodel.cpp \
           views/auth/loginview.cpp \
           views/auth/registerview.cpp \
           views/mainview.cpp \
           views/showitem.cpp \
           views/edititem.cpp \
           views/createitem.cpp \
           views/accountview.cpp

# Header file
HEADERS += globals.h \
           views/initialFileSelector.h \
           controllers/viewcontroller.h \
           controllers/usercontroller.h \
           controllers/bibliotecacontroller.h \
           models/usermodel.h \
           models/bibliotecamodel.h \
           models/itemmodel.h \
           models/bookmodel.h \
           models/filmmodel.h \
           models/musicmodel.h \
           views/auth/loginview.h \
           views/auth/registerview.h \
           views/mainview.h \
           views/showitem.h \
           views/edititem.h \
           views/createitem.h \
           views/accountview.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
