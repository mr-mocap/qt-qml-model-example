#include "application.h"
#include <QQmlEngine>
#include <QStringList>
#include <QQuickWindow>
#include "listmodel1type.h"


void Application::RegisterQMLType()
{
    qmlRegisterType<Application>("MyApp", 1, 0, "Application");

    /* Let's go ahead and just register ALL the types that this class can use */
    ListModel1Type::RegisterQMLType();
    UserListModel::RegisterQMLType();
}

Application::Application(QObject *parent)
    :
    QObject(parent),
    _user_list_model(new UserListModel(parent))
{
    {
        QQuickWindow *recast = qobject_cast<QQuickWindow *>(parent);

        if (recast)
        {
            qInfo() << "Object Name: " << recast->objectName();
        }
    }

    _simple_string_list_model = _generateInitialSimpleStringListModel();

    /* Initialize _list_model_1 member here, typically because
     * we may need to have the rest of the class initialized before
     * we retrieve the data (from possibly elsewhere in the class.
     */
    _list_model_1 = _generateInitialListModel1();

    _generateInitialUserListModel();
}

QVariant Application::simpleStringListModel() const
{
    return QVariant::fromValue(_simple_string_list_model);
}

QVariant Application::listModel1() const
{
    return QVariant::fromValue(_list_model_1);
}

UserListModel &Application::userListModel()
{
    return _user_list_model;
}

QPointer<UserListModel> Application::_qmlUserListModel()
{
    return QPointer<UserListModel>(&_user_list_model);
}

void Application::deleteQObjectsInList(QList<QObject *> &objects_to_delete)
{
    for (QObject *iObject : objects_to_delete)
    {
        delete iObject; // NOTE: dangling pointer now!
    }
}

void Application::regenerateSimpleStringListModel()
{
    // We can just do this reassignment because the underlying type is QString.
    _simple_string_list_model = _generateInitialSimpleStringListModel();

    emit simpleStringListModelChanged();
}

QStringList Application::_generateInitialSimpleStringListModel()
{
    return { "SimpleStringModelItem #1", "SimpleStringModelItem #2", "SimpleStringModelItem #3"};
}

QList<QObject *> Application::_generateInitialListModel1() const
{
    QList<QObject *> retval;

    retval.append(new ListModel1Type("Lee", "Team Lead"));
    retval.append(new ListModel1Type("Vaughn", "Wizard"));
    retval.append(new ListModel1Type("David H", "App Developer"));
    retval.append(new ListModel1Type("David K", "Audio/Visual"));

    for (QObject *iObject : retval)
    {
        ListModel1Type *lmt = qobject_cast<ListModel1Type *>(iObject);

        // Connect each object's occupationChanged signal to be handled by THIS class.
        lmt->connect(lmt, &ListModel1Type::occupationChanged,
                     this, &Application::_listModel1ItemChanged);
    }
    return retval;
}

void Application::_listModel1ItemChanged()
{
    // Let's just emit a signal to let QML know that the underlying list has somehow changed.
    emit listModel1Changed();
}

void Application::_generateInitialUserListModel()
{
    _user_list_model.appendUser( { "UserListModel Lee", "Team Lead" } );
    _user_list_model.appendUser( { "UserListModel Vaughn", "Wizard" } );
    _user_list_model.appendUser( { "UserListModel David H", "App Developer" } );
    _user_list_model.appendUser( { "UserListModel David K", "Audio/Visual" } );
}
