#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money {0};
    void changeMoney(int diff);

    void buyDrink(int diff);

private slots:
    void on_PB10_clicked();

    void on_PB50_clicked();

    void on_PB100_clicked();

    void on_PB500_clicked();

    void on_PB_reset_clicked();

    void on_PB_coffee_clicked();

    void on_PB_tea_clicked();

    void on_PB_milk_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
