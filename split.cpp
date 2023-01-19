/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

if (in == NULL){
  return;
}

  
  split(in->next,odds,evens);

  
  if ( (in->value)%2 == 0){
  
    if (evens == nullptr){     
       cout<<in->value<<endl;  
   Node* newp = new Node((in->value),nullptr);   
    evens = newp;      
    }
    else {
      cout<<in->value<<endl;  
      Node* newp = new Node((in->value),evens);     
       evens = newp; 
    }
   
  }
   else if ( (in->value)%2 != 0){
    
    if (odds == nullptr){   
    cout<<in->value<<endl;  
    Node* newp = new Node((in->value),nullptr);
    odds = newp; 

    
    }
    else {
     cout<<in->value<<endl;  
      Node* newp = new Node((in->value),odds);
      odds = newp;
    }
  }
  
  

}



/* If you needed a helper function, write it here */

