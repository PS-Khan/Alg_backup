#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>

struct Node {
    int value;
    char name;
};

class Graph {
    private:
        std::vector<std::vector<int>> matrix;
        std::list<std::list<Node>> list;

        void deapthFS_helper(int src, bool *visited){
            if(visited[src]){
                return;
            }else{
                visited[src] = true;
                std::list<std::list<Node>>::iterator it_src = list.begin();
                std::advance(it_src, src);
                std::cout<<"Visited: "<<(*it_src).front().name<<" ";
                for(int i = 0; i < (int)matrix.size(); i++ ){
                    if(matrix[src][i] == 1){
                        deapthFS_helper(i,visited);
                    }
                }
            }
        }
        
    public: 

        void add_node(Node node){
            //list
            std::list<Node> list_tmp;
            list_tmp.push_back(node);
            list.push_back(list_tmp);

            //matrix
            std::vector<int> tmp;
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

        void delete_item(int src){
            int row_size =  matrix[0].size();
            int column_size = matrix.size();
            for (int row = 0; row < row_size; row++) {
                for (int i = src; i < row_size - 1; i++) {
                    matrix[row][i] = matrix[row][i + 1];
                }
                matrix[row].pop_back();
            }
            matrix.erase(matrix.begin() + src);
            
            //list
            std::list<std::list<Node>>::iterator it_src = list.begin();
            std::advance(it_src, src);
            char name = (*it_src).front().name;
            list.erase(it_src);

            for (auto &sub_list : list) {
                sub_list.remove_if([&name](const Node &item) { return item.name == name; });
            }
            
            
            
        }

        

        void deapthFsearch(int src){
            bool visited[list.size()]={false};
            deapthFS_helper(src, visited);
        }

        void breadthFsearch(int src){
            bool visited[list.size()]={false};
            std::queue<int> q;
            visited[src] = true;
            q.push(src);
            while(!q.empty()){
                src = q.front();
                q.pop();
                std::list<std::list<Node>>::iterator it_src = list.begin();
                std::advance(it_src, src);
                std::cout<<"Visited: "<<(*it_src).front().name<<" ";
               

                for(int i = 0; i < (int)matrix.size(); i++){
                    if(matrix[src][i] == 1 && !visited[i]){
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
            
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
    graph.add_node({4,'D'});
    graph.add_node({5,'E'});

    

    graph.add_edge(0, 2);
    graph.add_edge(0, 4);
    graph.add_edge(2, 4);
    graph.add_edge(2, 1);
    graph.add_edge(2, 3);
    graph.add_edge(1, 3);
    graph.add_edge(3, 4);

    graph.delete_item(1);

    graph.display_matrix();
    graph.display_list();
    graph.deapthFsearch(0);
    std::cout<<std::endl;
    graph.breadthFsearch(0);
    
    return 0;
}