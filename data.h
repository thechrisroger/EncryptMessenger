#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

#include <QDir>
#include <QString>
#include <QDebug>

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QString databaseName);
    ~Data();

    bool insertRecord(QString direction, QString datetime, QString message);

private:
    QWidget widget;
    QSqlDatabase *database;
    QSqlQuery *sqlQuery;
    QSqlTableModel *tableModel;
    QTableView *tableView;
    QItemSelectionModel *selectionModel;
    static qint32 duplicates;
signals:

public slots:
    void displayRecord();

};


#endif // DATA_H
