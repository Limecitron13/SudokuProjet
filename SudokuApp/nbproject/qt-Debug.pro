# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = SudokuApp
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += DialogGrilleInvalide.cpp DialogGrilleValide.cpp FenetrePrincipal.cpp main.cpp
HEADERS += DialogGrilleInvalide.h DialogGrilleValide.h FenetrePrincipal.h
FORMS += DialogGrilleInvalide.ui DialogGrilleValide.ui FenetrePrincipal.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../Sudoku 
LIBS += ../Sudoku/dist/Debug/GNU-Linux/libsudoku.a  
