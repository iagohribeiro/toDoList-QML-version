#ifndef TASKITEM_H
#define TASKITEM_H

#include <QObject>
#include <QVector>

struct Item
{
    bool taskStatus;
    QString taskDescription;
};

class taskItem : public QObject
{
    Q_OBJECT
public:
    explicit taskItem(QObject *parent = nullptr);

    QVector<Item> items() const;

    bool setItem(int index, const Item &item);

signals:
   void preItemAppended();
   void postItemAppended();

   void preItemRemoved(int index);
   void postItemRemoved();

public slots:
   void appendItem(QString text);
   void removeItem();


private:
   QVector<Item> itemsList;

};

#endif // TASKITEM_H
