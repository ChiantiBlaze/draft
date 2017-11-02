#include "letter-counter.h"
#include <iostream>
#include <QLabel>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>

using namespace std;

LetterCounter::LetterCounter(QWidget *parent) : QWidget(parent)
{
	/* components */
	QTextEdit *textarea = new QTextEdit(this);
	QLabel *total_words = new QLabel("0 words  ", this);
	QLabel *total_letters = new QLabel("0 letters", this);
	QLabel *empty_area = new QLabel("", this); /* for stretching */


	/* apply grid layout */
	QGridLayout *grid = new QGridLayout(this);
	
	grid->addWidget(textarea, 0,0,1,100);
	grid->addWidget(empty_area, 15,0,1,98);
	grid->addWidget(total_words, 15,98,1,1);
	grid->addWidget(total_letters, 15,99,1,1);

	setLayout(grid);

	/* connect counting functions */
	connect(textarea, &QTextEdit::textChanged, this,[=](){
		string text = textarea->toPlainText().toStdString();

		/* update counters */
		string updated_letters = to_string(this->utf8_strlen(text))+" letters";

		total_letters->setText(QString::fromStdString(updated_letters));
	});
}

int LetterCounter::utf8_strlen(string text)
{
	/* utf8 length calculation code from http://www.zedwood.com/article/cpp-utf8-strlen-function */
    int c,i,ix,q;
    for (q=0, i=0, ix=text.length(); i < ix; i++, q++)
    {
        c = (unsigned char) text[i];
        if      (c>=0   && c<=127) i+=0;
        else if ((c & 0xE0) == 0xC0) i+=1;
        else if ((c & 0xF0) == 0xE0) i+=2;
        else if ((c & 0xF8) == 0xF0) i+=3;
        else return 0;
    }
    return q;
}