#include <iostream>
#include <queue>
#include <vector>

int main(){

    std::priority_queue<int> pq;

    pq.push(3);
    pq.push(2);
    pq.push(5);
    pq.push(6);


    size_t count= pq.size();
    while (count>0){
        count--;
        std::cout<<pq.top();
        pq.pop();
    }

    std::priority_queue< int, std::vector<int>, std::greater<int> > pq2;
    pq2.push(3);
    pq2.push(2);
    pq2.push(5);
    pq2.push(6);

    count= pq2.size();
    while (count>0){
        count--;
        std::cout<<pq2.top();
        pq2.pop();
    }


    struct node
    {
        int priority;
        int info;
        struct node *link;
    };
    class Priority_Queue
    {
        private:
            node *front;
        
        public:
            Priority_Queue()
            {
                front = NULL;
            }
        
            void insert(int item, int priority)
            {
                node *tmp, *q;
                tmp = new node;
                tmp->info = item;
                tmp->priority = priority;
                if (front == NULL || priority > front->priority)
                {
                    tmp->link = front;
                    front = tmp;
                }
                else
                {
                    q = front;
                    while (q->link != NULL && q->link->priority >= priority)
                        q=q->link;
                    tmp->link = q->link;
                    q->link = tmp;
                }
            }

        int del()
        {
            node *tmp;
            if(front == NULL){
                std::cout<<"Queue Underflow\n";
                return -1;
                
            }else
            {
                tmp = front;
                front = front->link;
                int res=tmp->info;
                delete tmp;
                return res;
            }
        }


    };
    std::cout<<std::endl;
    Priority_Queue p_q;
    p_q.insert(1,5);
    p_q.insert(2,6);
    p_q.insert(3,4);
    std::cout<<p_q.del();
    std::cout<<p_q.del();
    std::cout<<p_q.del();


    return 0;
}