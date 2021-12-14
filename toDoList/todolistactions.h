#ifndef TODOLISTACTIONS_H
#define TODOLISTACTIONS_H

#include <QObject>

class toDoListActions : public QObject
{
    Q_OBJECT
public:
    explicit toDoListActions(QObject *parent = nullptr);
    void editCheckBox();

signals:

};

#endif // TODOLISTACTIONS_H
