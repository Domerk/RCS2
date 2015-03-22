// elements.h

#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QtGui>
#include <ctime>
#include <QVector>

//==================================================
//============== класс "Автомобиль" ================
//==================================================
class Car : public QObject // машинка, наследует QObject
{
    Q_OBJECT // макрос, необходимый для работы с сигналами и слотами

private:
    int x; // координаты
    int y;
    short int direction; // направление
    short int Turn; // значение поворота, которое должна сделать машинка
    bool f; // флаги
    bool p;
    bool v;
    bool prev;
    int tc; // всякие дополнительные переменные
    int vx, vy;
    int my_number; // манишка будет знать свой номер
    int style; // дизайн
public:
    Car(int nx, int ny, int ndirection, int number); // конструктор
    void show(QPainter *painter); // рисовалка
    void moving(); //движение
    void turn(); // поворот
signals:
    void siganlXY(int dir, int mx, int my, int mt, bool mf, bool mp); // сигнал, передающий координаты
public slots:
    void slotTC(int no, int tc_color); // слот, принимающий значение сигнала светофора
    void slotXY(int dir, int mx, int my, int mt, bool mf, bool mp); // слот, принимающий координаты других машин
    void slotSTYLE (int number, int new_style); // слот для дизайна
};

//==================================================
//=============== класс "Светофор" =================
//==================================================
class TrafficLight : public QObject // светофор
{
    Q_OBJECT
protected:
    int x1, y1, x2, y2, a; // координаты, угол наклона полукруга
    int radius; // радиус полукруга
    int position; // метоположение
    int Traffic_Color; // цвет
    int cp; // дополнительная переменная
    QVector <int> TTtimes; // вектор времени
public:
    TrafficLight(int npos, int ncolor);
    void light (int atime); // светить, принимает время, через которое должен сменяться сигнал
    void show(QPainter *painter); // рисовалка
signals:
    void signalTC(int no, int tc_color); // сигнал - цвет светофора
    void signalR(int no); // сигнол - номер светофора
public slots:
    void slotTT(QVector <int> vct); // слот для времени
};
//==================================================

#endif // ELEMENTS_H
