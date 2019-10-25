#include "notification.h"

#include <QDebug>
#include "framework/common/errorinfo.h"

int Notification::typeId = qRegisterMetaType<Notification *>();

Notification::Notification(){
    badge = new CBadge();
    notificationManager = new CNotificationManager();
}

Notification::~Notification(){
    delete badge;
    delete notificationManager;
}

void Notification::request(QString callBackID, QString actionName, QVariantMap params)
{
    qDebug() << Q_FUNC_INFO << "request" << callBackID << endl;
    if (actionName == "badgeShow"){
        badgeShow(callBackID.toLong(), params);
    }else if(actionName == "sendNotification"){
        sendNotification(callBackID.toLong(), params);
    }else if(actionName == "removeNotification"){
        removeNotification(callBackID.toLong(), params);
    }
}

void Notification::submit(QString typeID, QString callBackID, QString actionName, QVariant dataRowList, QVariant attachementes)
{
    Q_UNUSED(typeID)
    Q_UNUSED(callBackID)
    Q_UNUSED(actionName)
    Q_UNUSED(dataRowList)
    Q_UNUSED(attachementes)
}

void Notification::badgeShow(long callBackID,QVariantMap params){
    qDebug() << Q_FUNC_INFO << "badgeShow" << params << endl;
    QString appid = params.value("appid").toString();
    long num = params.value("num").toInt();

    badge->setValue(appid,num);

    emit success(callBackID, true);
}

void Notification::sendNotification(long callBackID,QVariantMap params){
    qDebug() << Q_FUNC_INFO << "sendNotification" << params << endl;
    long type = params.value("type").toInt();
    QString title = params.value("title").toString();
    QString subtitle = params.value("subtitle").toString();

    CNotification notification;
    notification.setTitle(title);
    notification.setSubtitle(subtitle);

    if(type == 1){
        notification.setAttributes(CAbstractNotification::DeleteOnFinished);//通知在状态栏显示完成后， 自动删除
    }else if(type == 2){
        notification.setAttributes(CAbstractNotification::HideDisplayTime);//通知发送时间不显示在下拉列表上
    }else if(type == 3){
        notification.setAttributes(CAbstractNotification::DeleteOnReboot);//通知在手机重启后， 自动删除
    }
    notification.setVibrationMode(CAbstractNotification::ForceVibrationMode);//强制震动模式。 忽略系统的震动设置， 在通知发送是， 必须震动
    notificationManager->sendNotification(notification);

    emit success(callBackID, true);
}

void Notification::removeNotification(long callBackID,QVariantMap params){
    qDebug() << Q_FUNC_INFO << "removeNotification" << params << endl;

    notificationManager->removeAllNotifications();

    emit success(callBackID, true);
}
