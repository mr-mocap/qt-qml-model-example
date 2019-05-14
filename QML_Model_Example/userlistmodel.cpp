#include "userlistmodel.h"
#include <QQmlEngine>

User::User(const QString &name, const QString &occupation)
    :
    _name(name),
    _occupation(occupation)
{
}

QString User::name() const
{
    return _name;
}

QString User::occupation() const
{
    return _occupation;
}

bool User::operator==(const User &other_user) const
{
    return (other_user.name() == _name) && (other_user.occupation() == _occupation);
}

void UserListModel::RegisterQMLType()
{
    qmlRegisterUncreatableType<UserListModel>("MyApp.Models", 1, 0, "UserListModel", "Type cannot be created in QML");
}

UserListModel::UserListModel(QObject *parent)
    :
    QAbstractListModel(parent)
{
}

void UserListModel::appendUser(const User &user)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    _users << user;
    endInsertRows();
}

void UserListModel::removeUser(const User &user)
{
    Q_UNUSED(user);

    int pos = _users.indexOf(user);

    if (pos >= 0)
    {
        beginRemoveRows(QModelIndex(), pos, pos);
        _users.removeAt(pos);
        endRemoveRows();
    }
}

int UserListModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return _users.count();
}

QVariant UserListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _users.count())
        return QVariant();

    const User &user = _users[index.row()];

    if (role == NameRole)
        return user.name();
    else if (role == OccupationRole)
        return user.occupation();
    return QVariant();
}

QHash<int, QByteArray> UserListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[NameRole] = "name";
    roles[OccupationRole] = "occupation";
    return roles;
}
