/**
 * Lista.h
Lista określona jest przez 2 tablice, ktore maja nazwy 'name' i 'next'.
Jeżeli 'element' jest indeksem do tych tablic, to 'name[element]' jest zapamietanym obiektem,
a 'next[element]' indeksem nastepnego obiektu na liscie, o ile nastepny istnieje.
 */

#ifndef LISTA_H_
#define LISTA_H_
#include <iostream>
#include <string>
#include "IArrayList.h"
#include "Queue.h"
#include "LinkedList.h"
#include <cstdlib>
#include <ctime>
#define SIZE 2
using namespace std;

template <class type>
class ArrayList : public IArrayList<type>
{
public:
	ArrayList();
	virtual ~ArrayList();
	void add(type item, int position);//dodaje element do listy (gdziekolwiek), item - dodawany element, position - indeks elementu listy, po ktorym ma byc wstawiony item
		//throw(EmptyListExeption);
	type getElem(int index);				//pobiera element ze wskazanego indeksu (bez usuwania)
		//throw(EmptyListExeption);
	/*wyjatki*/
	int getSize();      				//zwraca rozmiar tablicy
	void display(int i);    			//wyswietla zawartosc i-tego elem listy
	int findInArray(type item);				//przeszukuje liste
	int getNext(int index);
	type getName(int index);
	bool isEmpty();						//zwraca 1 gdy lista jest pusta
	void remove(int index);				//usuwa element o danym indeksie
	int getCount();
	void displayFree();

private:
	type *name_;     		//wskaznik do tablicy dynamicznej z zapamietanymi obiektami
    int *next_;				//wskaznik do tab dyn (kolejki) z indeksami nastepnych elementow
    Queue<type> free_;			//obiekt typu kolejka wolnych lokalizacji
    int size_;      		//aktualny rozmiar tablicy
    int count_;    			//liczba danych przechowywanych w tablicy
    type end_;
    void enlarge_x2();      //zwieksza rozmiar tablicy dwukrotnie, metoda nr 2

};



//***************************************************************************************************//



using namespace std;

#include "ArrayList.h"
/**
 * konstruktor
 */
///size_=SIZE	- poczatkowy rozmiar listy
///	count_		- liczba elementow na liscie
///	end_=0;
///	name_ = 	- tablica przechowujaca dodane elementy
///	next_=		- tablica przechowujaca indeks nastepnego elementu na liscie

template <class type>
ArrayList<type>::ArrayList() {

	size_=SIZE;				//poczatkowy rozmiar tablicy
	count_=0;				//liczba dodanych elementow
	end_=0;
	name_ = new type[size_];
	next_=new int[size_];
	//name_[0]=NULL;			//pierwszy element
	next_[0]=1;

}

/**
 * destruktor
 */
template <class type>
ArrayList<type>::~ArrayList() {
	delete [] name_;
	delete [] next_;
}

/**
 * funkcja zwracajaca aktualny rozmiar listy
 * @return size_
 */
template <class type>
int ArrayList<type>::getSize()
{
    //cout<<"aktualny rozmiar  tablicy: "<<count_<<endl;
    return size_;
}


/**
 * funkcja zwiekszajaca rozmiar tablicy dwukrotnie
 */
template <class type>
 void ArrayList<type>::enlarge_x2()
{
    if(size_==(count_+1) )
    {
        size_=size_*2;
        type *tmp1= new type[size_];
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


/**
 * funkcja dodajaca element w dowolnym miejscu w tablicy
 * @param item - element, ktory mam zostac dodany
 * @param position - indeks elementu, po ktorym ma zostac dodany item
 */
template <class type>
 void ArrayList<type>::add(type item, int position)				///position - indeks elementu po ktorym mamy wstawic
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
template <class type>
void ArrayList<type>::remove(int index)
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
template <class type>
 void ArrayList<type>::display(int i)				///wyswietla nazwe obiektu i numer indeksu obiektu, na ktory pokazuje jako nastepny
     {


             //cout<<next_[i]<<endl;
     }

//void ArrayList::displayFree()
//{
//	free_.display();
//}
/**
 * funkcja przeszukujaca tablice stringow
 * @param item - szukane slowo
 * @return - zwraca nr indeksu szukanego slowa lub -1, jezeli nie znaleziono
 */
template <class type>
 int ArrayList<type>::findInArray(type item)
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
template <class type>
 int ArrayList<type>::getNext(int index)
 {
	return next_[index] ;
 }
 /**
  * funkcja zwracajaca element z tablicy name_
  * @param index - nr indeksu zwracanego elementu
  * @return
  */
//template <class type>
// LinkedList<type> ArrayList<type>::getName(int index)
// {
//	 return name_[index];
// }
/**
 * funkcja zwracajaca liczbe elementow w tablicy
 * @return
 */
template <class type>
 int ArrayList<type>::getCount()
 {
	 return count_;
 }

template <class type>
 type ArrayList<type>::getElem(int index)
 {
	 return name_[next_[index]];
 }

#endif /* LISTA_H_ */
