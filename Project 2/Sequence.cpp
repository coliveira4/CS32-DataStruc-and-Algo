//
//  Sequence.cpp
//  Project 2
//
//  Created by Christina Oliveira on 1/25/17.
//  Copyright © 2017 Christina Oliveira. All rights reserved.
//

#include "Sequence.h"

#include<iostream>

Sequence::Sequence(){  //Constructor: creates empty,circular, doubly-linked list
    m_size = 0;
    head = new Node;
    head->m_next = head;
    head->m_back = head;
}

Sequence::~Sequence() //Destructor: if list is empty, just delete head, else delete each node then the head
{
    
    while (head->m_back != head)
    {
        Node* temp = head->m_back;
        temp->m_back->m_next= head;
        head->m_back = temp->m_back;
        delete temp;
    }
    delete head;
    
}

Sequence::Sequence(const Sequence& other) //Copy constructor
: m_size(other.m_size)
{
    head = new Node;
    head->m_next = head;
    head->m_back = head;
    Node* p = other.head->m_next;
    while(p != other.head )
    {
        Node *temp = new Node;
        temp->m_value = p->m_value;
        temp->m_next = head;
        temp->m_back = head->m_back;
        head->m_back->m_next = temp;
        head->m_back = temp;
        
        p = p->m_next;
    }
}

Sequence& Sequence::operator=(const Sequence& rhs) //Assignment Operater
{
    if (this == &rhs)
    {
        return *this;
    }
    Sequence temp(rhs);
    swap(temp);
    return *this;
}


bool Sequence::empty() const{  //returns true is sequence is empty
    return(m_size == 0);
}

int Sequence::size() const{ //returns the number of nodes in the sequence
    return m_size;
}

bool Sequence::insert(int pos, const ItemType& value) //Inserts Node with m_value value at position pos
{
    if (pos < 0  ||  pos > size() ) //cant insert item at position not in the list
        return false;
 
    else if(pos >= 0 && pos < size())  //Case 1: insert item at positions 0 to size()-1
    {
        Node *p = head->m_next;      //Allocate a new Node pointer to traverse the list
        for(int i = 0; i < size(); i++) //will iterate a set number of times so can use i as "index"
        {
            if(i == pos)
            {
                Node *latest = new Node;
                latest->m_value = value;
                latest->m_next = p;
                latest->m_back = p->m_back;
                p->m_back->m_next = latest;
                p->m_back = latest;
                m_size++;
                return true;
            }
            p = p->m_next;
            
        }
    }
    else  //Case 2: insert item when pos==size
    {
        Node *p = head->m_back;
        Node *latest = new Node;
        latest->m_value = value; //insert value
        latest->m_next = head;    //links to head since it is the new last item
        latest->m_back = p;       //link up surrounding nodes
        p->m_next = latest;
        head->m_back = latest;
        m_size++;
        return true;
    }
    return true;
}



int Sequence::insert(const ItemType& value)
{
    int pos = size();
    if(empty())           //if its empty add at pos 0
    {
    insert(0,value);
    return 0;
    }
    Node *p = head;        //else, traverse the list to the desired position and insert there
    for(int i =0; i <size(); i++)
    {
        p=p->m_next;
        if(p->m_value >= value)
        {
            pos = i;
            break;
        }
    }
    insert(pos,value);
    
    return pos;
}

bool Sequence::erase(int pos) //removes node at position pos and links up surrounding nodes
{
    if (pos < 0  ||  pos >= size())
        return false;
    
    Node *p = head;
    for(int i =0; i <size(); i++)
    {
        p = p->m_next;
        if(i==pos)          //once we have reached the desired position
        {
            Node *temp = p;
            p->m_back->m_next = temp->m_next;
            p->m_next->m_back = temp->m_back;
            delete temp;            //delete the node at this position
            m_size--;
            return true;
        }
        
    }
    return true;
}

int Sequence::remove(const ItemType& value) //removes all nodes with m_value value and relinks surrounding nodes
{
    int count = 0;
    Node *p;
    p = head->m_next;
    while(p != head)
    {
        if (p->m_value == value) //if the value here is the value specified
        {
            Node *temp = p;                     //delete this node
            p->m_back->m_next = temp->m_next;
            p->m_next->m_back = temp->m_back;
            delete temp;
            m_size--;
            count++;
        }
        p = p->m_next;
        
    }
   
    return count;
}

bool Sequence::get(int pos, ItemType& value) const //access item at position pos and set value to it
{
    if (pos < 0  ||  pos >= size())
        return false;
    
    Node* p = head;
    for (int i = 0; i < size(); i++)
    {
        p = p->m_next; //moves the pointer with i
        if (i == pos)
        {
            value = p->m_value;  //sets the value at the pos to value
            return true;
        }
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value) //set m_value of node at position pos to value
{
    if (pos < 0  ||  pos >= size())
        return false;
    Node *p = head;
    for (int i = 0; i < size(); i++)
    {
        p = p->m_next;
        if (i == pos)
        {
            p->m_value = value;
            return true;
        }
    }
    return true;
}

int Sequence::find(const ItemType& value) const  //returns position of earliest occurance of node with m_value value
{
    if(empty()) //if its empty, then its def not there!
        return -1;
    Node *p = head;
    for(int i = 0; i < size(); i++ )
    {
        p = p->m_next;
        if(p->m_value == value)
            return i;
    }
    
    return -1;
}

void Sequence::swap(Sequence& other)  //Swap two sequences by swapping thier heads and sizes.
{
    //swap heads
    Node* temp = other.head;
    other.head = head;
    head = temp;
    //swap the sizes
    int temp2 = other.m_size;
    other.m_size = m_size;
    m_size = temp2;
   }


//Non-Member Functions
//Returns the position of the earliest starting position where seq2 is entirely contained within seq1
int subsequence(const Sequence& seq1, const Sequence& seq2){
    //if se2 is empty or is larger than seq1, return -1
    if(seq2.empty() || seq2.size() > seq1.size())
        return -1;
    //else, look for first item in seq2 anywhere within seq1
    int pos;
    bool full  = false;
    ItemType x;
    ItemType y;
    for(int i =0; i < seq1.size();i++ ){
        //utilize get function to access sequence values in temp variables x and y
        seq1.get(i, x);
        seq2.get(0, y);
        if(x == y)       //if found, save starting point and see if streak continues
        {
            int k = i;
            pos = i;  //saves starting point
            for (int j =0;j < seq2.size(); j++)
            {
                full = true;   //true until proved false at this point
                seq1.get(k, x);
                seq2.get(j, y);
                if (x != y)
                {
                    full  = false;    //Proved wrong
                    break;
                }
                k++;
            }
            if(full)
            {
                return pos;
            }
        }
    }
    
    //if there is no such sequence return -1
    return -1;
}


void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result){ //combines the sequences
    //result is not guananteed to be empty, gotta empty it!
    //need to make a temp sequence to avoid aliasing issues
    Sequence temp(result);
    while(!temp.empty())
    {
        temp.erase(0);
    }
    //case 1: both sequences empty
    if(seq1.empty() && seq2.empty())
    {
        result = temp;
        return;
    }
    //case 2: seq1 is empty, then result is seq2
    else if(seq1.empty())
    {
        temp = seq2;
        result = temp;
        return;
    }
    //case 3: reverse of case 2
    else if(seq2.empty())
    {
        temp = seq1;
        result = temp;
        return;
    }
    ItemType x,y;
    int j = 0;  //just an iterator for the second sequence
    int tempsize = 0;   //iterator for the result
    //case 4: anything else
    for (int i =0 ;i < seq1.size() || j < seq2.size(); )
    {
        if(i < seq1.size()) //if we can, insert an item from seq1
        {
            seq1.get(i,x);
            temp.insert(tempsize,x); //inserts at the end
            i++;
            tempsize++;
        }
        if(j < seq2.size())
        {
            seq2.get(j,y);
            temp.insert(tempsize,y);
            j++;
            tempsize++;
        }
    }
    result = temp;
    
}
