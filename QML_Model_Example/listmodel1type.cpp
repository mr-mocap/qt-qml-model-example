#include "listmodel1type.h"
#include <QQmlEngine>

void ListModel1Type::RegisterQMLType()
{
    qmlRegisterUncreatableType<ListModel1Type>("", 1, 0, "ListModel1Type", "Type cannot be created in QML");
}

ListModel1Type::ListModel1Type(QObject *parent) : QObject(parent)
{
}

ListModel1Type::ListModel1Type(const QString &name)
    :
    QObject(nullptr),
    _name(name)
{
}


QString ListModel1Type::name() const
{
    return _name;
}
