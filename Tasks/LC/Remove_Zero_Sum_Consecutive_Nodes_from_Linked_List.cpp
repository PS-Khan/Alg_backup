/*

for some reason didnt accept aproach when i went
through list uping x when values negative , y when positive and so on, 
 and it worked , but gave not same values in case
[1,2,3,-3,4], it returned [3,4] wich it ought to accept , but showed that ot wanted [1,2,4]
i wrote smth like that firstly:
ListNode *res;
while(head != nullptr){
    int x  = 0;
    while(head != nullptr && head->val < 0){
        x+=head->val;
        head =head->next;
    }
    int y = 0;
    while(head != nullptr && head->val > 0){
        y +=  head->val;
        head = head->next;
    }
    if(head != nullptr && y+x+head->val == 0){
        res = head->next;
    }else if(head != nullptr && y+x > 0){
        head->val = y+x+head->val;
        res =  head;
    }
}
return res;

*/
/*

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.

*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* current = &dummy;
            
        while (current->next != nullptr) {
            int sum = 0;
            ListNode* runner = current->next;
            while (runner != nullptr) {
                sum += runner->val;
                if (sum == 0) {
                    current->next = runner->next;
                    break;
                }
                runner = runner->next;
            }
            if (sum != 0) {
                current = current->next;
            }
        }
        return dummy.next;
    }