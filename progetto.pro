INCLUDEPATH += src\

QT += core \
    charts

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets
lessThan(QT_MAJOR_VERSION, 5): error("requires Qt 5")

CONFIG += c++11

QMAKE_CXXFLAGS += -v

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x050000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    Controllers/*.cpp \
    Models/*.cpp \
    Views/*.cpp \
    Services/*.cpp

HEADERS += \
    Controllers/*.h \
    Models/*.h \
    Views/*.h \
    Services/*.h

RESOURCES = resources.qrc

ICON = AppIcon.ico