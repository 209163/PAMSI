/*
 * Dictionary.h
 *
 *  Created on: 19 mar 2016
 *      Author: paula
 */



#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include <string>
using namespace std;
#define AMOUNT_OF_WORDS 99171
#define HASH_AMOOUNT_OF_SIGNS 5
#define MAX_HEX_ASCII_CODE 127
#include "LinkedList.h"

/**
 * @brief Klasa tworzy tablicy asocjacyjną - słownik
 *
 * Tworzy tablice asocjacyjną, na podstawie kluczba podanego przez operator []
 * Gdy element o danym kluczu nie istnieje, a uzytkownik probuje sie do niego odwolac
 * to dany element jest tworzony i dodawany do tablicy
 */

class Dictionary {
private:

	/**
	 * @brief Tablica list
	 */
	LinkedList *columnList;
public:
	/**
	 * @brief Konstruktor tworzacy kolumneList
	 * Tworze 367 miejsc bo mam tylko trzy pierwsze znaki uzywane przy hashowaniu
	 */
	Dictionary();
	virtual ~Dictionary();
	/**
	 * funkcja wczytujaca slownik do tablicy
	 */
	void setWords();			//wpisuje slowa z pliku "words.txt" do tablicy words_[99171]
	/**
	 * funkcja zwracajaca slowo z tablicy z wyrazami ze slownika
	 * @param i - numer indeksu zwracanego slowa
	 * @return words_[i]
	 */
	string getWords(int i);		//zwraca i-ty element tablicy words_[]
	/**
	 * funkcja zliczajaca linie w pliku (ilosc slow w slowniku)
	 * @return lines
	 */
	int countLines();			//zapisuje do lines_ liczbe linni w pliku
	/**
	 * funkcja generujaca losowe slowa na podstawie slownika
	 * @return
	 */
	string RandomWords();     		//generuje losowe slowo ze slownika
	/**
	 * funkcja generujaca losowe liczby
	 * @return
	 */
	int RandomNumber();
	/**
	 * @brief Operator pozwalajacy odnosic sie do slownika
	 * Gdy element o danym kluczu nie istnieje, a użytkownik próbuje sie do niego odwołać
	 * to dany element jest tworzony i dodawany do tablicy
	 *
	 * @param str Klucz elementu do odwolania
	 */
	int &operator[](string str);
	/**
	 * @brief Funkcja hashująca trzy pierwsze znaki
	 * @param str Obiekt string do zhashowania
	 */
	int str2int(string str);
	static int orderAlphabeticChecking(string str_1, string str_2);
private:
	string words_[AMOUNT_OF_WORDS];
	string randomWord_;
	//int size_;						//poczatkowy rozmiar slownika


};

#endif /* DICTIONARY_H_ */
