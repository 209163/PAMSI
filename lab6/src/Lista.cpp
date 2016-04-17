/*
 * Lista.cpp
 *
 *  Created on: 18 mar 2016
 *      Author: paula
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#define SIZE 2

using namespace std;

#include "Lista.h"
/**
 * konstruktor
 */
///size_=SIZE	- poczatkowy rozmiar listy
///	count_		- liczba elementow na liscie
///	end_=0;
///	name_ = 	- tablica przechowujaca dodane elementy
///	next_=		- tablica przechowujaca indeks nastepnego elementu na liscie

Lista::Lista() {

	size_=SIZE;				//poczatkowy rozmiar tablicy
	count_=0;				//liczba dodanych elementow
	end_=0;
	name_ = new string[size_];
	next_=new int[size_];
	name_[0]="-";			//pierwszy element
	next_[0]=1;

}

/**
 * destruktor
 */
Lista::~Lista() {
	delete [] name_;
	delete [] next_;
}

/**
 * funkcja zwracajaca aktualny rozmiar listy
 * @return size_
 */
int Lista::getSize()
{
    //cout<<"aktualny rozmiar  tablicy: "<<count_<<endl;
    return size_;
}

//
//void Lista::enlarge_by1()
//{
//    if(size_==count_)
//    {
//        size_++;
//        string *tmp1= new string[size_];
//        int *tmp2= new int[size_];
//        for(int i=0; i<count_;i++)
//        {
//            tmp1[i]=name_[i];      //przepisuje dane ze starej tablicy do nowej
//            tmp2[i]=next_[i];
//        }
//        delete [] name_;
//        delete [] next_;
//        name_ =tmp1;
//        next_ =tmp2;
//    }
//
//}
/**
 * funkcja zwiekszajaca rozmiar tablicy dwukrotnie
 */
 void Lista::enlarge_x2()
{
    if(size_==(count_+1) )
    {
        size_=size_*2;
        string *tmp1= new string[size_];
        int *tmp2= new int[size_];
        for(int i=0; i<=count_;i++)
        {
            tmp1[i]=name_[i];      //przepisuje dane ze starej tablicy do nowej
            tmp2[i]=next_[i];
        }
        delete [] name_;
        delete [] next_;
        name_ =tmp1;
        next_=tmp2;
    }

}

// void Lista::enlarge_x3()
//   {
//       if(size_==count_ )
//       {
//           size_=size_*3;
//           string *tmp1= new string[size_];
//           int *tmp2= new int[size_];
//           for(int i=0; i<count_;i++)
//           {
//               tmp1[i]=name_[i];      //przepisuje dane ze starej tablicy do nowej
//               tmp2[i]=next_[i];
//           }
//           delete [] name_;
//           delete [] next_;
//           name_ =tmp1;
//           next_ =tmp2;
//       }
//
//   }

/**
 * funkcja dodajaca element w dowolnym miejscu w tablicy
 * @param item - element, ktory mam zostac dodany
 * @param position - indeks elementu, po ktorym ma zostac dodany item
 */
 void Lista::add(string item, int position)				///position - indeks elementu po ktorym mamy wstawic
 {
	 enlarge_x2();
//	 if(position==count_)
//		 end_=position;
	 if(free_.isEmpty()==0)
	 {
		 name_[free_.getFront()]=item;
		 next_[free_.getFront()]=next_[position];
		 next_[position]=free_.getFront();
		 free_.dequeue();
	 }
	 else
	 {
		 if(position==count_)
		 {
			 name_[count_+1]=item;
		 	 next_[count_+1]=0;
		 	 next_[position]=count_+1;
		 }
		 else
		 {
			 name_[count_+1]=item;
			 next_[count_+1]=next_[position];
			 next_[position]=count_+1;
		 }
	 }
	 count_++;

 }


/**
 * funkcja usuwajaca dowolny element z listy
 * @param index - nr indeksu elementu, ktory ma zostac usuniety
 */
void Lista::remove(int index)
{
	for (int i=0; i<=count_+1;i++)
	{
		if(next_[i]==index)
		{
			next_[i]=next_[next_[i]];
			free_.enqueue(index);
		}

	}
	count_--;
}

/**
 * funkcja wyswietlajaca elementy z tablic name_ i next_ o okreslonym indeksie
 * @param i - nr indeksu do wyswietlenia
 */
 void Lista::display(int i)				///wyswietla nazwe obiektu i numer indeksu obiektu, na ktory pokazuje jako nastepny
     {
             cout<<name_[i]<<" ";
             cout<<next_[i]<<endl;
     }

//void Lista::displayFree()
//{
//	free_.display();
//}
/**
 * funkcja przeszukujaca tablice stringow
 * @param item - szukane slowo
 * @return - zwraca nr indeksu szukanego slowa lub -1, jezeli nie znaleziono
 */
 int Lista::find(string item)
 {
	 	 for (int i=0; i<count_; i++)
	 	 {
	 		 	if(name_[next_[i]]==item)
	 		 	{
	 		 		return next_[i];						//zwraca numer indeksu szukanego slowa
	 		 	}
	 	 }
	 	 return -1;  				//jezeli slowa nie znaleziono
 }
/**
 * funkcja zwracajaca element z tablicy next_
 * @param index - numer indeksu elementu
 * @return
 */
 int Lista::getNext(int index)
 {
	return next_[index] ;
 }
 /**
  * funkcja zwracajaca element z tablicy name_
  * @param index - nr indeksu zwracanego elementu
  * @return
  */
 string Lista::getName(int index)
 {
	 return name_[index];
 }
/**
 * funkcja zwracajaca liczbe elementow w tablicy
 * @return
 */
 int Lista::getCount()
 {
	 return count_;
 }
