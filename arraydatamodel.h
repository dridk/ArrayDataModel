#ifndef ARRAYDATAMODEL_H
#define ARRAYDATAMODEL_H

#include <QAbstractListModel>

class ArrayDataModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ArrayDataModel(QObject *parent = 0);
    ArrayDataModel (const QList< QVariant > &other, QObject *parent=0);
    virtual	~ArrayDataModel ();

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;

    Q_SLOT void	append (const QVariantList &values);
    Q_SLOT void	append (const QVariant &value);
    Q_SLOT void	clear ();
    Q_INVOKABLE int	indexOf (const QVariant &value, int from=0) const;
    Q_SLOT void	insert (int i, const QVariantList &values);
    Q_SLOT void	insert (int i, const QVariant &value);
    Q_INVOKABLE bool	isEmpty () const;
    Q_SLOT void	move (int from, int to);
    Q_SLOT void	removeAt (int i);
    Q_SLOT void	replace (int i, const QVariant &value);
    Q_INVOKABLE int	size () const;
    Q_SLOT void	swap (int i, int j);
    Q_INVOKABLE QVariant	value (int i) const;
    Q_INVOKABLE QVariant	value (int i, const QVariant &defaultValue) const;




private:
    QVariantList mDatas;
    
};

#endif // ARRAYDATAMODEL_H
