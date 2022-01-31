#include <QLabel>
#include <math.h>

class mylabel: public QLabel
{
	Q_OBJECT
	
	public:
		mylabel(QWidget *parent);
		
		int value;
	
	public slots:
		void increase();
		void labelToZero();
		void getValue();
	
	signals:
		void increaseNext();
		void sendValue(int n);
};
