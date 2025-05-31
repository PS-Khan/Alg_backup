//make -f Makefile
#include <iostream>
#include <stack>




int main(){

    std::stack<std::string> st;
    st.push("Monday");
    st.push("Tuesday");
    st.push("Wensday");
    st.push("Thersday");
    st.push("Friday");
    st.push("Saturday");
    st.push((std::string)__DATE__);

    while(!st.empty()){
        std::cout<<st.top()<< std::endl;
        st.pop();
    }


    std::stack<std::string> st2;
    st2.emplace("Monday !");
    st.emplace("Tuesday");
    st.swap(st2);

    while(!st.empty()){
        std::cout<<st.top()<< std::endl;
        st.pop();
    }
     while(!st2.empty()){
        std::cout<<st2.top()<< std::endl;
        st2.pop();
    }


    const int max_size=5;
    class my_Stack{

        public:
            my_Stack(){
                top=-1;
            };

            bool isEmpty(){
                return (top==-1);
            }

            bool isFull(){
                return (top==max_size-1);
            }

            void push(int element){
                if(!isFull()){
                    top++;
                    array[top]=element;
                }else{
                    std::cout<<"stack is full"<<std::endl;
                }
            }

            void pop(){
                if(!isEmpty()){
                    array[top]=0;
                    top--;
                }else{
                    std::cout<<"stack is empty "<<std::endl;
                }
            }

            int topElement(){
                if(!isEmpty()){
                    return array[top];
                }else{
                    std::cout<<"stack is empty "<<std::endl;
                    return -1;
                }
            }
            

        private:
            int array[max_size];
            int top;


    };

    my_Stack stack_m;
    stack_m.push(10);
    stack_m.push(2);
    stack_m.pop();
    std::cout<<stack_m.topElement()<<std::endl;
    stack_m.pop();
    std::cout<<(bool)stack_m.isEmpty();
    stack_m.pop();

    return 0;
}