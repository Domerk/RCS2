//widget_style.h

#ifndef WIDGET_STYLE_H
#define WIDGET_STYLE_H


#include <QtGui>
#include <QWidget>
#include "options.h"

//==================================================
//============ ����� - ���� �������� =============
//==================================================

class WidgetStyle : public QWidget
{
    Q_OBJECT //���� ������ ��������� ����������� moc, ��� ����� �������� �
    //���� �������������� ����������, ������ ��� �������� ���
    //������������ ����������� �++

public:
    WidgetStyle(QWidget *parent = 0); // �����������
   ~WidgetStyle(); // ����������

signals:
    void signalSTYLE(int, int); // ������

private slots:
    virtual void C1(); // ����� ��� ������
    virtual void C2();
    virtual void C3();
    virtual void C4();

private:
    QVBoxLayout* vb; // ������������ ����������
    QGridLayout* gl; // ��������� ����������

    QPushButton* pb1; // ��������
    QPushButton* pb2;
    QPushButton* pb3;
    QPushButton* pb4;

    QSpinBox* spb; // ��������

    QLabel* t1; // �������
    QLabel* t2;
    QLabel* t3;
    QLabel* t4;
};

#endif // WIDGET_STYLE_H
