#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

/*
Back in the day, people had fun turning "recipes" into surprise images using typewriters.

Use the provided recipe to create a recognizable image.

Chunks in the recipe are separated by a space.
Each chunk will tell you either
nl meaning NewLine (aka Carriage Return)
~or~
how many of the character and what character

For example:
4z means zzzz
1{ means {
10= means ==========
5bS means \\\\\ (see Abbreviations list below)
27 means 77
123 means 333333333333
(If a chunk is composed only of numbers, the character is the last digit.)

So if part of the recipe is
2* 15sp 1x 4sQ nl
...that tells you to show
**               x''''
and then go to a new line.


Abbreviations used:
sp = space
bS = backSlash \
sQ = singleQuote '
and
nl = NewLine


How i solved:
 */
std::unordered_map<string, char> map_dict ={
    {"sp",' '},
    {"bS", '\\'},
    {"sQ", '\''},
    {"nl", '\n'}
};
int main()
{
    string t;
    getline(cin, t);
    std::istringstream ss(t);
    std::string part;
    std::string answear;
    while (std::getline(ss, part, ' ')) {
        cerr<<part<<" ";

        if(std::all_of(part.begin(), part.end(), [](unsigned char c) { return std::isdigit(c); })){
            char lastDigit = part.back();
            int sub;
            if (part.length() > 1) {
                sub = std::stoi(part.substr(0, part.length() - 1));
            }else{
                sub = std::stoi(part);// i think this is redundant
            }
            while (sub > 0){
                answear+=lastDigit;
                sub--;
            }
        }else{
            string st, symbol;
            for(int i = 0; i < (int)part.size(); i++){
                if(std::isdigit(part[i])){
                    st+=part[i];
                }else{
                    symbol+=part[i];
                }
            }
            int times = st.length()>0 ? std::stoi(st): 1 ;
            while(times >0){
                if(map_dict.find(symbol) != map_dict.end()){
                    answear+=map_dict[symbol];
                    times--;
                }else{
                    answear+=symbol;
                    times--;
                }
            }
        }


    }
    //cerr<<"\n"<<answear<<"\n";


    cout << answear << endl;
}



/*
What i found:
#1

int main() {
    string chunk;
    while (cin >> chunk) {
        if (chunk == "nl") {
            cout << "\n";
        } else {
            char character;
            if ((chunk[chunk.size() - 2] == 's') && (chunk[chunk.size() - 1] == 'p')) {
                character = ' ';
                chunk[chunk.size() - 2] = 0;
            } else if ((chunk[chunk.size() - 2] == 'b') && (chunk[chunk.size() - 1] == 'S')) {
                character = '\\';
                chunk[chunk.size() - 2] = 0;
            } else if ((chunk[chunk.size() - 2] == 's') && (chunk[chunk.size() - 1] == 'Q')) {
                character = '\'';
                chunk[chunk.size() - 2] = 0;
            } else {
                character = chunk[chunk.size() - 1];
            }
            chunk[chunk.size() - 1] = 0;
            int length = stoi(chunk);
            for (int  i = 0; i < length; i++) {
                putchar(character); 
            }
        }
    }
}


#2



namespace 
{

static const std::unordered_map<std::string, char> abbreviations
{
    {"sp", ' '},
    {"bS", '\\'},
    {"sQ", '\''}
};

static const std::string newLine {"nl"};

std::string generateString(char symbol, const std::string& numOfSymbolsStr)
{
    const int numOfSymbols = std::stoi(numOfSymbolsStr);
    return std::string(numOfSymbols, symbol);
}

std::string instuctionToString(std::string& instruction)
{
    // fix for "Tree" and "Flamingo Fran" as its last instructions contains \n in the end.
    if (*instruction.rbegin() == '\n')
    {
        instruction.resize(instruction.size() - 1);
    }

    const size_t size { instruction.size() };
    if (newLine == instruction)
    {
        return "\n";
    }

    const bool containsAbbreviation = std::isalpha(instruction[size - 2]);

    return containsAbbreviation 
        ? generateString(abbreviations.at(instruction.substr(size - 2)), instruction.substr(0, size - 2))
        : generateString(instruction[size - 1], instruction.substr(0, size - 1));
}

}

int main()
{
    std::string instruction;
    std::string results;
    while (std::getline(std::cin, instruction, ' '))
    {
        results += instuctionToString(instruction);
    }

    std::cout << results << std::endl;
}

*/