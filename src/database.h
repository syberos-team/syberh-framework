#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlQueryModel>

#include "framework/nativesdkhandlerbase.h"
class Database : public NativeSdkHandlerBase
{
    Q_OBJECT
public:
    Q_INVOKABLE Database();
    ~Database();

    void request(QString callBackID,QString actionName,QVariantMap params);
    void submit(QString typeID,QString callBackID,QString actionName,QVariant dataRowList, QVariant attachementes);

    /**
     * @brief createTable 创建数据库和表
     * @param params 参数
     * @return 成功则返回true。
     *      失败则返回错误码。
     */
    void createTable(long callBackID, QVariantMap params);

    /**
     * @brief selectOperate 执行查询sql
     *
     * @param params 参数
     * @return 成功则返回数据。
     *      失败则返回错误码。
     */
    void selectOperate(long callBackID, QVariantMap params);

    /**
     * @brief execOperate 执行操作sql
     * @param params 参数
     * @return 成功则返回true。
     *      失败则返回错误码。
     */
    void execOperate(long callBackID, QVariantMap params);

    /**
     * @brief isDataExists 判断数据库是否存在
     * @param params 参数
     * @return 成功则返回true。
     *      失败则返回错误码。
     */
    void isDataExists(long callBackID);

    /**
     * @brief isTableExists 判断表是否存在
     * @param params 参数
     * @return 成功则返回true。
     *      失败则返回错误码。
     */
    void isTableExists(long callBackID, QVariantMap params);

private :

    static int typeId;
    QSqlDatabase myConnection;
    bool checkOrCreateDir(QString path);
};

#endif // DATABASE_H
