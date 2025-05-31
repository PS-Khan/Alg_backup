//make -f Makefile
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


int main(){

    float a = 0, b = 0;
    char c;
    do{
        if(a==0){
            cout << "Enter a number" << endl;      
            cin >> a; 
            cin.ignore();
        }
        cout << "Enter operation(*,/,+,-) e/E for exit \n ";
        cin.get(c);
        switch(c){
            case '-':
                cout << "Enter a second number" << endl; 
                cin>>b;
                cin.ignore();
                a-=b;
                cout<<"\n"<<a<<endl;
                break;
            case '+':
                cout << "Enter a second number" << endl; 
                cin>>b;
                cin.ignore();
                a+=b;
                cout<<"\n"<<a<<endl;
                break;
            case '*':
                cout << "Enter a second number" << endl; 
                cin>>b;
                cin.ignore();
                a*=b;
                cout<<"\n"<<a<<endl;
                break;
            case '/':
                cout << "Enter a second number" << endl; 
                cin>>b;
                cin.ignore();
                a/=b;
                cout<<"\n"<<a<<endl;
                break;
            case 'e':
                break;
            case 'E':
                break;
        }

    }while (c != 'e' && c != 'E');
    return 0;
}