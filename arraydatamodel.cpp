#include "arraydatamodel.h"

ArrayDataModel::ArrayDataModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

ArrayDataModel::ArrayDataModel(const QList<QVariant> &other, QObject *parent)
{
}

ArrayDataModel::~ArrayDataModel()
{
    mDatas.clear();
}


void ArrayDataModel::append(const QVariantList &values)
{
    beginInsertRows(QModelIndex(),0, values.count());
    mDatas.prepend(values);
    endInsertRows();
}

void ArrayDataModel::append(const QVariant &value)
{
    beginInsertRows(QModelIndex(),0, 0);
    mDatas.prepend(value);
    endInsertRows();
}

void ArrayDataModel::clear()
{
    beginResetModel();
    mDatas.clear();
    endResetModel();
}


int ArrayDataModel::indexOf(const QVariant &value, int from) const
{

    for (int i=from; i< mDatas.count(); ++i)
    {
        if (mDatas[i] == value)
            return i;
    }

    return -1;
}

void ArrayDataModel::insert(int i, const QVariantList &values)
{

    beginInsertRows(QModelIndex(), i, values.count());

    foreach (QVariant value, values)
        mDatas.insert(i, value);

    endInsertRows();

}

void ArrayDataModel::insert(int i, const QVariant &value)
{
    beginInsertRows(QModelIndex(), i, i);
    mDatas.insert(i, value);
    endInsertRows();
}

bool ArrayDataModel::isEmpty() const
{
    return mDatas.isEmpty();
}

void ArrayDataModel::move(int from, int to)
{
    //Mieux faire ?
    beginResetModel();
    mDatas.move(from, to);
    endResetModel();
}

void ArrayDataModel::removeAt(int i)
{
    beginRemoveRows(QModelIndex(),i,i);
    mDatas.removeAt(i);
    endRemoveRows();
}

void ArrayDataModel::replace(int i, const QVariant &value)
{
    mDatas.replace(i, value);
    emit dataChanged(index(i), index(i));
}

int ArrayDataModel::size() const
{
    return mDatas.size();
}

void ArrayDataModel::swap(int i, int j)
{
    //peu mieux faire
    beginResetModel();
    mDatas.swap(i,j);
    endResetModel();
}

QVariant ArrayDataModel::value(int i) const
{
    return mDatas.value(i);
}

QVariant ArrayDataModel::value(int i, const QVariant &defaultValue) const
{
    return mDatas.value(i, defaultValue);
}


QVariant ArrayDataModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return mDatas.at(index.row());

    return QVariant();


}
int ArrayDataModel::rowCount(const QModelIndex &parent) const
{
    return mDatas.count();
}
