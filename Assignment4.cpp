#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>



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
        void preOrderTraversalHelper(TreeNode*& node, std::vector<T>& Vector){
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

        void inOrderTraversalHelper(TreeNode*& node, std::vector<T>& Vector){
            if(!node){
                return;
            }
            inOrderTraversalHelper(node->left,Vector);
            for(int i = 0 ; i < node->amount; ++i){
                Vector.push_back(node->data);
            }
            inOrderTraversalHelper(node->right,Vector);
            return;

        }


        friend void destroyTree(TreeNode* node){ // recursicive that'll keep traversing a tree until its end and then delete it's leaf
            if(!node){
                return;
            }
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;

        }
        friend TreeNode* copyTreeHelp(TreeNode* other){
            if(other){
                TreeNode* one = new TreeNode(other->data);
                one->amount = other->amount;
                one->left = copyTreeHelp(other->left);
                one->right = copyTreeHelp(other->right);
                return one;

            }
            else{
                return nullptr;
            }
        }

    public:

        //BST(T value){
        //    root = new treeNode(value);
        //}
        BST() : root(nullptr){ // Constructor

        }
        ~BST(){ // Destructor
            destroyTree(root);
        }
        BST(const BST& other) : root(copyTreeHelp(other.root)){

        }
        
        //###################################################################################################################################################
        BST& operator=(const BST& other){ // Copy Assignment TO FNISH FOR THE LOVE OF GOD THIS IS WHAT IS WRONG 
            if(this == &other){
                return *this;
            }
            destroyTree(root);
            root = copyTreeHelp(other.root);
            return *this;
        }
        //###################################################################################################################################################
        
        BST(BST&& other) noexcept{ // Move Constructor
            root = other.root;
            destroyTree(other.root);
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

            preOrderTraversalHelper(root,ToGive);

            return ToGive;
        }
        std::vector<T> inOrderTraversal(){
            std::vector<T> ToGive;
            if(!root){
                return ToGive;
            }

            inOrderTraversalHelper(root,ToGive);

            return ToGive;
        }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> given){
    os << "[";
    for(T i : given){
        os << i << ", ";
    }
    os << "\b\b]";
    return os;
}


int testTreeSort(){
    srand(time(NULL));
    BST<int> George;
    for(int i = 0 ; i < 10000 ; ++i){
        George.insert(rand());
    }
    auto begTotal = std::chrono::high_resolution_clock::now();
    George.inOrderTraversal();
    auto endTotal = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTotal - begTotal).count();

}
    
int TestNormalSort(){
    srand(time(NULL));
    std::vector<int> George;
    for(int i = 0 ; i < 10000 ; ++i){
        George.push_back(rand());
    }
    auto begTotal = std::chrono::high_resolution_clock::now();
    std::sort(George.begin(),George.end());
    auto endTotal = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTotal - begTotal).count();
    }

int main(){
    int g;
    BST<int> George;
    George.insert(5);
    George.insert(2);
    George.insert(8);
    George.insert(4);
    std::vector<int> preOrder = George.preOrderTraversal();

    BST<std::string> ss ;
    ss.insert("Hi");
    ss.insert("bonjour");
    ss.insert("Konichiwa");
    ss.insert("GutenTag");

    
    std::cout << "-----------------------" << std::endl;
    
    std::cout << "tree : " << George <<std::endl;
    std::cout << "Pre Order : " <<George.preOrderTraversal() << std::endl;
    std::cout << "in Order :  " <<George.inOrderTraversal() << std::endl;
    
    std::cout << "-----------------------" << std::endl;
    
    std::cout << "tree : " << ss << std::endl;
    std::cout << "Pre Order : " << ss.preOrderTraversal() << std::endl;
    std::cout << "In Order :  " <<ss.inOrderTraversal() << std::endl;
    George.insert(10);
    BST<int> G2 = George;
    George.insert(10);
    G2 = George;
    std::cout << "tree : " << G2 <<std::endl;   
    std::cout << "tree : " << George <<std::endl;   

    std::cout << "\n\n\n Let's do some testing \n";
    std::cout << "tree sort time : \n \t 1 : " << testTreeSort() << " \n \t 2 : "<< testTreeSort()<< " \n \t 3 : "<< testTreeSort() << std::endl;
    std::cout << "Normal sort time : \n \t 1 : " << TestNormalSort() << " \n \t 2 : "<< TestNormalSort()<< " \n \t 3 : "<< TestNormalSort()<< std::endl;;
}   