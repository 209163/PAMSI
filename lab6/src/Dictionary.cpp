/*
 * Dictionary.cpp
 *
 *  Created on: 19 mar 2016
 *      Author: paula
 */
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

//#define SIZE 99171						//poczatkowy rozmiar slownika (liczba slow = liczba linijek w pliku)

using namespace std;
#include "Dictionary.h"

Dictionary::Dictionary() {


}

Dictionary::~Dictionary() {

}

/**
 * funkcja zliczajaca linie w pliku (ilosc slow w slowniku)
 * @return lines
 */
int Dictionary::countLines()				//sprawdza ilosc slow (linii) w pliku
{
	int lines=0;
	fstream file;
	file.open("dictionary.txt", ios::in);
	string line;
	while(!file.eof()) {
	 getline(file,line);
	lines++;
	}
	lines--;
	file.close();
	return lines;
}

/**
 * funkcja generujaca losowe liczby
 * @return
 */
int Dictionary::RandomNumber()				//generuje losowy numer od 0 do liczby linii w pliku
{
	int r;
	int amount=countLines();
	r=(rand() % (amount-1));
	return r;
}
/**
 * funkcja generujaca losowe slowa na podstawie slownika
 * @return
 */
string Dictionary::RandomWords()
{
	string rW;
	int i=RandomNumber();
	rW=getWords(i);							//pobiera i-ty (randomowy) wyraz z tablicy
	return rW;
}

/**
 * funkcja wczytujaca slownik do tablicy
 */
void Dictionary::setWords()					//wczytuje slownik do tablicy
{
	fstream file;
	file.open("dictionary.txt", ios::in);
	if (file.good())
	{
		int s=0;
		s=countLines();

		for(int i=0;i<s;i++)
		{
			if(!file.eof())
			{
				getline(file, words_[i]);

			}
		}

	}
	file.close();
}
/**
 * funkcja zwracajaca slowo z tablicy z wyrazami ze slownika
 * @param i - numer indeksu zwracanego slowa
 * @return words_[i]
 */
string Dictionary::getWords(int i)
{
	return words_[i];
}

