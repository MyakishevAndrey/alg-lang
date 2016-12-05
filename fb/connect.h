#ifndef CONNECT_H
#define CONNECT_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QPointer>
#include <QJsonObject>
#include <QEventLoop>
#include <QByteArray>
#include <QString>
#include <QJsonDocument>
#include <QDebug>

class FBconnect : public QObject
{
    Q_OBJECT
public:
    explicit FBconnect(QObject *parent = 0, QPointer<QNetworkAccessManager> manager = nullptr);
    ~FBconnect();
signals:

public slots:

private:
    QPointer<QNetworkAccessManager> manager;
    QJsonObject FBrequest(const QString& in);
    QJsonObject ObjectFromString(const QString &in);
};

#endif // CONNECT_H
