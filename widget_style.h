//widget_style.h

#ifndef WIDGET_STYLE_H
#define WIDGET_STYLE_H


#include <QtGui>
#include <QWidget>
#include "options.h"

//==================================================
//============ класс - окно настроек =============
//==================================================

class WidgetStyle : public QWidget
{
    Q_OBJECT //Этот макрос указывает компилятору moc, что нужно внедрить в
    //файл дополнительную информацию, прежде чем передать его
    //стандартному компилятору С++

public:
    WidgetStyle(QWidget *parent = 0); // конструктор
   ~WidgetStyle(); // деструктор

signals:
    void signalSTYLE(int, int); // сигнал

private slots:
    virtual void C1(); // слоты для кнопок
    virtual void C2();
    virtual void C3();
    virtual void C4();

private:
    QVBoxLayout* vb; // вертикальная компановка
    QGridLayout* gl; // табличная компановка

    QPushButton* pb1; // кнопочки
    QPushButton* pb2;
    QPushButton* pb3;
    QPushButton* pb4;

    QSpinBox* spb; // спинбокс

    QLabel* t1; // надписи
    QLabel* t2;
    QLabel* t3;
    QLabel* t4;
};

#endif // WIDGET_STYLE_H
