#ifndef LISTMODEL1TYPE_H
#define LISTMODEL1TYPE_H

#include <QObject>

class ListModel1Type : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name  READ name)
public:
    explicit ListModel1Type(QObject *parent = nullptr);
    explicit ListModel1Type(const QString &name);

    static void RegisterQMLType();

    /** Immutable value **/
    QString name() const;
signals:

public slots:

protected:
    QString _name;
};

#endif // LISTMODEL1TYPE_H
