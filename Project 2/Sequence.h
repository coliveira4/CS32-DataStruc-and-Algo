//
//  Sequence.hpp
//  Project 2
//
//  Created by Christina Oliveira on 1/25/17.
//  Copyright © 2017 Christina Oliveira. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h
#include <string>

typedef std::string ItemType;

class Sequence
{
public:

    Sequence();  //creates an empty sequence
    ~Sequence();  // destructor
    Sequence(const Sequence& other); //copy constructor
    Sequence& operator=(const Sequence& rhs); // assignment operator
    
    bool empty() const;
    int size() const;
    bool insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    
    
private:
    //doubly-linked list
    struct Node{
        ItemType m_value;
        Node* m_next;
        Node* m_back;
    };
    Node* head; //head of list
    
    int m_size; //to keep track of the size of our list
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */
