#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"person.h"
#include<QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString sname=NULL);
    ~Widget();
    void dateToTabale(QString sql);
    void displayClass();
    void displaySno();
    void towidget(QString username);
    QString sname;
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
