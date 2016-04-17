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

//#define SIZE 99171						//poczatkowy rozmiar slownika

using namespace std;
#include "Dictionary.h"

Dictionary::Dictionary() {
	columnList=new LinkedList[HASH_AMOOUNT_OF_SIGNS * MAX_HEX_ASCII_CODE+1];

}

Dictionary::~Dictionary() {

}


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


int Dictionary::RandomNumber()				//generuje losowy numer od 0 do liczby linii w pliku
{
	int r;
	int amount=countLines();
	r=(rand() % (amount-1));
	return r;
}

string Dictionary::RandomWords()
{
	string rW;
	int i=RandomNumber();
	rW=getWords(i);							//pobiera i-ty (randomowy) wyraz z tablicy
	return rW;
}


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

string Dictionary::getWords(int i)
{
	return words_[i];
}

int Dictionary::str2int(string str)
{
	int hash=0;
	for (unsigned int i=0; (i<HASH_AMOOUNT_OF_SIGNS && i<str.size()); i++)
		hash+=(int)str[i];
	return hash;

}

int &Dictionary::operator[](string str)
{
	int id=str2int(str);
	for(int i=0; i<columnList[id].size();i++)
	{
		if(!(columnList[id][i].name.compare(str)))		//znaleziono taki sam klucz w slowniku
			return columnList[id][i].number;
	}
	LinkedList::LinkedListElement elementToAdd;
	elementToAdd.name=str;
	columnList[id].push_back(elementToAdd);
	return columnList[id].show_back().number;
}

int Dictionary::orderAlphabeticChecking(string str_1, string str_2)
{
	unsigned int wordLength=str_1.size();
	if(str_2.size() < str_1.size())
		wordLength=str_2.size();
	for(unsigned int i=0; i<wordLength;i++)
	{
		if((int)str_1[i]>(int)str_2[i]) return 2;
		if((int)str_1[i]<(int)str_2[i]) return 1;
	}
	if((int)str_1.size()>(int)str_2.size()) return 2;
	if((int)str_1.size()<(int)str_2.size()) return 1;
	else return 0;
}
