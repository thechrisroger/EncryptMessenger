#include "data.h"

qint32 Data::duplicates = 1;

Data::Data(QString databaseName) : QObject(nullptr)
{
    QString currPath(QDir::currentPath());
    QDir dir(currPath + tr("/sql"));
    if(!dir.exists())
    {
        dir.mkdir((currPath + tr("/sql")));
    }
    database = new QSqlDatabase();
    if(database->contains(databaseName))
    {
        *database = QSqlDatabase::addDatabase("QSQLITE",databaseName + QString("_%1").arg(duplicates++));//%1 is a placeholder
    }
    else
    {
        *database = QSqlDatabase::addDatabase("QSQLITE",databaseName);
    }

    if(!QFile::exists(QDir::currentPath() + tr("/sql/") + databaseName + tr(".db")))
    {
        database->setDatabaseName(QDir::currentPath() + tr("/sql/") + databaseName + tr(".db"));
        if(!database->open())
        {
            QMessageBox::critical(nullptr,tr("警告"),tr("打开数据库失败"),QMessageBox::NoButton);
        }
    }
    else
    {
        database->setDatabaseName(QDir::currentPath() + tr("/sql/") + databaseName + tr(".db"));
        if(!database->open())
        {
            QMessageBox::critical(nullptr,tr("警告"),tr("打开数据库失败"),QMessageBox::NoButton);
        }
    }

    sqlQuery = new QSqlQuery(*database);
    sqlQuery->exec("CREATE TABLE IF NOT EXISTS record(direction VACHER(5) NOT NULL,datetime VARCHAR(30) NOT NULL,"
                   "message TEXT NOT NULL)");

    tableModel = new QSqlTableModel(nullptr,*database);
    tableView = new QTableView(&widget);

}

Data::~Data()
{
    delete sqlQuery;
    delete tableModel;
    delete tableView;
}

bool Data::insertRecord(QString direction,QString datetime,QString message)
{
    sqlQuery->prepare("INSERT INTO record(direction,datetime,message) VALUES(:direction,:datetime,:message)");
    sqlQuery->bindValue(":direction",QVariant(direction));
    sqlQuery->bindValue(":datetime",QVariant(datetime));
    sqlQuery->bindValue(":message",message);
    bool insertResult = sqlQuery->exec();
    return insertResult;
}

void Data::displayRecord()
{
    widget.setWindowTitle(tr("历史记录"));
    tableModel->setTable(tr("record"));
    tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!tableModel->select())
    {
        QMessageBox::warning(nullptr,tr("EM"),tr("打开数据表失败"),QMessageBox::NoButton);
    }
    tableModel->setHeaderData(tableModel->fieldIndex(tr("direction")),Qt::Horizontal,tr("发送方"));
    tableModel->setHeaderData(tableModel->fieldIndex(tr("datetime")),Qt::Horizontal,tr("时间"));
    tableModel->setHeaderData(tableModel->fieldIndex(tr("message")),Qt::Horizontal,tr("消息"));
    selectionModel = new QItemSelectionModel(tableModel);

    tableView->setModel(tableModel);
    tableView->setSelectionModel(selectionModel);
    tableView->setFixedSize(800,600);
    tableView->setColumnWidth(0,100);
    tableView->setColumnWidth(1,200);
    tableView->setColumnWidth(2,500);

    widget.show();
}
