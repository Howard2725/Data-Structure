#include <iostream> 
#include <stack>
#include <omp.h>
#include <random>
using namespace std;


// 定义BST的节点  
class TreeNode {

private:
    int val;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode() {
    }
    friend class BST;
};

// BST类  
class BST {
private:
    TreeNode* root;

public:
    BST() : root(nullptr) {}

    // 插入新值  
    void insert(int val) {
        root = insertRec(root, val);
    }

    // 递归插入  
    TreeNode* insertRec(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }

        if (val < root->val) {
            root->left = insertRec(root->left, val);
        }
        else if (val > root->val) {
            root->right = insertRec(root->right, val);
        }

        // 如果值相等，这里简单处理为不插入，可修改  
        return root;
    }

    // 查找值  
    bool search(int val) {
        return searchRec(root, val);
    }

    // 递归查找  
    bool searchRec(TreeNode* root, int val) {
        if (root == nullptr) {
            return false;
        }

        if (root->val == val) {
            return true;
        }

        if (val < root->val) {
            return searchRec(root->left, val);
        }
        else {
            return searchRec(root->right, val);
        }
    }
  

    // 递归中序遍历  
    void inorderTraversalRec(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversalRec(root->left);
            //cout << root->val << " ";
            inorderTraversalRec(root->right);
        }
    }
    // 中序遍历BST  
    void inorderTraversal() {
        inorderTraversalRec(root);
        //cout << endl;
    }


    // 前序遍历BST  
    void preorderTraversal() {
        preorderTraversalRec(root);
        cout << endl;  
    }
    // 递归前序遍历  
    void preorderTraversalRec(TreeNode* root) {
        if (root != nullptr) {
            cout << root->val << " "; // 访问根节点  
            preorderTraversalRec(root->left); // 递归遍历左子树  
            preorderTraversalRec(root->right); // 递归遍历右子树  
        }
    }


    // 后序遍历BST  
    void postorderTraversal() {
        postorderTraversalRec(root);
        cout << endl; 
    }
    // 递归后序遍历  
    void postorderTraversalRec(TreeNode* root) {
        if (root != nullptr) {
            postorderTraversalRec(root->left); // 递归遍历左子树  
            postorderTraversalRec(root->right); // 递归遍历右子树  
            cout << root->val << " "; // 访问根节点  
        }
    }

    //非递归中序遍历
    void inorderTraversal_alter() {
        inorderTraversal_alterRec(root);
    }
    void inorderTraversal_alterRec(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr != nullptr || !stk.empty()) {
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            //cout << curr->val << " ";
            curr = curr->right;
        }
        //cout << endl;
    }

};

int main() {
    BST bst;
    cout << "————请按 Enter 开始遍历————";
    cin.get();
    cout << "循环次数\t" << "递归遍历\t" << "非递归遍历" << endl;
    for (int n = 10000; n < 100000; n += 10000) {
        srand(time(NULL));
        for (int i = 0; i < 100; i++) {
            bst.insert(rand() % 1000);
        }

        double start = 0, end = 0;

        //递归中序遍历所用时间
        start = omp_get_wtime();
        for (int i = 0; i < n; i++) {
            bst.inorderTraversal();
        }
        end = omp_get_wtime();
        cout << n << "\t\t" << end - start;

        //中序遍历所用时间
        start = omp_get_wtime();
        for (int i = 0; i < n; i++) {
            bst.inorderTraversal_alter();
        }
        end = omp_get_wtime();
        cout << "\t" << end - start << endl;
    }

    return 0;
}