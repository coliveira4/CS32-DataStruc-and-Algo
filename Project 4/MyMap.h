// MyMap.h

// Skeleton for the MyMap class template.  You must implement the first six
// member functions.
#include "support.h"
template<typename KeyType, typename ValueType>

class MyMap
{
public:
    //////////////////
	MyMap()
    : m_size(0), m_root(nullptr)
    {}
    ///////////////////////////
    ~MyMap(){clear();}
    ////////////////////////
    void clear(){
        if (m_root != nullptr)
            deleteNodes(m_root);
        m_root = nullptr;
    }
    ///////////////////////
    int size() const{return m_size;}
    //////////////////////
    void associate(const KeyType& key, const ValueType& value){
        
        //if empty
        if(m_root == nullptr){
            m_root = new Node(nullptr, key, value);
            m_root->m_left =nullptr;
            m_root->m_right = nullptr;
            m_size++;
            return;
        }
        
        addNode(m_root, key, value);
        
    }
    
    ////////////////////////////////
	  // for a map that can't be modified, return a pointer to const ValueType
    const ValueType* find(const KeyType& key) const{
        
        Node* cur = m_root;
        while(cur != nullptr){
            if(cur->m_key == key)
                return &(cur->m_value);
            else if(cur->m_key > key)
                cur = cur->m_left;
            else
                cur = cur->m_right;
        }
        return nullptr;
    }

	  // for a modifiable map, return a pointer to modifiable ValueType
	ValueType* find(const KeyType& key)
	{
		return const_cast<ValueType*>(const_cast<const MyMap*>(this)->find(key));
	}

    ///////////////////////////////////////////////////////////////
	  // C++11 syntax for preventing copying and assignment
	MyMap(const MyMap&) = delete;
	MyMap& operator=(const MyMap&) = delete;
    //////////////////////////////////////////////////////////////////
    

private:
   
    struct Node
    {
    Node(Node* parent, KeyType key, ValueType value)
        {
            m_left = nullptr;
            m_right = nullptr;
            m_parent = parent;
            m_key = key;
            m_value = value;
        }
        KeyType m_key;
        ValueType m_value;
        Node* m_parent;
        Node* m_left;
        Node* m_right;
    };
    
    int m_size;
    Node* m_root;
    
    void deleteNodes(Node* top){
        if (top == nullptr)
            return;
        if (top->m_left != nullptr)
            deleteNodes(top->m_left);
        if (top->m_right != nullptr)
            deleteNodes(top->m_right);
        delete top;
    }
    void addNode(Node* p, const KeyType& key, const ValueType& value)
    {
        if(p != NULL)
        {
            if(p->m_key == key)
            {
                p->m_value = value;
                return;
            }
            
            Node* next;
            if(key < p->m_key)
            {
                next = p->m_left;
                if(p->m_left == nullptr)
                {
                    p->m_left = new Node(nullptr, key, value);
                    m_size++;
                    p->m_left->m_left = nullptr;
                    p->m_left->m_right = nullptr;
                    return;
                }
            }
            else
            {
                next = p->m_right;
                if(p->m_right == nullptr)
                {
                    p->m_right = new Node(nullptr, key, value);
                    m_size++;
                    p->m_right->m_left = NULL;
                    p->m_right->m_right = NULL;
                    return;
                }
            }
            addNode(next, key, value);
        }
    }

  
};
