/**
 * Line 1 : n number of input signals.
Line 2 : m number of output signals.
n next lines : two space separated strings : name of input signal, then signal form.
m next lines : four space separated strings : name of output signal, then type of logic gate,
then first input name, then second input name.
Standard Output Stream:
ZORGLUB signal: ----____----____----____----____----____--
MEGAMAN signal: --____----____----____----____----____----
ZOLTRON signal: ---___---___------______------______-_-_-_
PEW_PEW signal: -_-_-_-_------_____----____---___--__--__-
OUTPUT1 type: AND ZORGLUB MEGAMAN
HereAND ZORGLUB MEGAMAN
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
OUTPUT2 type: OR ZORGLUB ZOLTRON
HereOR ZORGLUB ZOLTRON
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
OUTPUT3 type: XOR ZORGLUB PEW_PEW
HereXOR ZORGLUB PE
...
---____----____----____----____----
----____----____----____----____----____--
ROGUE_4 type: NXOR PEW_PEW MEGAMAN
HereNXOR PEW_PEW MEGAMAN
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
SQUAD_1 type: NAND PEW_PEW MEGAMAN
HereNAND PEW_PEW MEGAMAN
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
SQUAD_2 type: OR ZOLTRON PEW_PEW
HereOR ZOLTRON PEW_PEW
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
SQUAD_3 type: NOR ZOLTRON PEW_PEW
HereNOR ZOLTRON PEW_PEW
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
SQUAD_4 type: AND ZOLTRON PEW_PEW
HereAND ZOLTRON PEW_PEW
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
MIKADO1 type: AND MEGAMAN PEW_PEW
HereAND MEGAMAN PEW_PEW
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
MIKADO2 type: OR MEGAMAN PEW_PEW
HereOR MEGAMAN PEW_PEW
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
MIKADO3 type: XOR MEGAMAN MEGAMAN
HereXOR MEGAMAN MEGAMAN
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
MIKADO4 type: NXOR ZOLTRON ZOLTRON
HereNXOR ZOLTRON ZOLTRON
-_-_-_-_------_____----____---___--__--__-
---___---___------______------______-_-_-_
--____----____----____----____----____----
----____----____----____----____----____--
OUTPUT1 --______--______--______--______--______--
OUTPUT2 ----__--------------____------__-----_-_--
OUTPUT3 _-_--_-_____--__---_---_---_--__-__-_--_-_
OUTPUT4 ----____----____----____----____----____--
ROGUE_1 --____----____----____----____----____----
ROGUE_2 __----____----____----____----____----____
ROGUE_3 _-_-_-_-______-----____----___---__--__--_
ROGUE_4 -__-_--_--________-___-___-______-_--_-__-
SQUAD_1 _-----_-__------------_----------_----_--_
SQUAD_2 ---_-_------------_----_------___--_---_--
SQUAD_3 ___-_-____________-____-______---__-___-__
SQUAD_4 -_-___-_-___--_____________---________-___
MIKADO1 -_____-_--____________-__________-____-__-
MIKADO2 ---_-_------------_-------_--------__-----
MIKADO3 __________________________________________
MIKADO4 ------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


string compute(string op, unordered_map<string,string> &signals, string n1, string n2){
    string res;
    std::cerr<< "Here"<<op<<" "<< n1 << " " << n2 << std::endl;
    for (auto k : signals){
         std::cerr<< k.second<<std::endl;
    }
    if(op == "AND"){
        for (int i = 0; i < signals[n1].length(); i++){
            if(signals[n1][i] == '-' &&  signals[n2][i] == '-' ){
                res +='-';
            }else{
                res += '_';
            }
            
        }
    } else if(op == "OR"){
        for (int i = 0; i < signals[n1].length(); i++){
            if(signals[n1][i] == '-' ||  signals[n2][i] == '-' ){
                res +='-';
            }else{
                res += '_';
            }
            
        }
    } else if(op == "XOR"){
       for (int i = 0; i < signals[n1].length(); i++){
            if( (signals[n1][i] == '-' &&  signals[n2][i] == '-') || (signals[n1][i] == '_' &&  signals[n2][i] == '_') ){
                res +='_';
            }else{
                res += '-';
            }
            
        }
    } else if (op == "NAND") {
        for (int i = 0; i < signals[n1].length(); i++) {
            if ( !(signals[n1][i] == '-' && signals[n2][i] == '-') ) {
                res += '-';
            } else {
                res += '_';
            }
        }
    } else if ( op == "NOR" ) {
        for (int i = 0; i < signals[n1].length(); i++) {
            if (!(signals[n1][i] == '-' || signals[n2][i] == '-')) {
                res += '-';
            } else {
                res += '_';
            }
        }
    } else if ( op == "NXOR" ) {
        for (int i = 0; i < signals[n1].length(); i++) {
            if (!((signals[n1][i] == '-' && signals[n2][i] == '-') || (signals[n1][i] == '_' && signals[n2][i] == '_'))) {
                res += '_';
            } else {
                res += '-';
            }
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    int m;
    cin >> m; cin.ignore();
    unordered_map<string,string> signals;
    for (int i = 0; i < n; i++) {
        string input_name;
        string input_signal;
        cin >> input_name >> input_signal; cin.ignore();
        std::cerr<<input_name <<" signal: "<< input_signal<< std::endl;
        signals[input_name] = input_signal;
    }
    for (int i = 0; i < m; i++) {
        string output_name;
        string type;
        string input_name_1;
        string input_name_2;
        cin >> output_name >> type >> input_name_1 >> input_name_2; cin.ignore();
        std::cerr<<output_name <<" type: "<< type<<" " <<input_name_1<<" "<< input_name_2<< std::endl;
        string res;
        res += output_name+' '+ compute(type,signals,input_name_1,input_name_2);
        cout <<res<<std::endl;

    }
    
}

/*


#include <iostream>
#include <map>
using namespace std;

char AND (char c1, char c2) {return (c1=='-')&&(c2=='-') ? '-' : '_';}
char OR  (char c1, char c2) {return (c1=='-')||(c2=='-') ? '-' : '_';}
char XOR (char c1, char c2) {return (c1=='-')^ (c2=='-') ? '-' : '_';}
char NAND(char c1, char c2) {return (c1=='-')&&(c2=='-') ? '_' : '-';}
char NOR (char c1, char c2) {return (c1=='-')||(c2=='-') ? '_' : '-';}
char NXOR(char c1, char c2) {return (c1=='-')^ (c2=='-') ? '_' : '-';}

main()
{
    int n, m;
    string id, type, in1, in2;
    map<string, string> inputs;

    cin >> n >> m;
    for (;n--;) {
        cin >> id >> in1;
        inputs[id] = in1;
    }
    for (;m--;) {
        cin >> id >> type >> in1 >> in2;
        
        char(*fct)(char, char); // Hope you like it !
        if ("AND"  == type) fct = &AND;
        if ("OR"   == type) fct = &OR;
        if ("XOR"  == type) fct = &XOR;
        if ("NAND" == type) fct = &NAND;
        if ("NOR"  == type) fct = &NOR;
        if ("NXOR" == type) fct = &NXOR;

        cout << id << " ";
        for (int i=0; i<inputs[in1].length(); ++i)
            cout << fct(inputs[in1][i], inputs[in2][i]);
        cout << endl;
    }
}

*/