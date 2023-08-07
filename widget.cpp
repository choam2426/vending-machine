#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::buyDrink(int diff){
    if (money - diff <0){
        QMessageBox::information(nullptr, "hey", "not enough money man");
    }
    else{
    money -= diff;
    ui->lcdNumber->display(money);
    QMessageBox::information(nullptr, "result", "good choice");
    }
}


void Widget::on_PB10_clicked()
{
    changeMoney(10);
}


void Widget::on_PB50_clicked()
{
    changeMoney(50);
}


void Widget::on_PB100_clicked()
{
    changeMoney(100);
}


void Widget::on_PB500_clicked()
{
    changeMoney(500);
}


void Widget::on_PB_reset_clicked()
{
    int coin[4] = {500, 100, 50, 10};
    int change_coin[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        change_coin[i] = money/coin[i];
        money = money % coin[i];
        if (money == 0){
            break;
        }
    }
    QString message = QString("500: %1\n100: %2\n50: %3\n10: %4").arg(change_coin[0]).arg(change_coin[1]).arg(change_coin[2]).arg(change_coin[3]);
    QMessageBox::information(nullptr, "change", message);
    ui->lcdNumber->display(0);
}


void Widget::on_PB_coffee_clicked()
{
    buyDrink(100);
}


void Widget::on_PB_tea_clicked()
{
    buyDrink(150);
}


void Widget::on_PB_milk_clicked()
{
    buyDrink(200);
}

