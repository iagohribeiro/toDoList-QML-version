#include "taskmodel.h"

#include "taskitem.h"
#include <QtDebug>
taskModel::taskModel(QObject *parent)
    : QAbstractListModel(parent)
    , taskList(nullptr)
{
}

int taskModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !taskList)
        return 0;

    // FIXME: Implement me!
    return taskList->items().size();
}

QVariant taskModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !taskList)
        return QVariant();

    const Item item = taskList->items().at(index.row());

    switch (role) {
    case doneTask:
       return QVariant(item.taskStatus);
    case descriptionTask:
       return QVariant(item.taskDescription);
    }
    return QVariant();
}

bool taskModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << "Enter setData method";
    if(!taskList)
        return false;

    Item item = taskList->items().at(index.row());

    switch (role) {
    case doneTask:
       item.taskStatus = value.toBool();
       qDebug() << value.toBool();
        break;
    case descriptionTask:
       item.taskDescription = value.toString();
        break;
    }

    if (taskList->setItem(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags taskModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> taskModel::taskNames()
{
    qDebug() << "Ester taskNames";
    QHash<int, QByteArray> names;
    names[doneTask] = "taskStatus";
    names[descriptionTask] = "taskDescription";

    return names;
}

taskItem *taskModel::list() const
{
    return taskList;
}

void taskModel::setList(taskItem *newTaskList)
{
    beginResetModel();

    qDebug() << "Enter SetList method";

    if(taskList)
        taskList->disconnect(this);

    taskList = newTaskList;

    if (taskList)
    {
        qDebug() << "Enter connections condition";
        connect(taskList, &taskItem::preItemAppended, this, [=](){
            const int index = taskList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(taskList, &taskItem::postItemAppended, this, [=](){
            endInsertRows();
        });

        connect(taskList, &taskItem::preItemRemoved, this, [=](int index){
            beginRemoveRows(QModelIndex(), index, index);
        });

        connect(taskList, &taskItem::postItemRemoved, this, [=](){
            endRemoveRows();
        });
    }

    endResetModel();
}
