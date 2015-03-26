// widget.h

#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QLabel>
#include <QMenuBar>
#include <QVector>
#include "road.h"
#include "options.h"
#include "widget_style.h"

//==================================================
//============ класс - окно приложения =============
//==================================================

class Widget : public QMainWindow //Наследует базовый класс библиотеки Qt
{
    Q_OBJECT //Этот макрос указывает компилятору moc, что нужно внедрить в
    //файл дополнительную информацию, прежде чем передать его
    //стандартному компилятору С++

public:
    Widget(QMainWindow *parent = 0); // конструктор
    ~Widget(); // деструктор

private slots:
    virtual void label_program(); // слоты
    virtual void label_developer();
    virtual void label_help();
    void LEVEL_1();
    void LEVEL_2();
    void LEVEL_3();
    void LEVEL_4();

signals:
    void signalLEVEL (int); // сигнал
    void signalSTYLE();

private:
    QMenuBar* menuBar; // меню
    QMenu* pmenu;
    QMenu* pmenu1;
    QMenu* pmenu2;
    QMenu* pmenu3;
    QLabel* lprogram; // надписи
    QLabel* ldeveloper;
    QLabel* lhelp;
    QHBoxLayout* mainLayout; // компановка
    Road* road; // дорога
    Options* options; // настойки
    QWidget* mainWidget; // дополнительный виджет
    WidgetStyle* wgs;
};

#endif // WIDGET_H
