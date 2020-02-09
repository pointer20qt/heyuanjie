#include "regisform.h"
#include "ui_regisform.h"
#include<QPushButton>
#include<QSqlQuery>
#include<QMessageBox>
#include<QString>
#include<QFile>

RegisForm::RegisForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisForm)
{
    ui->setupUi(this);
     this->setWindowTitle(QStringLiteral("注册"));
    QFile f ("://white.qss");
    f.open(QIODevice::ReadOnly);
    this->setStyleSheet(f.readAll());

    connect(ui->pushButton,QPushButton::clicked,[=](){
       QSqlQuery q;
       q.exec(QString("insert into cstu values (%1,'%2','%3','%4')").arg(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text()));
       QMessageBox::warning(this,"恭喜","注册成功！");
    } );
}

RegisForm::~RegisForm()
{
    delete ui;
}
