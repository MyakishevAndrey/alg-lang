#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Sl = new QStackedLayout(this);
    li = new LogIn(this);
    Sl->addWidget(li);
    setLayout(Sl);
    Sl->setCurrentIndex(0);
    manager = new QNetworkAccessManager(this);
    con = new FBconnect(this, manager);
}


Widget::~Widget()
{
    delete ui;
    delete con;
}
