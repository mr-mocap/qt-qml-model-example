#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QList>

/** This represents our main application object.
 *
 *  This will contain various sub-models for use
 *  in the entire application.
 */
class Application : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariant listModel1            READ listModel1)
    Q_PROPERTY(QVariant simpleStringListModel READ simpleStringListModel)
public:
    explicit Application(QObject *parent = nullptr);

    static void RegisterQMLType();

    QVariant simpleStringListModel() const;

    /** Represents a ListModel of type ListModel1Type.
     *
     *  @returns QVariant (QList<QObject *>)
      */
    QVariant listModel1() const;
signals:

public slots:

protected:
    QStringList      _simple_string_list_model;
    QList<QObject *> _list_model_1;

    QStringList _generateInitialSimpleStringListModel();
    QList<QObject *> _generateInitialListModel1() const;
};

#endif // APPLICATION_H
