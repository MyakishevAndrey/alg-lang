#include "connect.h"

FBconnect::FBconnect(QObject *parent, QPointer<QNetworkAccessManager> _manager) : QObject(parent)
{
    manager = _manager;
    QString urls("https://graph.facebook.com/bgolub?fields=id,name,picture");
    qDebug() << FBrequest(urls);
}

FBconnect::~FBconnect()
{

}

QJsonObject FBconnect::FBrequest(const QString &in)
{
    QUrl url(in);
        QNetworkRequest request(url);
        QNetworkReply* reply = manager->get(request);

        QEventLoop loop;
        connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();

        if(reply->error() != QNetworkReply::NoError){
            //qDebug() <<  reply->errorString();
            //emit replyError(reply->errorString());
            qDebug() << "error";
            reply->deleteLater();
            return QJsonObject();
        }
        QByteArray content = reply->readAll();

        QString  str = QString::fromUtf8(content.data(), content.size());
        qDebug() << "str: " << str;
        QJsonObject  jObj  =  ObjectFromString(str);
        reply->deleteLater();
        return jObj;

}

QJsonObject FBconnect::ObjectFromString(const QString &in){
    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());

    // check validity of the document
    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();
        }
        else
        {
            qDebug() << "Document is not an object" << endl;
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << in << endl;
    }

    return obj;
}
