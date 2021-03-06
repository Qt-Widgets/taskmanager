#pragma once
#include <QObject>
#include <QTimer>
#include <QSqlDatabase>
#include "statscore.h"

class QSqlTableModel;
class QStringListModel;

class GenericStatsCore : public StatsCore
{
    Q_OBJECT
public:
    GenericStatsCore(int msec, QObject *parent=nullptr);
    virtual ~GenericStatsCore();
    virtual void setRefreshRate(int msec);
    virtual QAbstractItemModel *processModel();
    virtual QStringList staticInformation();
    virtual void killProcess(quint64 pid);
    virtual QAbstractItemModel *systemModel();

protected:
    QTimer refreshTimer_;
    QSqlDatabase database_;
    QSqlTableModel *processModel_;
    QStringListModel *systemModel_;
    QStringList staticSystemInfo_;
    virtual void updateProcesses();
    virtual void gatherStaticInformation() = 0;
    virtual void updateSystemInfo() = 0;
};
