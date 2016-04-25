/*
 * BinarySearchTree.cpp
 *
 *  Created on: 18 kwi 2016
 *      Author: paula
 */

#include "BinarySearchTree.h"
//#include <cstddef>
#include <iostream>
#include <string>


BinarySearchTree::BinarySearchTree() {
//	tree_=new node[size_];
//	size_=BEGIN_SIZE;
//	count_=0;
//	tab_=new int[size_];
	//tree_[1]=NULL;
	//"taken" gdy indeks zajety
	//empty_=new std::string[size_];
	q_=NULL;
	root_=NULL;

}

BinarySearchTree::~BinarySearchTree() {
	//delete [] tree_;
}
////
void BinarySearchTree::add(int z)
{
     node *p,*q;
     node *t=new node;
     t->key=z;
     t->left=NULL;
     t->right=NULL;
     t->color='r';
     p=root_;
     q=NULL;
     if(root_==NULL)
     {
           root_=t;
           t->parent=NULL;
     }
     else
     {
         while(p!=NULL)
         {
        	 //display(p);
              q=p;
              if(p->key<t->key)
                  p=p->right;
              else
                  p=p->left;
         }
         t->parent=q;
         if(q->key<t->key)
              q->right=t;
         else
              q->left=t;
     }
     addfix(t);
}

void BinarySearchTree::addfix(node *t)
{
     node *u;
     if(root_==t)
     {
         t->color='b';
         return;
     }
     while(t->parent!=NULL&&t->parent->color=='r')
     {
           node *g=t->parent->parent;
           if(g->left==t->parent)
           {
                        if(g->right!=NULL)
                        {
                              u=g->right;
                              if(u->color=='r')
                              {
                                   t->parent->color='b';
                                   u->color='b';
                                   g->color='r';
                                   t=g;
                              }
                        }
                        else
                        {
                            if(t->parent->right==t)
                            {
                                 t=t->parent;
                                 leftRotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            rightRotate(g);
                        }
           }
           else
           {
                        if(g->left!=NULL)
                        {
                             u=g->left;
                             if(u->color=='r')
                             {
                                  t->parent->color='b';
                                  u->color='b';
                                  g->color='r';
                                  t=g;
                             }
                        }
                        else
                        {
                            if(t->parent->left==t)
                            {
                                   t=t->parent;
                                   rightRotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            leftRotate(g);
                        }
           }
           root_->color='b';
     }
}

void BinarySearchTree::leftRotate(node *p)
{
     if(p->right==NULL)
           return ;
     else
     {
           node *y=p->right;
           if(y->left!=NULL)
           {
                  p->right=y->left;
                  y->left->parent=p;
           }
           else
                  p->right=NULL;
           if(p->parent!=NULL)
                y->parent=p->parent;
           if(p->parent==NULL)
                root_=y;
           else
           {
               if(p==p->parent->left)
                       p->parent->left=y;
               else
                       p->parent->right=y;
           }
           y->left=p;
           p->parent=y;
     }
}


void BinarySearchTree::rightRotate(node *p)
{
     if(p->left==NULL)
          return ;
     else
     {
         node *y=p->left;
         if(y->right!=NULL)
         {
                  p->left=y->right;
                  y->right->parent=p;
         }
         else
                 p->left=NULL;
         if(p->parent!=NULL)
                 y->parent=p->parent;
         if(p->parent==NULL)
               root_=y;
         else
         {
             if(p==p->parent->left)
                   p->parent->left=y;
             else
                   p->parent->right=y;
         }
         y->right=p;
         p->parent=y;
     }
}

void BinarySearchTree::display()
{
     display(root_);
}
void BinarySearchTree::display(node *p)
{
     if(root_==NULL)
     {
          cout<<"\nEmpty Tree.";
          return ;
     }
     if(p!=NULL)
     {
                cout<<"\n\t NODE: ";
                cout<<"\n Key: "<<p->key;
                cout<<"\n Colour: ";
    if(p->color=='b')
     cout<<"Black";
    else
     cout<<"Red";
                if(p->parent!=NULL)
                       cout<<"\n Parent: "<<p->parent->key;
                else
                       cout<<"\n There is no parent of the node.  ";
                if(p->right!=NULL)
                       cout<<"\n Right Child: "<<p->right->key;
                else
                       cout<<"\n There is no right child of the node.  ";
                if(p->left!=NULL)
                       cout<<"\n Left Child: "<<p->left->key;
                else
                       cout<<"\n There is no left child of the node.  ";
                cout<<endl;
    if(p->left)
    {
                 cout<<"\n\nLeft:\n";
     display(p->left);
    }
    /*else
     cout<<"\nNo Left Child.\n";*/
    if(p->right)
    {
     cout<<"\n\nRight:\n";
                 display(p->right);
    }
    /*else
     cout<<"\nNo Right Child.\n"*/
     }
}

void BinarySearchTree::find(int x)
{
     if(root_==NULL)
     {
           cout<<"\nEmpty Tree\n" ;
           return  ;
     }
     node *p=root_;
     int found=0;
     while(p!=NULL&& found==0)
     {
            if(p->key==x)
                found=1;
            if(found==0)
            {
                 if(p->key<x)
                      p=p->right;
                 else
                      p=p->left;
            }
     }
     if(found==0)
          cout<<"\nElement Not Found.";
     else
     {
                cout<<"\n\t FOUND NODE: ";
                cout<<"\n Key: "<<p->key;
                cout<<"\n Colour: ";
    if(p->color=='b')
     cout<<"Black";
    else
     cout<<"Red";
                if(p->parent!=NULL)
                       cout<<"\n Parent: "<<p->parent->key;
                else
                       cout<<"\n There is no parent of the node.  ";
                if(p->right!=NULL)
                       cout<<"\n Right Child: "<<p->right->key;
                else
                       cout<<"\n There is no right child of the node.  ";
                if(p->left!=NULL)
                       cout<<"\n Left Child: "<<p->left->key;
                else
                       cout<<"\n There is no left child of the node.  ";
                cout<<endl;

     }
}

//void BinarySearchTree::add(int a)
//{
//		tab_[count_]=a;
//		count_++;
//
//
//}
//
//void BinarySearchTree::quicksort(int *tab, int left, int right )
//{
//	int v=tab[(left+right)/2];
//	int i,j,x;
//	i=left;
//	j=right;
//	while(i<=j)
//	{
//		while(tab[i]<v) i++;
//		while(tab[j]>v) j--;
//		if(i<=j)
//		{
//			x=tab[i];
//			tab[i]=tab[j];
//			tab[j]=x;
//			i++;
//			j--;
//		}
//	}
//	if (j>left) quicksort(tab, left, j);
//	if (i<right) quicksort(tab,i, right);
//}


//void BinarySearchTree::enlarge_x2()
//{
//	if(size_==(count_+1) )
//	    {
//	        size_=size_*2;
//	        int *tmp= new int[size_];
//	        for(int i=0; i<=count_;i++)
//	        {
//	            tmp[i]=tree_[i];      //przepisuje dane ze starej tablicy do nowej
//	        }
//	        delete [] tree_;
//	        tree_ =tmp;
//
//	    }
//}

//int BinarySearchTree::isEmpty()
//{
//	if(count_==0) return 1;
//	else return 0;
//}

//int BinarySearchTree::getSize()
//{
//	return size_;
//}

//node BinarySearchTree::getElem(int index)
//{
//
//	return tree_[index];
//}
