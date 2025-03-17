#include <iostream>
#include <vector>



template<typename T>
class BST {
        
    private:
        struct TreeNode {
            T data;
            TreeNode* left;
            TreeNode* right;
            int amount;
            //this is the constructor
            TreeNode(const T& value) : data(value), left(nullptr), right(nullptr), amount(1) {}
        };
        TreeNode* root;
        void insertHelper(TreeNode*& node, const T& value){
            if(!node){
                node = new TreeNode(value);
            }
            else if (value < node->data)
            {
                insertHelper(node->left,value);
            }
            else if (value > node->data){
                insertHelper(node->data);
            }
            else if(value == node->data){
                ++node->amount;
            }
        }
        void preOrderTraversalHelper(TreeNode* node, std::vector<T>& sortedVector);
        void destroyTree(TreeNode* node){
            if(!node){
                return;
            }
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;

        }
        TreeNode* copyTree(TreeNode* other);

    public:

        BST(T value){

        }
        BST() : root(nullptr){ // Constructor

        }
        ~BST(){ // Destructor
            destroyTree(root);
        }
        BST(const BST& other){ // Copy Constructor

        } 
        BST& operator=(const BST& other){ // Copy Assignment

        }
        BST(BST&& other) noexcept{ // Move Constructor
            
        }
        BST& operator=(BST&& other) noexcept{ // Move Assignment
            
        }
        void insert(const T& value){
            if(!root){
                root = value;
            } 
            else if (value < root->data)
            {
                insertHelper(root->left,value);
            }
            else if (value > root->data){
                insertHelper(root->data);
            }
            else if(value == root->data){
                ++root->amount;
            }
            

        }
        std::ofstream operator<<();
        std::vector<T> preOrderTraversal(){

        }
};


int main(){
    int g;
}