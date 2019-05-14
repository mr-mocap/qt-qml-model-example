#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QList>
#include <QPointer>
#include "userlistmodel.h"

/** This represents our main application object.
 *
 *  This will contain various sub-models for use
 *  in the entire application.
 */
class Application : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariant listModel1            READ listModel1             NOTIFY listModel1Changed)
    Q_PROPERTY(QVariant simpleStringListModel READ simpleStringListModel  NOTIFY simpleStringListModelChanged)
    Q_PROPERTY(QPointer<UserListModel> userListModel READ _qmlUserListModel)
public:
    explicit Application(QObject *parent = nullptr);

    static void RegisterQMLType();

    void deleteQObjectsInList(QList<QObject *> &objects_to_delete);

    QVariant simpleStringListModel() const;

    void regenerateSimpleStringListModel();

    /** Represents a ListModel of type ListModel1Type.
     *
     *  @returns QVariant (QList<QObject *>)
      */
    QVariant listModel1() const;

    UserListModel &userListModel();

signals:
    void simpleStringListModelChanged();
    void listModel1Changed();

public slots:

protected:
    QStringList      _simple_string_list_model;
    QList<QObject *> _list_model_1;
    UserListModel _user_list_model;

    QStringList _generateInitialSimpleStringListModel();
    QList<QObject *> _generateInitialListModel1() const;
    void _generateInitialUserListModel();

    QPointer<UserListModel> _qmlUserListModel();
protected slots:
    void _listModel1ItemChanged(); ///< When an individual ListModel1Type item changed in the list
};

#endif // APPLICATION_H
