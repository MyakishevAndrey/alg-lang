#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include "login.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QPointer>
#include "connect.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:

private:
    Ui::Widget *ui;
    QStackedLayout *Sl;
    LogIn *li;
    QPointer<QNetworkAccessManager> manager;
    QPointer<FBconnect> con;
};

#endif // WIDGET_H
