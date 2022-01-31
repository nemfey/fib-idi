#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent)
	: QLabel(parent) {
		//connect(this,SIGNAL(returnPressed()),this,SLOT(tractaReturn()));
}

void MyLabel::TruncarLabel (int n) {
	QString str = text();
	//int aux = str.size() - (str.size()*n /10);
	//str.truncate(aux);
	str.truncate(n);
	setText(str);
}
