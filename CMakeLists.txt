cmake_minimum_required(VERSION 3.16)
project(Biblioteca)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
include_directories(${CMAKE_SOURCE_DIR}/controllers)
include_directories(${CMAKE_SOURCE_DIR}/models)
include_directories(${CMAKE_SOURCE_DIR}/views)
add_executable(Biblioteca
        main.cpp
        globals.cpp globals.h

        controllers/viewcontroller.cpp controllers/viewcontroller.h
        controllers/usercontroller.cpp controllers/usercontroller.h
        controllers/bibliotecacontroller.cpp controllers/bibliotecacontroller.h

        models/usermodel.cpp models/usermodel.h
        models/bibliotecamodel.cpp models/bibliotecamodel.h
        models/itemmodel.cpp models/itemmodel.h
        models/bookmodel.cpp models/bookmodel.h
        models/filmmodel.cpp models/filmmodel.h
        models/musicmodel.cpp models/musicmodel.h

        views/auth/loginview.cpp views/auth/loginview.h
        views/auth/registerview.cpp views/auth/registerview.h
        views/mainview.cpp views/mainview.h
        views/showitem.cpp views/showitem.h
        views/edititem.cpp views/edititem.h
        views/createitem.cpp views/createitem.h
        views/accountview.cpp views/accountview.h
)
target_link_libraries(Biblioteca PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
