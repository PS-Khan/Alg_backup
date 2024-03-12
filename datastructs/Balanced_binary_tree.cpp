#include <iostream>
#include <vector>


//rewrite
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data) : data(data), left(nullptr), right(nullptr) {};

};

class BinarysearchTree{
    protected:
        
        
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

        void display_tree_helper(Node *root){
            if(root != nullptr){
                if(root->left !=nullptr){
                    std::cout<<root->left->data<<" ";
                }
                if(root->right !=nullptr){
                    std::cout<<root->right->data<<" ";
                }
                if(root->right !=nullptr || root->left !=nullptr){
                    std::cout<<"\n";
                }
                if(root->left !=nullptr){
                    display_tree_helper(root->left);
                }
                if(root->right !=nullptr){
                    display_tree_helper(root->right);
                }
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

        void storehelper(Node *root, std::vector<Node*> &nodes){
            if(root == nullptr){
                return ;
            }
            storehelper(root->left, nodes);
            nodes.push_back(root);
            storehelper(root->right, nodes);

        }

        
    
    public:
        Node *root = nullptr;
        void insert(Node *node){
            root = insertHelper(root, node);
        }
        void display(){
            displayHelper(root);
        }
        void display_tree(){
            std::cout<<"\n"<<root->data<<std::endl;
            display_tree_helper(root);
        }
        bool search(int data){
            return searchHelper(root, data);
        }

        int check_balance(Node *root){
            if(root == nullptr){
                return 0;
            }
            int left_sub_tree_h = 0 ;
            int right_sub_tree_h = 0;

            left_sub_tree_h = check_balance(root->left);
            if(left_sub_tree_h == -1){
                return -1;
            }

            right_sub_tree_h = check_balance(root->right);
            if(right_sub_tree_h == -1){
                return -1;
            }

            if(std::abs(right_sub_tree_h - left_sub_tree_h) > 1){
                return -1;
            }
            return std::max(left_sub_tree_h, right_sub_tree_h) + 1; 
        }
        
        void remove (int data){
            if(search(data) == true){
                removeHelper(root, data);
            }else{
                std::cout<< data << " data is not found";
            }
        }
        std::vector<Node*> storeNodes (Node *root){
            std::vector<Node*> nodes;
            storehelper(root, nodes);
            return nodes;
        }

         
        /* Recursive function to construct binary tree */
        Node* buildTreeUtil(std::vector<Node*> &nodes, int start,int end)
        {
            // base case
            if (start > end)
                return NULL;
        
            /* Get the middle element and make it root */
            int mid = (start + end)/2;
            Node *root = nodes[mid];
        
            /* Using index in Inorder traversal, construct
            left and right subtress */
            root->left  = buildTreeUtil(nodes, start, mid-1);
            root->right = buildTreeUtil(nodes, mid+1, end);
        
            return root;
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
    //tree.display_tree();
    std::cout<<tree.check_balance(tree.root);
    std::cout<<"NOdes v:\n";
    std::vector<Node*> nodes  = tree.storeNodes(tree.root); 
    for(int i = 0 ;  i < (int)nodes.size(); i ++){
        std::cout<< nodes[i]->data<<std::endl;
    }

    tree.root = tree.buildTreeUtil(nodes,0, (int)nodes.size()-1);
    std::cout<<"check:\n";
    std::cout<<tree.check_balance(tree.root);

    return 0;
}