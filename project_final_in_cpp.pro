QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choose_the_category_of_question.cpp \
    choose_the_difficulty_to_question.cpp \
    choose_the_difficulty_to_question_to_survival_mode.cpp \
    choose_the_type_of_game.cpp \
    main.cpp \
    mainwindow.cpp \
    pvp_mode_questions.cpp \
    question_of_player_to_pvp_mode.cpp \
    question_of_player_to_survival_mode.cpp \
    window_of_question_player.cpp

HEADERS += \
    choose_the_category_of_question.h \
    choose_the_difficulty_to_question.h \
    choose_the_difficulty_to_question_to_survival_mode.h \
    choose_the_type_of_game.h \
    class_information_of_question.h \
    information_of_players.h \
    mainwindow.h \
    pvp_mode_questions.h \
    question_of_player_to_pvp_mode.h \
    question_of_player_to_survival_mode.h \
    window_of_question_player.h

FORMS += \
    choose_the_category_of_question.ui \
    choose_the_difficulty_to_question.ui \
    choose_the_difficulty_to_question_to_survival_mode.ui \
    choose_the_type_of_game.ui \
    mainwindow.ui \
    pvp_mode_questions.ui \
    question_of_player_to_pvp_mode.ui \
    question_of_player_to_survival_mode.ui \
    window_of_question_player.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += C:\Users\ModernSystem\Desktop\curl-8.8.0_1-win64-mingw\include
LIBS += -L/Users/ModernSystem/Desktop/curl-8.8.0_1-win64-mingw/lib -lcurl

INCLUDEPATH += C:\Users\ModernSystem\Desktop\include
LIBS += -L/Users/ModernSystem/Desktop/include/lib
