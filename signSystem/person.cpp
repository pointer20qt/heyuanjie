#include "person.h"
#include "ui_person.h"
#include<QSqlQuery>
#include<QTextCharFormat>
#include<QFile>
Person::Person(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Person)
{
    ui->setupUi(this);
     this->setWindowTitle(QStringLiteral("个人界面"));
    QFile f ("://white.qss");
    f.open(QIODevice::ReadOnly);
    this->setStyleSheet(f.readAll());

}
void Person::init(QString sno,QString sname)
{
    //查看选中的学生的学号，姓名，签到次数
    ui->label->setText("学号："+sno);
    ui->label_2->setText("姓名："+sname);
    QSqlQuery q;
    q.exec(QString("select ctime from ccheck where csno=%1 and "
                   "date_format(ctime,'%Y-%m')=date_format(curdate(),'%Y-%m')").arg(sno));
    ui->label_4->setText("签到次数："+QString::number(q.size()));

    //查看学生签到了哪几天
    QTextCharFormat f;
    f.setForeground(Qt::white);
    f.setBackground(Qt::black);
    while(q.next())
    {
        ui->calendarWidget->setDateTextFormat(q.value(0).toDate(),f);
    }
}
Person::~Person()
{
    delete ui;
}
