INCLUDEPATH += src\

QT += core \
    charts

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets
lessThan(QT_MAJOR_VERSION, 5): error("requires Qt 5")

TARGET = BookAnalyzer
TEMPLATE = app

CONFIG += c++11

#QMAKE_CXXFLAGS += -v

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
    Services/*.cpp \
    Interfaces/*.cpp

HEADERS += \
    Controllers/*.h \
    Models/*.h \
    Views/*.h \
    Services/*.h \
    Interfaces/*.h

RESOURCES = resources.qrc

ICON = AppIcon.ico
OBJECTS_DIR = build
RCC_DIR = build/rcc
MOC_DIR = build/moc
QMAKE_LFLAGS += -no-pie #Altrimenti Ubuntu non lo vede come eseguibile, per altri sistemi operativi si può omettere
