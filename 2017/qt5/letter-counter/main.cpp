#include "letter-counter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	LetterCounter window;

	window.resize(500, 300);
	window.setWindowTitle("Letter Counter");
	window.show();

	return app.exec();
}