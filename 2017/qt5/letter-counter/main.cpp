/**
 * @author	Chianti Blaze
 * @date	11/3/2017
 * @section	DESCRIPTION
 *
 * Simple letter counter application.
 *
 */

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