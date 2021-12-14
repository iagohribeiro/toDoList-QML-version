#include "taskitem.h"
#include <QtDebug>

taskItem::taskItem(QObject *parent) : QObject(parent)
{
}

QVector<Item> taskItem::items() const
{
    return itemsList;
}

bool taskItem::setItem(int index, const Item &item)
{
    if (index < 0 || index >= itemsList.size())
    {
        return false;
    }

    const Item &oldItem = itemsList.at(index);

    if(item.taskStatus == oldItem.taskStatus && item.taskDescription == oldItem.taskDescription)
    {
        return false;
    }

    itemsList[index] = item;
    return true;
}

void taskItem::appendItem(QString text)
{
    emit preItemAppended();

    Item item;
    item.taskStatus = false;
    item.taskDescription = text;
    itemsList.append(item);


    //qDebug() << itemsList.length();

    for(int i = 0; i<itemsList.length(); i++)
    {
        qDebug() << itemsList[i].taskDescription;
    }
    qDebug() << "Enter appendItem function";

    emit postItemAppended();
}

void taskItem::removeItem()
{
    for (int i=0; i < itemsList.size();)
    {
        if (itemsList.at(i).taskStatus)
        {
            emit preItemRemoved(i);

            itemsList.removeAt(i);
        }
        else
        {
            ++i;
        }
    }
}

