#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QVariant>
#include <QtDebug>

class MyClass : public QObject
{
    Q_OBJECT
public slots:
    void cppSlot(const QVariant&);
};

#endif // MYCLASS_H
