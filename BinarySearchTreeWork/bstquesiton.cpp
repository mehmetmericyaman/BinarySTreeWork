#include <iostream>

using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data= 0, TreeNode *left = NULL, TreeNode *right= NULL): data(data), left(left), right(right){ }

};
class BinarySearchTree{
    public:
    TreeNode *root;
    BinarySearchTree(TreeNode *root = NULL) : root(root){  }
    bool isEmpty()const { return root == NULL; }
    TreeNode *getRoot()const{ return root; }
    
    TreeNode *insert(TreeNode * start, int data){
        if(start!=nullptr){
            if(data<start->data)
                start->left= insert(start->left, data);
            else
                start->right= insert(start->right, data);
        }
        else
            return new TreeNode(data);
        return start;
    }
    void insert(int data){
        root= insert(root, data);
    }
    bool isSameSkeleton(TreeNode *r1, TreeNode*r2){
        if(r1==NULL && r2==NULL) return true;
        if(r1==NULL || r2==NULL) return false;
        return isSameSkeleton(r1->left, r2->left) && isSameSkeleton(r1->right, r2->right);
    }
    bool isSameSkeleton(BinarySearchTree &bst2) {
        return isSameSkeleton(this->root, bst2.root);
    }
    
    bool sameBST(TreeNode *r1, TreeNode *r2){
        if(r1==NULL && r2==NULL) return true;
        if(r1==NULL || r2==NULL) return false;
        if(r1->data != r2->data) return false;
        return(sameBST(r1->left, r2->left) && sameBST(r1->right, r2->right));
    }
    bool sameBST(BinarySearchTree &bst2) {
        return sameBST(this->root, bst2.root);
    }
    void preorder(TreeNode *start){//v l r
        if(start==NULL) return;
        cout<<start->data<<" ";
        preorder(start->left);
        preorder(start->right);
        
    }
    void preorder(){
        preorder(root);
    }



};
int main(){
    BinarySearchTree bst1;
    BinarySearchTree bst2;

    bst1.insert(10);
    bst1.insert(12);
    bst1.insert(7);
    
    bst2.insert(11);
    bst2.insert(13);
    bst2.insert(6);
    
    cout<< bst1.isSameSkeleton(bst2)<<endl;

    cout<<bst1.sameBST(bst2)<<endl;
    
    bst1.preorder();






    return 0;
}