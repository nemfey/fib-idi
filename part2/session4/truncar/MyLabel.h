#include <QLabel>
#include <iostream>

class MyLabel: public QLabel {
	Q_OBJECT
	
public:
	MyLabel (QWidget *parent);
	
public slots:
	void TruncarLabel (int);
};
