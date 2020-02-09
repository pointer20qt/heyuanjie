#include "login.h"
#include "ui_login.h"
#include<QSqlQuery>
#include<QMessageBox>
#include"widget.h"
#include<QDebug>
#include"regisform.h"
#include<QFile>
#include<QIODevice>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("登录"));

   QFile f ("://white.qss");
   f.open(QIODevice::ReadOnly);
   this->setStyleSheet(f.readAll());

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("hyj");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open())
    {
            qDebug()<<"打开数据库成功";
    }
     else
     {
            qDebug()<<"打开数据库失败";
    }

    //登录按钮
    connect(ui->pushButton,QPushButton::clicked,[=](){
        QSqlQuery q;
        QSqlQuery q1;
         q.exec(QString("select * from cstu where cname='%1'").arg(ui->lineEdit->text()));     
          q.next();
          q1.exec(QString("select * from cstu where cname='%1' and pass='%2'").arg(ui->lineEdit->text(),ui->lineEdit_2->text()));
          q1.next();
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warning","您输入为空");
        }
        else
        {
           if(q.size()>=1)
           {
               if(q1.size()>=1)
               {
                   QMessageBox::warning(this,"恭喜","密码正确！");
                   Widget *w=new Widget(NULL,ui->lineEdit->text());
                   w->show();
                   this->close();
               }
               else
               {
                   QMessageBox::warning(this,"warning","密码错误！");
               }
           }
           else
             {
                 QMessageBox::warning(this,"warning","用户不存在！");
             }
        }
    });
    //注册按钮
    connect(ui->pushButton_2,QPushButton::clicked,[=](){
        RegisForm*r=new RegisForm;
        r->show();
          });


}

Login::~Login()
{
    delete ui;
}
