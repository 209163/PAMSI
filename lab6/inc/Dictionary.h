/*
 * Dictionary.h
 *
 *  Created on: 19 mar 2016
 *      Author: paula
 */

#include <string>
using namespace std;
#define AMOUNT_OF_WORDS 99171

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

class Dictionary {
public:
	Dictionary();
	virtual ~Dictionary();
	void setWords();			//wpisuje slowa z pliku "words.txt" do tablicy words_[99171]
	string getWords(int i);		//zwraca i-ty element tablicy words_[]
	int countLines();			//zapisuje do lines_ liczbe linni w pliku
	string RandomWords();     		//generuje losowe slowo ze slownika
	int RandomNumber();
private:
	string words_[AMOUNT_OF_WORDS];
	string randomWord_;
	//int size_;						//poczatkowy rozmiar slownika


};

#endif /* DICTIONARY_H_ */
