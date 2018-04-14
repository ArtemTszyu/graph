#include <iostream>
#include <sstream>
#include <utility>

template <typename T>
class queue_t
{
private:
    struct node_t
    {
        node_t* next;
        T value;
    };
private:
    node_t* head;
    node_t* tail;

public:
    queue_t()
    {
        head = nullptr;
        tail = nullptr;
    }
    
       queue_t(queue_t<T> const & other)
	{
		node_t* node = other.heado();
        	while(node != nullptr){
			push(node->value);
			node = node->next;
		}
        	
	}
	
    queue_t<T> & operator=(queue_t<T> & other)
    {
	    if(other.heado() != nullptr){
		    this->~queue_t();
             }

        node_t* node = other.heado();
        while(node != nullptr){
		push(node->value);
		node = node->next;
	}
        return *this;
    }
    
    ~queue_t()
    {
        if (head != nullptr)
        {
            del (head);
        }
    }
    
    node_t * heado() {
		return head;
	}
	node_t * tailo() {
		return tail;
	}
	
	T headl(node_t* heado){
		return heado->value;
	}
	
	T taill(node_t* tailo){
		return tailo->value;
	}

    void del(node_t* run_)
    {
        if (run_ != nullptr)
        {
            if (run_->next != nullptr)
            {
                del(run_->next);
            }
            delete run_;
        }
    }
    
    void push(T value ){    
        if (head == nullptr)
        {
            head = new node_t;
            head->value = value;
            tail = head;
        }
        else
        {
            tail->next = new node_t;
            tail = tail->next;
            tail->next = nullptr;
        }
    }
 T pop (){
   if(head != nullptr){
        T deleted = head->value;
        node_t* node = head;
        head = head->next;
	if(head == nullptr){
		tail = nullptr;
	}
        delete node;
        return deleted;
        }
   else {
	   throw std::logic_error("Error");
   }
  }           
};
