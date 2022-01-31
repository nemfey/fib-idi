#include "mylabel.h"

mylabel::mylabel(QWidget *parent=0): QLabel(parent)
{
	value = 0;
	
	setStyleSheet("background:rgb(0, 255, 0);");
}

void mylabel::increase()
{
	bool next;
	QString str;
	getValue();
	
	if(text()=="0") 
	{
		setText("1");
		next = false;
		
		str = "background:rgb(255, 255, 0);";
		emit sendValue(value);
	}
	else
	{
		setText("0");
		next = true;
		
		str = "background:rgb(0, 255, 0);";
		emit sendValue(-value);
	}
	
	setStyleSheet(str);
	
	if(next) emit increaseNext();	
}

void mylabel::labelToZero()
{
	QString str;
	
	setText("0");
	str = "background:rgb(0, 255, 0);";
	setStyleSheet(str);
	
	value = 0;
}

void mylabel::getValue()
{
	if(objectName()=="label_7") value = pow(2,2)*10;
	else if(objectName()=="label_2") value = pow(2,1)*10;
	else if(objectName()=="label_3") value = pow(2,0)*10;
	
	else if(objectName()=="label_4") value = pow(2,2);
	else if(objectName()=="label_5") value = pow(2,1);
	else if(objectName()=="label_6") value = pow(2,0);
}
