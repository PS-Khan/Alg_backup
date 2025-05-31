#include <iostream>
#include <queue>

class Graph {
    private:
        int nodes = 0;


    public:
        struct Node{
            char name;
            int nodes = 0;
            struct Node **connections;
        };
        Graph(){

        };

        Node create_node(char name){
            Node node;
            node.name = name;
            node.connections = new Node*[1];
            node.connections[0] = nullptr; 
            this->nodes++;
            return node;
        }

        void connect_nodes(Node *a, Node *b){
            Node **tmp = a->connections;
            a->nodes++;
            a->connections = new Node*[a->nodes+1];//because of index; if nodes = 1 , it will create  [0]
            for (int i = 0; i < a->nodes-1; ++i) {
                a->connections[i] = tmp[i];
            }
            delete[] tmp;

            a->connections[a->nodes-1] = b;
            a->connections[a->nodes] = nullptr;
        }

        void show_connections(Node *node){
            Node **tmp = node->connections;
            int i = 0;
            while(tmp[i] != nullptr){
                std::cout<<tmp[i]->name<<" ";
                i++;
            }
            std::cout<<std::endl;
        }

        void del_connection(Node *a, Node *b) {
            Node **tmp = a->connections;
            a->connections = new Node*[a->nodes];

            int j = 0; 
            for (int i = 0; i < a->nodes; ++i) {
                if (tmp[i]->name != b->name) {
                    a->connections[j] = tmp[i];
                    j++;
                }
            }
            a->connections[j] = nullptr;
            delete[] tmp;
            a->nodes--; 
        }
        private:
            void DeapthFs_helper(char *visited, Node *node, int index){
                for(int i = 0; i < nodes; i++){
                    if(visited[i] == node->name){
                        return;
                    }
                }
                visited[index] = node->name;
                index++;
                std::cout<< "Visited: "<<node->name<<" ";
                for(int i = 0; i < node->nodes; i++){
                    DeapthFs_helper(visited, node->connections[i], index);
                }
            }
        public:

        void DeapthFsearch(Node &node){
            char visited[nodes];
            int index = 0;
            DeapthFs_helper(visited, &node, index);
            std::cout<<std::endl;
        }

        void BreadthFsearch(Node &node){
            char visited[nodes];
            std::queue<Node> q;
            int index = 0;

            q.push(node);
            visited[index] = node.name;
            
            while(!q.empty()){
                Node tmp_node = q.front();
                std::cout<< tmp_node.name <<" visited; ";
                q.pop();
                for(int i = 0; i < tmp_node.nodes; i++){
                    bool add = true;
                    for(int j = 0; j < nodes ; j++){
                        if(visited[j] == tmp_node.connections[i]->name){
                            add = false;
                            break;
                        }
                    }
                    if(add){
                        q.push(*tmp_node.connections[i]);
                        index++;
                        visited[index] = tmp_node.connections[i]->name;
                    }
                }
            }

        }


};

int main(){
    Graph graph;
    Graph::Node node_1 = graph.create_node('A');
    Graph::Node node_2 = graph.create_node('B');
    Graph::Node node_3 = graph.create_node('C');
    Graph::Node node_4 = graph.create_node('D');
    Graph::Node node_5 = graph.create_node('E');
    Graph::Node node_6 = graph.create_node('F');
    Graph::Node node_7 = graph.create_node('K');
    Graph::Node node_8 = graph.create_node('L');

    graph.connect_nodes(&node_1, &node_2);
    graph.connect_nodes(&node_1, &node_8);
    graph.connect_nodes(&node_1, &node_4);
    graph.connect_nodes(&node_1, &node_3);
    graph.connect_nodes(&node_2, &node_4);
    graph.connect_nodes(&node_4, &node_1);
    graph.connect_nodes(&node_4, &node_5);
    graph.connect_nodes(&node_5, &node_7);
    graph.connect_nodes(&node_7, &node_6);
    graph.connect_nodes(&node_8, &node_7);
    graph.connect_nodes(&node_3, &node_5);
    graph.connect_nodes(&node_2, &node_6);

    graph.del_connection(&node_1, &node_2);

    graph.DeapthFsearch(node_1);
    std::cout<<std::endl;
    graph.BreadthFsearch(node_1);

    //graph.show_connections(&node_1);
}