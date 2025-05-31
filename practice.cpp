#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include <pthread.h>


using namespace std;
#include <stdexcept>





int main(){
    int i = 1;
    cout<<i<<"\n";
    
    int j = 1<<2;
    i |=  j;



    cout<<i;
	return 0;
}
