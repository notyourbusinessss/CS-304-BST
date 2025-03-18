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
        public:
        TreeNode* root;
        private:
        void insertHelper(TreeNode*& node, const T& value){
            if(!node){
                node = new TreeNode(value);
            }
            else if (value < node->data)
            {
                insertHelper(node->left,value);
            }
            else if (value > node->data){
                insertHelper(node->right,value);
            }
            else if(value == node->data){
                node->amount += 1;
            }
        }
        void preOrderTraversalHelper(TreeNode* node, std::vector<T>& Vector){
            if(!node){
                return;
            }
            for(int i = 0 ; i < node->amount; ++i){
                Vector.push_back(node->data);
            }
            preOrderTraversalHelper(node->left,Vector);
            preOrderTraversalHelper(node->right,Vector);
            return;

        }


        void destroyTree(TreeNode* node){ // recursicive that'll keep traversing a tree until its end and then delete it's leaf
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
        void insert(const T& value){ //this 
            if(!root){
                root = new TreeNode(value);
            } 
            else if (value < root->data)
            {
                insertHelper(root->left,value); // call the inserthelper for right tree
            }
            else if (value > root->data){
                insertHelper(root->right,value); // call the inserthelp for left tree
            }
            else if(value == root->data){
                root->amount += 1;
            }
            

        }
        static std::ostream& InOrder(std::ostream &out,TreeNode* cur){ //just a recursive InOrder for printing it like an array
            if (cur)
            {
                InOrder(out, cur->left);
                for(int i = 0 ; i < cur->amount ; ++i){
                    out << cur->data << ", " ;
                }
                InOrder(out, cur->right);
            }
            return out;
        }
        



        friend std::ostream& operator<<(std::ostream& os,const BST<T>& given){ // here very important, make friend, have a const BST<T>& <- reference is important
            return InOrder(os,given.root) <<"\b\b ";

        
        }


        std::vector<T> preOrderTraversal(){
            std::vector<T> ToGive;
            if(!root){
                return ToGive;
            }
            for(int i = 0 ; i < root->amount; ++i){
                ToGive.push_back(root->data);
            }
            preOrderTraversalHelper(root->left,ToGive);
            preOrderTraversalHelper(root->right,ToGive);
            return ToGive;
        }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> given){
    os << "[";
    for(int i : given){
        os << given[i] << ", ";
    }
    os << "\b\b]";
    return os;
}

int main(){
    int g;
    BST<int> George;
    George.insert(5);
    George.insert(2);
    George.insert(8);
    George.insert(4);
    std::vector<int> preOrder = George.preOrderTraversal();

    std::cout << George <<std::endl;
    std::cout << preOrder;
}