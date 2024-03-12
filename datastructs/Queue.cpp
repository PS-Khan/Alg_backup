#include <iostream>
#include <queue>

int main() {

    std::queue<int> queue1,q2;

    queue1.push(2);
    queue1.push(3);
    queue1.push(5);
    queue1.push(8);
    std::cout<<queue1.back()<<std::endl;
    std::cout<<queue1.front()<<std::endl;
    std::cout<<queue1.empty()<<std::endl;
    queue1.emplace(13);
    std::cout<<queue1.front()<<std::endl;
    queue1.pop();
    std::cout<<queue1.front()<<std::endl;
    std::cout<<queue1.size()<<std::endl;

    q2.emplace(9);
    q2.swap(queue1);
    std::cout<<q2.front()<<std::endl;

    const int max_size=5;
    class my_Queue{
        public:

            my_Queue(){
                front=0;
                rear=-1;
                count=0;
            }

            int size() {
                return count;
            }

            bool isEmpty() {
                return (size() == 0);
            }

            bool isFull() {
                return (size() == max_size-1);
            }

            void push(int item)
            {
                // check for queue overflow
                if (isFull())
                {
                    std::cout << "Overflow\nProgram Terminated\n";
                    exit(EXIT_FAILURE);
                }
                rear = (rear + 1) % max_size;
                array[rear] = item;
                count++;
            }

            int pop()
            {
                // check for queue underflow
                if (isEmpty())
                {
                    std::cout << "Underflow\nProgram Terminated\n";
                    exit(EXIT_FAILURE);
                }
            
                int x = array[front];
                front = (front + 1) % max_size;
                count--;
                return x;
            }

            int peek_front()
            {
                if (isEmpty())
                {
                    std::cout << "Underflow\nProgram Terminated\n";
                    exit(EXIT_FAILURE);
                }
                return array[front];
            }
            int peek_rear()
            {
                if (isEmpty())
                {
                    std::cout << "Underflow\nProgram Terminated\n";
                    exit(EXIT_FAILURE);
                }
                return array[rear];
            }

        private:
            int array[max_size];
            int front;
            int rear;
            int count;  // current size of the queue



    };
    std::cout<<"my q"<<std::endl;
    my_Queue qu1;
    std::cout<<qu1.isEmpty()<<std::endl;
    qu1.push(1);
    qu1.push(2);
    qu1.push(3);
    std::cout<<qu1.peek_front()<<std::endl;
    std::cout<<qu1.peek_rear()<<std::endl;
    std::cout<<qu1.size()<<std::endl;
    qu1.pop();
    std::cout<<qu1.peek_front()<<std::endl;


}