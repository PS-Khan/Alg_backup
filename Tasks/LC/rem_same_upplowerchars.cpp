
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

/*
deletes from string all eE ,bB ans so on pairs.
*/

/*
with (like) stack
*/

 string makeGood(string s) {
        
        std::string res;

        for (char c : s) {
            if (!res.empty() && std::abs(c - res.back()) == 32) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }

/*
let this be
*/

    bool check(char a, char b){
        if(a == b || std::tolower(a) != std::tolower(b)){
            return false;
        }else{
            return true;
        }
    }
    string makeGood(string s) {
        std::string tmp;
        do{
            tmp = s;
            auto it = s.begin();
        while (it != s.end()) {
            if (std::next(it) != s.end() && check(*it, *std::next(it))) {
                it = s.erase(it, std::next(it, 2)); 
            } else {
                ++it;
            }
        }
            
        }while(tmp != s);

        return s;
    }
