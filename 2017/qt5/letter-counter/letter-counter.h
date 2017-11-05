#ifndef LETTER_COUNTER_H
#define LETTER_COUNTER_H

#include <QWidget>
#include <iostream>

class LetterCounter : public QWidget
{
public:
	LetterCounter(QWidget *parent=0);
	int utf8_strlen(std::string text);
};

#endif