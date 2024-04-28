/*

Overview
Given an array, deck, of integers representing cards, we need to order the cards in the deck so that they are revealed in increasing order.

Cards are revealed using the following process:

The top card is revealed and removed.
The next card is moved to the bottom of the deck.
Repeat while there are more cards.
Key Observations:

We need to sort the deck in a special order.
All values in the deck are unique.

*/


#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;


 vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::sort(begin(deck), end(deck));
        int size = deck.size();
        vector<int> res(size,0);
        int dck = 0, rs = 0;
        bool skip = false;
        while(dck < size){
            if( res[rs] == 0){
                if(!skip){
                    res[rs] = deck[dck];
                    dck++;
                }
                skip = !skip;
            }
            rs=(rs+1)%size;
        }
        

        return res;
}

//

 vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        queue<int> queue;

        for (int i = 0; i < N; i++) {
            queue.push(i);
        }
        
        sort(deck.begin(), deck.end());

        
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            
            result[queue.front()] = deck[i];
            queue.pop();

            
            if (!queue.empty()) {
                queue.push(queue.front());
                queue.pop();
            }
        }
        return result;
    }