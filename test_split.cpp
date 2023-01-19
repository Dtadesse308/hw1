/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;



int main(int argc, char* argv[])
{
   // Node* four = new Node(8,nullptr);
   // Node* three = new Node(2,four);
   
    Node* one = nullptr;

    Node* evens = nullptr;
    Node* odds = nullptr;
  
    split(one,odds,evens);

    while((evens)!=nullptr){
        cout<<"evens "<<(evens->value)<<endl;
        evens = evens->next;
    }
     while((odds)!=nullptr){
        cout<<"odds "<<(odds->value)<<endl;
        odds = odds->next;
    }

}
