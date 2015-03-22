//options.h

#ifndef OPTIONS_H
#define OPTIONS_H

#include <QtGui>
#include <QVector>

//==================================================
//================= класс "Опции" ==================
//==================================================

class Options : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* vb; //  вертикальная компановка

    QGridLayout* gl1; // табличная компановка
    QGridLayout* gl2;
    QGridLayout* gl3;
    QGridLayout* gl4;

    QHBoxLayout* hb; // горизонтальная компановка

    QLabel* lTR1; // надписи
    QLabel* lTR2;
    QLabel* lTR3;
    QLabel* lTR4;

    QLabel* lred1; // ещё надписи
    QLabel* lred2;
    QLabel* lred3;
    QLabel* lred4;
    QLabel* lyellow1;
    QLabel* lyellow2;
    QLabel* lyellow3;
    QLabel* lyellow4;
    QLabel* lgreen1;
    QLabel* lgreen2;
    QLabel* lgreen3;
    QLabel* lgreen4;

    QSpinBox* sred1; // элементы для вода числового значения
    QSpinBox* sred2; // с возможность увеличения/уменьшения на 1
    QSpinBox* sred3; // при помощи стрелочек
    QSpinBox* sred4;
    QSpinBox* syellow1;
    QSpinBox* syellow2;
    QSpinBox* syellow3;
    QSpinBox* syellow4;
    QSpinBox* sgreen1;
    QSpinBox* sgreen2;
    QSpinBox* sgreen3;
    QSpinBox* sgreen4;

    QPushButton* pb1; // кнопки
    QPushButton* pb2;


public:
    Options(QWidget *parent = 0); // конструктор
    ~Options(); // деструктор

signals:
    void sendDO (QVector <int> vct); // сигнал

private slots:
    virtual void DO(); // слоты
    virtual void RESTART();


};

#endif // OPTIONS_H
