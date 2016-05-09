/*
 * Stopwatch.cpp
 */
#include <iostream>
#include <fstream>
#include <sys/time.h>
using namespace std;
#include "Stopwatch.h"


/**
 * konstruktor
 */
Stopwatch::Stopwatch() {
	start_=0;
	stop_=0;
	RunTime_=0;
}
/**
 * destruktor
 */
Stopwatch::~Stopwatch() {
}
/**
 * funkcja zwracajaca czas wykonania
 * @return RunTime_
 */
double Stopwatch::getRunTime()
{
	setRunTime();
	return RunTime_;
}
/**
 * funkcja obliczajaca czas wykonania algorytmu
 */
void Stopwatch::setRunTime()
{
	RunTime_=float(stop_-start_);		//double czas_wyk1 = float(koniec-start)/CLOCKS_PER_SEC;
}
/**
 * funkcja zapisujaca pomiar w pliku
 * @param number - liczba elementow dla ktorych dzialal algorytm
 */
void Stopwatch::sendToFile(int number)
{
	FILE *pFile;
	pFile=fopen("data.txt","a");		//otwiera plik do dopisywania (jesli nie istnieje, to go tworzy)
	fprintf (pFile, "%.8f sek\t %d\n", RunTime_, number );
	fclose(pFile);

}
/**
 * funkcja zwracajaca czas rozpoczecia pomiaru
 * @return start_
 */
double Stopwatch::getStart()
{
	return start_;
}
/**
 * funkcja wlaczajaca stoper
 */
void Stopwatch::setStart()
{
	gettimeofday(&time, NULL);
	start_=time.tv_sec+(time.tv_usec/1000000.0);;
}
/**
 * funkcja zwracajaca czas zakonczenia pomiaru
 * @return stop_
 */
double Stopwatch::getStop()
{
	setStop();
	return stop_;
}
/**
 * funkcja wylaczajaca stoper
 */
void Stopwatch::setStop()
{
	gettimeofday(&time, NULL);
	stop_=time.tv_sec+(time.tv_usec/1000000.0);
}
