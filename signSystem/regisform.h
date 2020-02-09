#ifndef REGISFORM_H
#define REGISFORM_H

#include <QWidget>

namespace Ui {
class RegisForm;
}

class RegisForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegisForm(QWidget *parent = 0);
    ~RegisForm();

private:
    Ui::RegisForm *ui;
};

#endif // REGISFORM_H
