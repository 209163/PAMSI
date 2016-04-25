/*
 * main.cpp
 *
 *  Created on: 18 kwi 2016
 *      Author: paula
 */

#include <iostream>
#include <cctype>

#include "BinarySearchTree.h"
#include "BSTtest.h"

using namespace std;

//int index=0;
//int *tree=new int[20];
//int *tmp=new int[20];
//int dane[16];
//    bool pusty[16];
//    int wybor;
//    int *korzen;


//void divide(int *tab, int left, int right);
int main()
{

BSTtest test1;
test1.run();









	return 0;
}
//void divide(int *tab, int left, int right)
//{
//
//	  //gdy mamy jeden element, to jest on już posortowany
//	  if(right<=left) return;
//
//	  //znajdujemy srodek podtablicy
//	  int srodek = (right+left)/2;
//	  tmp[index]=tab[srodek];
//	  //cout<<tmp[index]<<" ";			//zapis kolejnych srodkow do tablicy
//	  index++;
//	  //dzielimy tablice na częsć lewą i prawa
//	  divide(tab, left, srodek);
//	  divide(tab, srodek+1, right);
//
//}
//
//void add()
//{
//    int liczba;
//    cout<<"Jaka liczbe dodac do drzewa: ";
//    liczba=tmp[1];
//
//    //drzewo puste
//    if (pusty[1]==true)
//    {
//        korzen=&dane[1];
//        *korzen=liczba;
//        pusty[1]=false;
//    }
//    else //drzewo niepuste
//    {
//    bool znalazlem_miejsce=false;
//    int wezel=1;
//
//    while (znalazlem_miejsce==false)
//    {
//        if (pusty[wezel]==true)
//        {
//            znalazlem_miejsce=true;
//            dane[wezel]=liczba;
//            pusty[wezel]=false;
//
//        }
//        else if(liczba<dane[wezel])
//        {
//            //w lewo
//            wezel=2*wezel;
//        }
//        else
//        {
//            //w prawo
//            wezel=2*wezel+1;
//        }
//        if(wezel>15)
//        {
//            cout<<"Potrzebne byloby wieksze drzewo!";
//
//            znalazlem_miejsce=true;
//        }
//    }
//    }
//
//}

