//road.h

#ifndef ROAD_H
#define ROAD_H

#include <QtGui>
#include <QVector>
#include <ctime>
#include "elements.h"
#include "widget_style.h"

//==================================================
//=============== класс "Дорога" ===================
//==================================================

class Road : public QWidget
{
    Q_OBJECT

public:
    Road(QWidget *parent = 0); // конструктор
    ~Road(); // деструктор
    virtual void paintEvent(QPaintEvent *); //отвечает за рисование

protected:
    virtual void timerEvent(QTimerEvent *); //отвечает за время

private:
    QPainter* painter; //"художник"
    int level;
    int t1, t2, t3, t4; // всякие нужные для анимации переменные
    int tc1, tc2, tc3, tc4;
    bool nc1, nc2, nc3, nc4;
    Car *Car1; // машинки
    Car *Car2;
    Car *Car3;
    Car *Car4;
    TrafficLight *TL1; // светофоры
    TrafficLight *TL2;
    TrafficLight *TL3;
    TrafficLight *TL4;
    QVector <int> times; // нужное время

public slots:
    void slotDO (QVector <int> vct); // слоты
    void slotTC (int no);
    void slotLEVEL(int);
    void slotSTYLE (int number, int new_style);

signals:
    void signalTT(QVector <int> vct); // сигналы
    void signalSTYLE(int, int);

};

#endif // ROAD_H
