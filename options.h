//options.h

#ifndef OPTIONS_H
#define OPTIONS_H

#include <QtGui>
#include <QVector>

//==================================================
//================= ����� "�����" ==================
//==================================================

class Options : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* vb; //  ������������ ����������

    QGridLayout* gl1; // ��������� ����������
    QGridLayout* gl2;
    QGridLayout* gl3;
    QGridLayout* gl4;

    QHBoxLayout* hb; // �������������� ����������

    QLabel* lTR1; // �������
    QLabel* lTR2;
    QLabel* lTR3;
    QLabel* lTR4;

    QLabel* lred1; // ��� �������
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

    QSpinBox* sred1; // �������� ��� ���� ��������� ��������
    QSpinBox* sred2; // � ����������� ����������/���������� �� 1
    QSpinBox* sred3; // ��� ������ ���������
    QSpinBox* sred4;
    QSpinBox* syellow1;
    QSpinBox* syellow2;
    QSpinBox* syellow3;
    QSpinBox* syellow4;
    QSpinBox* sgreen1;
    QSpinBox* sgreen2;
    QSpinBox* sgreen3;
    QSpinBox* sgreen4;

    QPushButton* pb1; // ������
    QPushButton* pb2;


public:
    Options(QWidget *parent = 0); // �����������
    ~Options(); // ����������

signals:
    void sendDO (QVector <int> vct); // ������

private slots:
    virtual void DO(); // �����
    virtual void RESTART();


};

#endif // OPTIONS_H
