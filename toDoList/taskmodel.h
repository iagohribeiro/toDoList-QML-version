#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QAbstractListModel>

class taskItem;

class taskModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(taskItem *list READ list WRITE setList)
public:
    explicit taskModel(QObject *parent = nullptr);

    enum {
        doneTask = Qt::UserRole,
        descriptionTask
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> taskNames();

    taskItem *list() const;
    void setList(taskItem *newTaskList);

private:
    taskItem *taskList;
};

#endif // TASKMODEL_H
