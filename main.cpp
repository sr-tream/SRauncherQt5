#include "srauncher.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SRauncher w;
	w.show();

	return a.exec();
}
