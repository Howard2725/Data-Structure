#include <iostream> 
#include<string>
#include<sstream>
#include<vector>
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

	int maxDepthRec(TreeNode* root) {
		if (root == nullptr) {
			return 0; // 空树深度为0  
		}
		int leftDepth = maxDepthRec(root->left); // 左子树的深度  
		int rightDepth = maxDepthRec(root->right); // 右子树的深度  

		// BST的深度是左右子树深度的最大值加1  
		return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
	}

	int maxDepth() {
		return maxDepthRec(root);
	}

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

	
};

int main() {

	int n = 0;
	cin >> n;
	cin.ignore();
	

	for (int i = 0; i < n; i++) {
		BST bst;

		string line;
		vector<int> numbers;

		// 读取一整行  
		getline(std::cin, line);

		// 使用istringstream来分割并读取整数  
		istringstream iss(line);
		int num;
		while (iss >> num) { // 使用>>操作符从istringstream中读取整数  
			numbers.push_back(num); // 将读取的整数添加到vector中  
		}

		// 输出读取的整数，验证结果  
		for (int num : numbers) {
			bst.insert(num);
		}

		cout << bst.maxDepth() << endl;

	}

	return 0;
}