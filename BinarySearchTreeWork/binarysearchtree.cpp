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
    TreeNode *root;
    void preorder(TreeNode *start){//V L R
        if(start!=NULL){
            cout<<start->data<<" ";
            preorder(start->left);
            preorder(start->right);
        }
        else return;
    }
    void inorder(TreeNode *start){ // L V R 
        if (start !=NULL ){
            inorder(start->left);
            cout<< start->data<< " ";
            inorder(start->right);
        }
        else return;
    }
    void postorder(TreeNode *start){//L R V
        if(start!=NULL){
            postorder(start->left);
            postorder(start->right);
            cout<< start->data<<" ";
        }
        else return;
    }
    public:
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
    int height(TreeNode *node){
        if(node!=NULL){
            int left= height(node->left);
            int right= height(node->right);
            return 1+ max(left, right);
        }
        else
            return -1;
    }
    /*void preorder(TreeNode *start){//V L R
        if(start!=NULL){
            cout<<start->data<<" ";
            preorder(start->left);
            preorder(start->right);
        }
        else return;
    }
    void inorder(TreeNode *start){ // L V R 
        if (start !=NULL ){
            inorder(start->left);
            cout<< start->data<< " ";
            inorder(start->right);
        }
        else return;
    }
    void postorder(TreeNode *start){//L R V
        if(start!=NULL){
            preorder(start->left);
            preorder(start->right);
            cout<< start->data<<" ";
        }
        else return;
    }*/
    void preorder(){
         preorder(root);
   }
    void inorder(){
        inorder(root);
   }
    void postorder(){
        postorder(root);
   }
   
   TreeNode* find(TreeNode* start, int data) {
        if (start == NULL || start->data == data) {
            return start;
        } else if (data < start->data) {
            return find(start->left, data);
        } else {
            return find(start->right, data);
        }
    }
    TreeNode *find(int data){
        return find(root, data);
   }

    TreeNode *getmin(TreeNode *start){
        while(start!=NULL && start->left!=NULL)
            start=start->left;
        return start;
    
    }
    TreeNode *getmin(){
        return getmin(root);
    }

    TreeNode *getmax(TreeNode *start){
        while(start!=NULL && start->right!=NULL)
            start=start->right;
        return start;
    }
    TreeNode *getmax(){
    return getmax(root);
    }


    TreeNode *remove(TreeNode *start, int data) {
        if (start == NULL) return NULL;

        if (data < start->data) {
            start->left = remove(start->left, data);
        } else if (data > start->data) {
            start->right = remove(start->right, data);
        } else {
            // Node to be deleted found
            if (start->left != NULL && start->right != NULL) { // Two children
                TreeNode *temp = getmin(start->right);
                start->data = temp->data; // Replace with inorder successor
                start->right = remove(start->right, temp->data);
            } else {
                TreeNode *temp = start;
                if (start->left == NULL) {
                    start = start->right;
                } else if (start->right == NULL) {
                    start = start->left;
                }
                delete temp;
            }
        }
        return start;
    }
    /*TreeNode *remove(TreeNode *start, TreeNode deleted){
        if(start==NULL) return NULL;
        if(start->data= deleted){
            if(start->left==NULL && start->right==NULL){
                return NULL;
            }
            if(start->right!=NULL){
                start->data=getmin(start->right);
                start->right=remove(start->right, getmin(start->right));
                remove(start(getmin(start->right)));
                return start;
            }
            start->data=getmax(start->left);
            start->left=remove(start->left, getmax(start->left));
            return start;

        }
        if(start->data< deleted){
            start=remove(start->right, deleted);
            return start;
        }
        start=remove(start->left, deleted);
        return start;
    }*/
    void remove(int data) {
        root = remove(root, data);
    }
    /*TreeNode *mirror(TreeNode *start){
        if(start!=0){
            mirror(start->left);
            mirror(start->right);
            TreeNode *temp= start->left;
            start->left=start->right;
            start->right=temp;
        }
        return start;
    }*/
   TreeNode *mirror(TreeNode *start){
    if(start==NULL) return start;
    mirror(start->left);
    mirror(start->right);
    TreeNode *tmp=start->left;
    start->left=start->right;
    start->right=tmp;
    return start;
   }
    
    void mirror(){
        root=mirror(root);
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

    int cntNode(TreeNode *start){
        if(start==NULL) return 0;
        return 1+ cntNode(start->left)+ cntNode(start->right);
    }
    int cntNode(){
        return cntNode(root);
    }
    int numberOfParents(TreeNode *start){
        if(start==NULL) return 0;
        if(start->left==NULL && start->right==NULL) return 0;
        int leftchild= numberOfParents(start->left);
        int rightchild= numberOfParents(start->right);
        if(start->left != NULL || start->right != NULL) 
            return 1 + leftchild + rightchild;
        return leftchild + rightchild;

    }
    int numberOfParents(){
        return numberOfParents(root);
    }
    
};


int main(){
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(11);
    bst.insert(9);
    bst.insert(20);
    bst.insert(1);
    bst.insert(98);
    cout<<"inorder travel: ";
    bst.inorder();
    cout<< endl;
    cout<<"preorder travel: ";
    bst.preorder();        
    cout<< endl;
    cout<<"postorder travel: ";
    bst.postorder();
    cout<< endl;
    cout<< bst.find(0)<<endl;
    cout<<"MAX : "<<bst.getmax()->data<<endl;
    cout<<"MIN : "<<bst.getmin()->data<<endl;
    
    bst.mirror();
    cout<<"MIRROORR: ";
    bst.inorder();
    cout<< endl;
    
    bst.remove(11);
    cout<<"inorder travel: ";
    bst.inorder();
    cout<< endl;
    
    BinarySearchTree bst1;
    BinarySearchTree bst2;

    bst1.insert(10);
    bst1.insert(12);
    bst1.insert(7);
    bst1.insert(11);
    bst1.insert(15);
    
    bst2.insert(11);
    bst2.insert(13);
    bst2.insert(6);
    
    cout<< bst1.isSameSkeleton(bst2)<<endl;

    cout<<bst1.sameBST(bst2)<<endl;

    cout<< bst1.cntNode()<<endl;
    cout<< bst1.numberOfParents()<<endl;





  





    return 0;

}
