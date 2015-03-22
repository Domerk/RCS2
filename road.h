//road.h

#ifndef ROAD_H
#define ROAD_H

#include <QtGui>
#include <QVector>
#include <ctime>
#include "elements.h"
#include "widget_style.h"

//==================================================
//=============== ����� "������" ===================
//==================================================

class Road : public QWidget
{
    Q_OBJECT

public:
    Road(QWidget *parent = 0); // �����������
    ~Road(); // ����������
    virtual void paintEvent(QPaintEvent *); //�������� �� ���������

protected:
    virtual void timerEvent(QTimerEvent *); //�������� �� �����

private:
    QPainter* painter; //"��������"
    int level;
    int t1, t2, t3, t4; // ������ ������ ��� �������� ����������
    int tc1, tc2, tc3, tc4;
    bool nc1, nc2, nc3, nc4;
    Car *Car1; // �������
    Car *Car2;
    Car *Car3;
    Car *Car4;
    TrafficLight *TL1; // ���������
    TrafficLight *TL2;
    TrafficLight *TL3;
    TrafficLight *TL4;
    QVector <int> times; // ������ �����

public slots:
    void slotDO (QVector <int> vct); // �����
    void slotTC (int no);
    void slotLEVEL(int);
    void slotSTYLE (int number, int new_style);

signals:
    void signalTT(QVector <int> vct); // �������
    void signalSTYLE(int, int);

};

#endif // ROAD_H
