// elements.h

#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QtGui>
#include <ctime>
#include <QVector>

//==================================================
//============== ����� "����������" ================
//==================================================
class Car : public QObject // �������, ��������� QObject
{
    Q_OBJECT // ������, ����������� ��� ������ � ��������� � �������

private:
    int x; // ����������
    int y;
    short int direction; // �����������
    short int Turn; // �������� ��������, ������� ������ ������� �������
    bool f; // �����
    bool p;
    bool v;
    bool prev;
    int tc; // ������ �������������� ����������
    int vx, vy;
    int my_number; // ������� ����� ����� ���� �����
    int style; // ������
public:
    Car(int nx, int ny, int ndirection, int number); // �����������
    void show(QPainter *painter); // ���������
    void moving(); //��������
    void turn(); // �������
signals:
    void siganlXY(int dir, int mx, int my, int mt, bool mf, bool mp); // ������, ���������� ����������
public slots:
    void slotTC(int no, int tc_color); // ����, ����������� �������� ������� ���������
    void slotXY(int dir, int mx, int my, int mt, bool mf, bool mp); // ����, ����������� ���������� ������ �����
    void slotSTYLE (int number, int new_style); // ���� ��� �������
};

//==================================================
//=============== ����� "��������" =================
//==================================================
class TrafficLight : public QObject // ��������
{
    Q_OBJECT
protected:
    int x1, y1, x2, y2, a; // ����������, ���� ������� ���������
    int radius; // ������ ���������
    int position; // �������������
    int Traffic_Color; // ����
    int cp; // �������������� ����������
    QVector <int> TTtimes; // ������ �������
public:
    TrafficLight(int npos, int ncolor);
    void light (int atime); // �������, ��������� �����, ����� ������� ������ ��������� ������
    void show(QPainter *painter); // ���������
signals:
    void signalTC(int no, int tc_color); // ������ - ���� ���������
    void signalR(int no); // ������ - ����� ���������
public slots:
    void slotTT(QVector <int> vct); // ���� ��� �������
};
//==================================================

#endif // ELEMENTS_H
