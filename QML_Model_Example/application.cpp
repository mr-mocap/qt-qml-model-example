#include "application.h"
#include <QQmlEngine>
#include <QStringList>
#include "listmodel1type.h"


void Application::RegisterQMLType()
{
    qmlRegisterType<Application>("MyApp", 1, 0, "Application");

    /* Let's go ahead and just register ALL the types that this class can use */
    ListModel1Type::RegisterQMLType();
}

Application::Application(QObject *parent) : QObject(parent)
{
    _simple_string_list_model = _generateInitialSimpleStringListModel();

    /* Initialize _list_model_1 member here, typically because
     * we may need to have the rest of the class initialized before
     * we retrieve the data (from possibly elsewhere in the class.
     */
    _list_model_1 = _generateInitialListModel1();
}

QVariant Application::simpleStringListModel() const
{
    return QVariant::fromValue(_simple_string_list_model);
}

QVariant Application::listModel1() const
{
    return QVariant::fromValue(_list_model_1);
}

QStringList Application::_generateInitialSimpleStringListModel()
{
    return { "SimpleStringModelItem #1", "SimpleStringModelItem #2", "SimpleStringModelItem #3"};
}

QList<QObject *> Application::_generateInitialListModel1() const
{
    QList<QObject *> retval;

    retval.append(new ListModel1Type("Lee"));
    retval.append(new ListModel1Type("Vaughn"));
    retval.append(new ListModel1Type("David H"));
    retval.append(new ListModel1Type("David K"));

    return retval;
}
