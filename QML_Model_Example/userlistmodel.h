#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>
#include <QString>

class User
{
public:
    User(const QString &name, const QString &occupation);

    QString name() const;
    QString occupation() const;

    bool operator ==(const User &other_user) const;
protected:
    QString _name;
    QString _occupation;
};

class UserListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum UserRoles {
        NameRole = Qt::UserRole + 1,
        OccupationRole
    };

    UserListModel(QObject *parent = nullptr);

    static void RegisterQMLType();

    void appendUser(const User &user);
    void removeUser(const User &user);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
protected:
    Q_DISABLE_COPY(UserListModel)

    QList<User> _users;

    QHash<int, QByteArray> roleNames() const;
};

#endif // USERLISTMODEL_H
