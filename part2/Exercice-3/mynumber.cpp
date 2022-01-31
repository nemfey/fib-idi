#include "mynumber.h"

mynumber::mynumber(QWidget *parent=0) : QLCDNumber(parent)
{
	res = 0;
}

void mynumber::getResult(int v)
{
	res = value();
	res += v;
	
	display(res);
}

void mynumber::newResult()
{
	res = 0;
}

void mynumber::resetResult()
{
	newResult();
	display(res);
}
