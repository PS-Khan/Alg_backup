#include <iostream>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data) : data(data), left(nullptr), right(nullptr) {};

};

class BinarysearchTree{
    private:
        Node *root = nullptr;
        
        Node* insertHelper (Node *root, Node *node){
            int data = node->data;
            if (root == nullptr){
                root = node;
                return root;
            }else if(data < root->data){
                root->left = insertHelper(root->left, node);
            }else{
                root->right = insertHelper(root->right, node);
            }
            return root;
        }

        
        void displayHelper(Node *root){
            if(root != nullptr){
                displayHelper(root->left);
                std::cout<<root->data<< " ";
                displayHelper(root->right);
            }
        }
        
        bool searchHelper(Node *root, int data){
            if(root == nullptr){
                return false;
            }else if(root->data == data){
                return true;
            }else if (root->data > data){
                searchHelper(root->left, data);
            }else{
                searchHelper(root->right, data);
            }
            
        }
        
        
        Node* removeHelper(Node *root, int data){
            
            if (root == nullptr){
                return root;
            }else if (data < root->data){
                root->left = removeHelper(root->left, data);
            }
            else if (data > root->data){
                root->right = removeHelper(root->right, data);

            }else{ //node found
                if(root->left == nullptr && root->right == nullptr){
                    root = nullptr;
                }
                else if(root->right != nullptr){
                    root->data = successor(root);
                    root->right = removeHelper(root->right, root->data);
                }else {
                    root->data = predecessor(root);
                    root->left = removeHelper(root->left, root->data);
                }
            }
            return root;
        }
        
        int successor(Node *root){
            root = root->right;
            while (root->left != nullptr)
            {
                root = root->left;
            }
            
            return root->data;
        }
        
        int predecessor(Node *root){
            root = root->left;
            while (root->right != nullptr)
            {
                root = root->right;
            }
            
            return root->data;
        }
    
    public:

        void insert(Node *node){
            root = insertHelper(root, node);
        }
        void display(){
            displayHelper(root);
        }
        bool search(int data){
            return searchHelper(root, data);
        }
        
        void remove (int data){
            if(search(data) == true){
                removeHelper(root, data);
            }else{
                std::cout<< data << " data is not found";
            }
        }
        


    
};

int main(){

    BinarysearchTree tree;
    Node node = Node(5);
    Node node2 = Node(1);
    Node node3 = Node(9);
    Node node4 = Node(2);
    Node node5 = Node(7);
    Node node6 = Node(3);
    Node node7 = Node(6);
    Node node8 = Node(4);
    Node node9 = Node(8);


    
    tree.insert(&node);
    tree.insert(&node2);
    tree.insert(&node3);
    tree.insert(&node4);
    tree.insert(&node5);
    tree.insert(&node6);
    tree.insert(&node7);
    tree.insert(&node8);
    tree.insert(&node9);
    std::cout<<tree.search(7)<<std::endl;

    tree.remove(1);

    tree.display();
    

    

    return 0;
}