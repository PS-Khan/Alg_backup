#include <iostream>
#include <queue>
#include <cstring>
class Node{
    public:
        char data;
        Node(char data){
            Node::data = data;
        }
};

class Graph{
    private:
        int **matrix = nullptr;
        int nodes, names_index;
        char nodes_names[];

        int** create_matrix(int nodes) {
    
            Graph::nodes = nodes;
            // Allocate memory for the array of pointers
            int **matrix = (int**)calloc(nodes, sizeof(int*));

                if (!matrix) {
                    return nullptr;
                }

                // Allocate memory for each row
                for (int i = 0; i < nodes; ++i) {
                    matrix[i] = (int*)calloc(nodes, sizeof(int));

                    // Check if memory allocation was successful
                    if (!matrix[i]) {
                        for (int j = 0; j < i; j++) {
                            free(matrix[j]);
                        }
                        free(matrix);
                        return nullptr;
                    }
                }

                return matrix;
        }

    public:

    Graph(int nodes){
        Graph::nodes = nodes;
        Graph::matrix = create_matrix(nodes);
        Graph::nodes_names[nodes] = {};
        Graph::names_index = 0;
    }

    

    void add_node (Node node){
        if(names_index<nodes){
            nodes_names[names_index] = node.data;
            names_index++;
        }
    }

    void add_edge (int src , int dst){
        if(matrix != nullptr){
            matrix[src][dst] = 1;
        }else{
            std::cout<<"matrix is not initialized"<<std::endl;
        }
       
    }

    bool checkEdge (int src , int dst) {
        if(matrix != nullptr){
            if(matrix[src][dst] == 1){
                return true;
            }else{
                return false;
            }
            
        }else{
            std::cout<<"matrix is not initialized"<<std::endl;
        }
    }

    void dFSHelper (int src, bool *visited){
        if (visited[src] == true){
            return;
        }else{
            visited[src] = true;
            std::cout<<nodes_names[src]<<" visited"<<std::endl;
        }

        for(int i = 0; i < nodes; i++ ){
            if(matrix[src][i] == 1){
                dFSHelper (i, visited);
            }
        }
        return;
    }

    void depthFirst_search(int src){
        bool visited[nodes]={false};
        dFSHelper (src, visited);

    }

    void breadthFirst_search(int src){
        std::queue<int> queue;
        bool visited[nodes]={false};

        queue.push(src);
        visited[src] = true;

        while(queue.size() !=0){
            src = queue.front();
            queue.pop();
            std::cout<<nodes_names[src]<<" visited"<<std::endl;

            for(int i = 0; i < nodes; i++ ){
                if(matrix[src][i] == 1 && !visited[i]){
                   queue.push(i);
                   visited[i] = true;
                }
            }
        }
    }

    void print () {
        std::cout<<"  ";
        for(int i = 0; i<names_index; i++){
            std::cout<<nodes_names[i]<<" ";
        }
        std::cout<<std::endl;
        for(int i = 0; i<nodes ; i++){
            std::cout<<nodes_names[i]<<" ";
            for(int j = 0; j<nodes ; j++){
                std::cout<< matrix[i][j] << " ";
            }
            std::cout<<std::endl;
        }

    }

    ~Graph() {
        // Free allocated memory for each row
        for (int i = 0; i < nodes; ++i) {
            free(matrix[i]);
        }
        // Free memory for the array of pointers
        free(matrix);
    }
};



int main(){

    Graph graph = Graph(5);
    graph.add_node(Node('A'));
    graph.add_node(Node('B'));
    graph.add_node(Node('C'));
    graph.add_node(Node('D'));
    graph.add_node(Node('E'));

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(1,4);
    graph.add_edge(2,3);
    graph.add_edge(2,4);
    graph.add_edge(4,0);
    graph.add_edge(4,2);

    graph.print();

    graph.depthFirst_search(0);
    std::cout<<std::endl;
    graph.breadthFirst_search(1);
    
    
    return 0;
}