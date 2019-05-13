#include "listmodel1type.h"
#include <QQmlEngine>

void ListModel1Type::RegisterQMLType()
{
    qmlRegisterUncreatableType<ListModel1Type>("", 1, 0, "ListModel1Type", "Type cannot be created in QML");
}

ListModel1Type::ListModel1Type(QObject *parent) : QObject(parent)
{
}

ListModel1Type::ListModel1Type(const QString &name, const QString &occupation)
    :
    QObject(nullptr),
    _name(name),
    _occupation(occupation)
{
}

QString ListModel1Type::name() const
{
    return _name;
}

QString ListModel1Type::occupation() const
{
    return _occupation;
}

void ListModel1Type::setOccupation(const QString &new_occupation)
{
    if (new_occupation != _occupation)
    {
        _occupation = new_occupation;
        emit occupationChanged();
    }
}
