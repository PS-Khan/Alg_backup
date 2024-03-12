#include <iostream>
#include <string>
#include <vector>
#include <list>
struct Node {
    int value;
    char name;
};

class Graph {
    private:
        std::vector<std::vector<int>> matrix;
        std::list<std::list<Node>> list;
        
    public: 

        void add_node(Node node){
            //list
            std::list<Node> list_tmp;
            list_tmp.push_back(node);
            list.push_back(list_tmp);
            std::vector<int> tmp;

            //matrix
            int resize = list.size();
            tmp.assign(resize,0);
            for(int i = 0; i < (int)matrix.size(); i++){
                if((int) matrix[i].size() < resize){
                    matrix[i].push_back(0);
                }
            }
            matrix.push_back(tmp);
            
        }

        void display_matrix(){
            std::cout<<"  ";
            auto temp_list = list;
            for (auto &item : temp_list){
                std::cout<<item.front().name<<" ";
            }
            std::cout<<std::endl;
            for(int i = 0; i < (int)matrix.size(); i++){
                std::cout<< temp_list.front().front().name<<" ";
                temp_list.pop_front();
                for(int j = 0; j < (int)matrix[i].size(); j++){
                    std::cout<< matrix[i][j] <<" ";
                }
                std::cout<<std::endl;
            }
        }

        void display_list(){
            for(auto &item : list){
                for(auto &i : item){
                    std::cout<<i.name <<"->";
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
        }

        void add_edge(const int src, const int dst){
            std::list<std::list<Node>>::iterator it_src = list.begin(), it_dst = list.begin();
            std::advance(it_src, src);
            std::advance(it_dst, dst);

            (*it_src).push_back((*it_dst).front());

            matrix[src][dst] = 1;
        }

        bool check_edge_matrix(const int src, const int dst){
            return matrix[src][dst] == 1;
        }


        ~Graph(){
            for (auto item : list){
                item.clear();
            }
            for (auto item : matrix){
                item.clear();
            }
            list.clear();
            matrix.clear();
        }



};


int main(){
    Graph graph;
    graph.add_node({1,'A'});
    graph.add_node({2,'B'});
    graph.add_node({3,'C'});

    graph.add_edge(0, 2);

    graph.display_matrix();
    graph.display_list();
    
    return 0;
}