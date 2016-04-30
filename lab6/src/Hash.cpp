/*
 * Hash.cpp
 *
 *  Created on: 27 kwi 2016
 *      Author: paula
 */

#include "Hash.h"
#include <cstdlib>
#include <iostream>
#include <string>

Hash::Hash(int size) {

	tableSize_=size;
	hashTable=new item[tableSize_];

	for(int i=0; i<tableSize_;i++)
	{
		hashTable[i].name="empty";
		hashTable[i].next=NULL;
		hashTable[i].tel=0;


	}

}

Hash::~Hash() {
 delete [] hashTable;
}

int Hash::hash(string key)
{
	int hash=0;
	int index;

	for(unsigned int i=0; i<key.length();i++)
	{
		hash=(hash+(int)key[i]);
	}

	index=hash % tableSize_;		//reszta z dzielenia przez rozmiar tablicy to index


	return index;
}

void Hash::addItem(string name, int tel)
{
	int index = hash(name);

	if(hashTable[index].name=="empty")	//jeszcze nic nie jest zapisane w tym buckecie; nadpisuje
	{
		hashTable[index].name=name;
		hashTable[index].tel=tel;
	}
	else
	{
		item* Ptr = &hashTable[index];
		item* n = new item;
		n->name=name;
		n->tel=tel;
		n->next=NULL;
		while(Ptr->next!=NULL)
		{
			Ptr=Ptr->next;
		}
		Ptr->next=n;
	}
}

int Hash::numberOfItemsInIndex(int index)
{
	int count = 0;
	if(hashTable[index].name=="empty") //niezajete miejsce
	{
		return count;
	}
	else
	{
		count++;
		item* Ptr = &hashTable[index];
		while(Ptr->next!=NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

void Hash::printTable()
{
	int number;
	//sprawdzam ilosc itemow w kazdym slocie
	for (int i=0; i<tableSize_;i++)
	{
		number=numberOfItemsInIndex(i);
		cout<<"-------------------\n";
		cout<<"index= "<<i<<endl;
		cout<<hashTable[i].name<<endl;
		cout<<"# of items = "<<number<<endl;
		cout<<"-------------------\n";
	}
}

void Hash::printItemsInIndex(int index)
{
	item* Ptr = &hashTable[index];

	if(Ptr->name=="empty")
	{
		cout<<"index= "<<index<<"is empty";
	}
	else
	{
		cout<<"index "<<index<<" contains the following items\n";
		while(Ptr !=NULL)
		{
			cout<<"--------------------------------\n";
			cout<<Ptr->name<<endl;
			cout<<Ptr->tel<<endl;
			cout<<"--------------------------------\n";
			Ptr=Ptr->next;
		}
	}
}

int Hash::find(string name)
{
	int index = hash(name);
	bool foundName=false;
	int telephone;

	//szukam w buckecie do ktorego trafilo name
	item* Ptr = &hashTable[index];
	while(Ptr != NULL)
	{
		if(Ptr->name ==name)
		{
		foundName = true;
		telephone=Ptr->tel;
		}
		Ptr = Ptr->next;
	}
	if (foundName==true)
	{
		cout<< name<<"'s slot index is "<<index<<" and an telephone number is "<<telephone<<endl;
		return telephone;
	}
	else
	{
		cout<<name<<" was not found in the Hash Table\n";
		return 0;
	}

}

int Hash::getTableSize()
{
	return tableSize_;
}

int Hash::operator [ ] (string name)
{
	return find(name);
}
