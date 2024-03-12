#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;


int main()
{
    int n;
    cin >> n; cin.ignore();
    int a = 0,b = 0,D = std::numeric_limits<int>::max();
    std::vector<int> arr;
    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi; cin.ignore();
        arr.push_back(pi);
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if(i%2 ==0){
            b = arr[i];
        }else{
            a = arr[i];
        }
        D = std::min(D, std::abs(a - b));
        //std::cerr<<a <<" "<<b<<" D:"<<D <<std::endl ;

    }

    cout << D << endl;
}