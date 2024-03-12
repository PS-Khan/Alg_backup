//make -f Makefile
#include <iostream>
#include <iomanip>
#include <cstring>
#include <list>
#include <iterator>





int main() {
    
    std::list<int> my_list = { 12, 5, 10, 9 };
    std::list<int> list_merge = {7, 8, 9};

    for (int x : my_list) {
		std::cout << x << '\n';
	}

    my_list.push_front(10);
    my_list.push_back(7);

    my_list.pop_front();
    my_list.pop_back();

    std::list<int>::iterator it = my_list.begin();
    std::advance(it,2);
    my_list.insert(it,44);

    for (int x : my_list) {
		std::cout << x << '\n';
	}
    std::cout<<"copy:\n";
    copy(my_list.begin(), my_list.end(), std::ostream_iterator<int>(std::cout," "));

    my_list.unique();

    for (it = my_list.begin(); it != my_list.end(); it++) { 
        std::cout << (*it) << " ";
    }

    my_list.merge(list_merge);  
    for (it = my_list.begin(); it != my_list.end(); it++) {
        std::cout << (*it) << " ";  
    }

    it = my_list.erase(it++);
    my_list.erase(it,it++);


    


    struct node{
        int data;
        struct node *next;
    };

    class linked_list{
        private:
            node *head,*tail;
        public:
            linked_list()
            {
                head = NULL;
                tail = NULL;
            }

            void add_node(int n)
            {
                node *tmp = new node;
                tmp->data = n;
                tmp->next = NULL;

                if(head == NULL)
                {
                    head = tmp;
                    tail = tmp;
                }
                else
                {
                    tail->next = tmp;
                    tail = tail->next;
                }
            }

            node* gethead()
            {
                return head;
            }

            void display()
            {
                node *tmp;
                tmp = head;
                while (tmp != NULL)
                {
                    std::cout << tmp->data << std::endl;
                    tmp = tmp->next;
                }
            }
            /*
            
            void display(node *head)
            {
                if(head == NULL)
                {
                    cout << "NULL" << endl;
                }
                else
                {
                    cout << head->data << endl;
                    display(head->next);
                }
            }

            */

            void concatenate(struct node *a,struct node *b)
            {
                if (a->next == NULL)
                    a->next = b;
                else
                    concatenate(a->next,b);
            }
            //or a->tail->next = b->head
        
            void front(int n)
            {
                node *tmp = new node;
                tmp -> data = n;
                tmp -> next = head;
                head = tmp;
            }

            void after(node *a, int value)
            {
                node* p = new node;
                p->data = value;
                /*
                if initial linked list is
                _______        _______        _______ 
                |   1   |____\ |   3   |____\ |   5   |____\ NULL
                |_______|    / |_______|    / |_______|    / 
                and new node's value is 10
                then the next line will do something like
                _______        _______        _______ 
                |   1   |____\ |   3   |____\ |   5   |____\ NULL
                |_______|    / |_______|    / |_______|    / 
                                / \
                                |
                                |
                            ___|___
                            |   10  |
                            |_______|
                */
                p->next = a->next;
                a->next = p;
                /*
                now the linked list will look like:
                _______       _______        _______        _______ 
                |   1   |____\|   10  |____\ |   3   |____\ |   5   |____\ NULL
                |_______|    /|_______|    / |_______|    / |_______|    / 
                */
            }

            void del (node *before_del)
            {
                node* temp;
                temp = before_del->next;
                before_del->next = temp->next;
                delete temp;
            }

            void reverse() {
                if (head == nullptr || head->next == nullptr) {
                    return; // No need to reverse if list is empty or has only one node
                }

                node *prev = nullptr;
                node *current = head;
                node *next = nullptr;

                while (current != nullptr) {
                    next = current->next;
                    current->next = prev;
                    prev = current;
                    current = next;
                }

                tail = head; // Update tail to point to the original head
                head = prev; // Update head to point to the new head
            }
        

    };
    
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.display();
    //a.display(a.gethead());

    linked_list b;
    b.add_node(3);
    b.add_node(4);

    a.concatenate(a.gethead(),b.gethead());
    a.del(a.gethead()->next);
    a.display();
    
    
    return 0;
}