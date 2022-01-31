#include <QLCDNumber>

class mynumber: public QLCDNumber {
	Q_OBJECT
	
	public:
		mynumber(QWidget *parent);
		
		int res;
	
	public slots:
		void getResult(int v);
		void resetResult();
		void newResult();
};
