#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T21:40:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LiquiNet
TEMPLATE = app


SOURCES += main.cpp\
        initialize.cpp \
    detail_input.cpp \
    progress.cpp \
    results.cpp \
    pipe_segement_details.cpp \
    booster_details.cpp \
    flow_control_valve_details.cpp \
    calc_h.cpp \
    calc_c.cpp \
    set_h_q.cpp \
    error_dialog.cpp \
    check_h.cpp \
    thread.cpp \
    selection_help.cpp

unix{
LIBS += -llapack -lblas -larmadillo
#INCLUDEPATH +=include
#LIBS +=-L"include" -llapack -lblas
}
win32{
INCLUDEPATH +=E:\Programs\LiquiNet\include
#LIBS += -larmadillo
#LIBS +=-L"E:\Programs\LiquiNet\include" -llapack -lopenblas
LIBS += -llapack -lopenblas
}

HEADERS  += initialize.h \
    detail_input.h \
    progress.h \
    results.h \
    booster_details.h \
    flow_control_valve_details.h \
    global_variables.h \
    pipe_segement_details.h \
    error_dialog.h \
    thread.h \
    selection_help.h

FORMS    += initialize.ui \
    detail_input.ui \
    progress.ui \
    results.ui \
    pipe_segement_details.ui \
    booster_details.ui \
    flow_control_valve_details.ui \
    error_dialog.ui \
    selection_help.ui
