#include "plotter.h"
#include <iostream>
#include <QBrush>
#include <QLine>
#include <QPainter>
#include <QPen>


Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{
    atl = new int;
}
void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    //QLineF lin;
    int x1, y1, x2, y2;
    brush.setColor(QColor(0,191,255));//azul
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(148,0,211));//roxo
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width(), height());

    pen.setColor(QColor(199,21,133));//rosa

    int width =  this->width();
    int height = this->height();

    double xScale = (width) / (31);
    double yScale = (height) / (100);

    x1 = 0;
    y1 = height;
    //y2 = 1;
    //double m = (double)(height - y2) / (double)width;

    for(int i = 0; i< valor.size(); i++){
        x2 = i * xScale;
        y2 = height - valor.at(i)*yScale;

        QPointF p1(x1, y1);
        QPointF p2(x2,y2);
        painter.drawLine(p1, p2);

        x1 = x2;
        y1 = y2;
        if(valor.size() >= 34){
            valor.erase(valor.begin());
        }
    }

}


void Plotter::setValor(int _valor)
{
    valor.append(_valor);
    repaint();
}





















