
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val){

    if ( (head_ == NULL) && (tail_ == NULL) ){
      Item* newp = new Item();
      head_ = newp;
      tail_ = newp;
      head_->val[0] = val; 
      head_ -> last = 1;
    }
    else if ( (tail_->last) < ARRSIZE ){
      tail_->val[( tail_->last )] = val;
      tail_->last++;
    }
    else if ( (tail_->last) >= ARRSIZE ){
      Item* newp = new Item();
      tail_->next = newp;
      newp->prev = tail_;
      newp->next = NULL;
      tail_ = newp;
      tail_->val[0]=val;
      tail_->last++;
    }
  size_++;
  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back() {
    //if last element in tail;
    //do i need to make tail point at previous? or have empty node

    if (head_ == tail_){
      if (tail_->last == 1){
        delete head_;
        head_ = NULL;
        tail_ = NULL;
        size_--;
        return;
      }
    }
   
    if (tail_->last == 1){
      Item* newp = tail_;
      tail_ = tail_->prev;
      delete newp;
      tail_->next = NULL;
    }
    
    else if (tail_->last >= 1){
    tail_->val[(tail_->last)-1] = "";
     tail_->last--;
    }
  size_--;
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */

  void ULListStr::push_front(const std::string& val){
  
    if (head_ == NULL){
      Item* newp = new Item();
      head_ = newp;
      tail_ = newp;
      head_->val[0]=val;
      head_->last = 1;

    }
    else if (head_->first > 0){
      head_->val[(head_->first)-1] = val;
      head_->first--;
      
    }

    else if (head_->first <= 0){
      Item* newp = new Item();
      newp->next = head_;
      head_->prev = newp;
      head_ = newp;
      head_->val[ARRSIZE-1] = val;
      head_->last = ARRSIZE;
      head_->first = ARRSIZE-1;

    }

    size_++;
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if (head_->first == ARRSIZE-1){
      Item* newp = head_;
      head_ = head_->next;
      delete newp;
    }
    else if (head_->first < ARRSIZE-1){
      head_->val[head_->first] = "";
      head_->first++;
    }
    size_--;
  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const {
    return (tail_->val[(tail_->last)-1]);
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr:: front() const{
    return (head_->val[head_->first]);
  }
  
  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const{
   if (head_ == NULL){
     return NULL;
   }
   int index = (head_->first + loc);

   Item* temp = head_;

   for (int i = 0; i <= (int)loc; i++){
     if ((index >= 0) && (index < ARRSIZE ) ){
       return (&temp->val[index]);
     }
     else if ( (temp->last) >= ARRSIZE){      
       index = index - ARRSIZE;
       temp = temp->next;      
     }
     
   }
    return NULL;
  }


// my code ends

void ULListStr::set(size_t loc, const std::string& val)
{
 std::string* ptr = getValAtLoc(loc);
 
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

 


