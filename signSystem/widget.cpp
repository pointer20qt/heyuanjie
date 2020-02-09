#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QCheckBox>
#include<QDateTime>
#include<QMessageBox>
#include<QPushButton>
#include"person.h"
#include<QFile>

Widget::Widget(QWidget *parent,QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
     this->setWindowTitle(QStringLiteral("主界面"));

    QFile f ("://white.qss");
    f.open(QIODevice::ReadOnly);
    this->setStyleSheet(f.readAll());

    this->sname=sname;
    dateToTabale("select * from cstu");
    displayClass();
    displaySno();

    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r,int c){
       Person *p=new Person;
       p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text());
       p->show();
    });

}


//数据显示到表格
void Widget::dateToTabale(QString sql)
{
    QSqlQuery q4;
    QSqlQuery q;
    q4.exec(QString("select csno from cstu where cname='%1'").arg(this->sname));
    q4.next();
    QString cursno=q4.value(0).toString();
   if(q.exec(sql))
   {
       ui->tableWidget->setRowCount(q.size());
       int i=0;
       while( q.next())
       {
           QCheckBox *c=new QCheckBox("未签到");
           QString sno =q.value(0).toString();

           QSqlQuery q3;
           q3.exec(QString("select ctime from ccheck where csno=%1 and date(ctime)=curdate()  order by ctime desc;").arg(sno));
           q3.next();
           if(sno!=cursno)
           {
               c->setDisabled(true);
           }
           if(q3.size())
           {
               c->setText("已签到");
              c->setDisabled(true);
              c->setChecked(true);
              ui->tableWidget->setItem(i,4,new QTableWidgetItem(q3.value(0).toString()));

           }
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(q.value(0).toString()));
             ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
              ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));

              ui->tableWidget->setCellWidget(i,3,c);

             connect(c,QCheckBox::clicked,[=](){
                 c->setText("已签到");
                c->setDisabled(true);
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
                QSqlQuery q1;
                q1.exec(QString("insert into ccheck values (%1,now())").arg(sno));
      } );
          i++;
       }
   }
}
//按照班级显示
void Widget::displayClass()
{
    QSqlQuery q4;
     ui->comboBox->addItem("全部班级");
   q4.exec("select distinct cclass from cstu");
       while(q4.next())
       {
           ui->comboBox->addItem(q4.value(0).toString());
       }
         connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text){
             if(text=="全部班级")
             {
                  dateToTabale("select * from cstu");
             }
             else
             {
                  dateToTabale(QString("select * from cstu where cclass='%1'").arg(text));
             }
         });
}
//按照学号显示
void Widget::displaySno()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warning","您输入为空");
        }
        else
        {
            dateToTabale(QString("select * from cstu where csno like '%1'").arg(ui->lineEdit->text()));
        }
    });

}
Widget::~Widget()
{
    delete ui;
}
