#include <iostream>
#include <vector>



template<typename T>
class BST {
    
private:
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };
    TreeNode* root;
    void insertHelper(TreeNode*& node, const T& value);
    void preOrderTraversalHelper(TreeNode* node, std::vector<T>& sortedVector);
    void destroyTree(TreeNode* node);
    TreeNode* copyTree(TreeNode* other);

public:
    BST(){ // Constructor

    }
    ~BST(){ // Destructor

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

    }
    std::vector<T> preOrderTraversal(){

    }
};
