 /*
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

 he school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

 
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

 
 int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> st;
        std::stack<int> sn;
        for (int student : students) {
            st.push(student);
        }
        int  size = st.size();

        for (int i = size-1; i >= 0 ; i--) {
            sn.push(sandwiches[i]);
        }
        
        while(true){
            for(int i = 0; i < size ; i++){
                int tmp = st.front();
                if(tmp  == sn.top()){
                    st.pop();
                    sn.pop();
                }else{
                    st.pop();
                    st.push(tmp);
                }
            }
            if(size == st.size()){
                return size;
            }else{
                size = st.size() ;
            }
        }