#include "bert.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Bert w;
	w.show();

	return a.exec();
}
