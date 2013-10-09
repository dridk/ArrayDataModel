ArrayDataModel
==============

ArrayDataModel for Qt. Same than blackberry 10 API but based on QAbstractItemModel

## API 
### public slots
* void	append (const QVariantList &values);
* void	append (const QVariant &value);
* void	clear ();
* void	insert (int i, const QVariantList &values);
* void	insert (int i, const QVariant &value);
* void	move (int from, int to);
* void	removeAt (int i);
* void	replace (int i, const QVariant &value);
* void	swap (int i, int j);

### public invokable
* int	indexOf (const QVariant &value, int from=0) const;
* bool	isEmpty () const;
* int	size () const;
* QVariant	value (int i) const;
* QVariant	value (int i, const QVariant &defaultValue) const;

## EXAMPLE 
  
    
    int main(int argc, char **argv)
    {
      QApplication app(argc,argv);
      QListView * view = new QListView;
      ArrayDataModel * model = new ArrayDataModel;
      view->setModel(model);
      view->show();
      model->append("salut");
      model->append(54);
      model->append(QDate::currentDateTime());
      app.exec();
    }
