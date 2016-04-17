/*
 * SortingAlg.cpp
 *
 *  Created on: 27 mar 2016
 *      Author: paula
 */

#include "SortingAlg.h"
#include <algorithm>
using namespace std;

SortingAlg::SortingAlg() {


}

SortingAlg::~SortingAlg() {

}
/**
 * funkcja sortujaca wykorzystujaca sortowanie babelkowe
 * @param tab - wskaznik do tablicy, ktorej elementy maja zostac posortowane
 * @param n - rozmiar tablicy
 */
void SortingAlg::bubble(int *tab, int n)
{
	for(int j=1;  j<(n-1); j++)
	{
		for (int i=0; i<n-2;i++)
		{
			if(tab[i]>tab[i+1])
			{
				swap(tab[i], tab[i+1]);
			}
		}
	}
}
