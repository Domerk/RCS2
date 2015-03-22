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
//============ ����� - ���� ���������� =============
//==================================================

class Widget : public QMainWindow //��������� ������� ����� ���������� Qt
{
    Q_OBJECT //���� ������ ��������� ����������� moc, ��� ����� �������� �
    //���� �������������� ����������, ������ ��� �������� ���
    //������������ ����������� �++

public:
    Widget(QMainWindow *parent = 0); // �����������
    ~Widget(); // ����������

private slots:
    virtual void label_program(); // �����
    virtual void label_developer();
    virtual void label_help();
    void LEVEL_1();
    void LEVEL_2();
    void LEVEL_3();
    void LEVEL_4();

signals:
    void signalLEVEL (int); // ������
    void signalSTYLE();

private:
    QMenuBar* menuBar; // ����
    QMenu* pmenu;
    QMenu* pmenu1;
    QMenu* pmenu2;
    QMenu* pmenu3;
    QLabel* lprogram; // �������
    QLabel* ldeveloper;
    QLabel* lhelp;
    QHBoxLayout* mainLayout; // ����������
    Road* road; // ������
    Options* options; // ��������
    QWidget* mainWidget; // �������������� ������
    WidgetStyle* wgs;
};

#endif // WIDGET_H
