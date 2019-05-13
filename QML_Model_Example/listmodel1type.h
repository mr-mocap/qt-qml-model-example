#ifndef LISTMODEL1TYPE_H
#define LISTMODEL1TYPE_H

#include <QObject>

class ListModel1Type : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name        READ name)
    Q_PROPERTY(QString occupation  READ occupation  WRITE setOccupation NOTIFY occupationChanged)
public:
    explicit ListModel1Type(QObject *parent = nullptr);
    explicit ListModel1Type(const QString &name, const QString &occupation);

    static void RegisterQMLType();

    /** Immutable value **/
    QString name() const;

    QString occupation() const;
    void    setOccupation(const QString &new_occupation);
signals:
    void occupationChanged();

public slots:

protected:
    QString _name;
    QString _occupation;
};

#endif // LISTMODEL1TYPE_H
