/*
 * BinarySearchTree.cpp
 *
 *  Created on: 18 kwi 2016
 *      Author: paula
 */

#include "BinarySearchTree.h"
#include <iostream>
#include <string>


BinarySearchTree::BinarySearchTree() {

	q_=NULL;
	root_=NULL;

}

BinarySearchTree::~BinarySearchTree() {
	
}

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

