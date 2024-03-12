#include <iostream>
#include <unordered_map>
#include <string>


struct cell{
    char op;
    int v1, v2;
    struct cell *p_cell_1 = nullptr, *p_cell_2 = nullptr;
    bool  calc = false;
    int  val;

    void compute_val(void)
    {
        switch(op)
        {
            case 'V': 
                val = v1     ;
                break;
            case 'A':
                val = v1 + v2; 
                break;
            case 'S': 
                val = v1 - v2;
                break;
            default :
                val = v1 * v2;
                break;
        }
        calc = true;
    }
    int eval() 
    {
        if( calc ) { return val;}
        if( p_cell_1   ) { v1 = p_cell_1->eval(); }
        if( p_cell_2   ) { v2 = p_cell_2->eval(); }
            
        compute_val();   
        return val;
    }
};

int main() {
    int n ;
    std::cin>> n; std::cin.ignore();
    cell *graph = new cell[n];

    for (int i = 0; i < n; i++) 
    {
        std::string op, arg1, arg2;
        std::cin>>op>>arg1>>arg2;std::cin.ignore(); 
        graph[i].op = op[0];
        if(arg1[0] == '$'){
            graph[i].p_cell_1 = &graph[stoi(arg1.substr(1))];
        }else{
            graph[i].v1 = stoi(arg1); graph[i].p_cell_1=nullptr;
        }
        if(arg2[0] == '$'){
            graph[i].p_cell_2 = &graph[stoi(arg2.substr(1))];
        }else if(arg2[0] != '_'){
            graph[i].v2 = stoi(arg2); graph[i].p_cell_2=nullptr;
        }
        if(graph[i].p_cell_1 == nullptr && graph[i].p_cell_2 == nullptr ) { graph[i].compute_val(); }
    }

    for (int i = 0; i < n; i++)
    { 
        std::cout<<graph[i].eval() << std::endl;           
    }
 
    return 0;
}