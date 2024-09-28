#include<iostream>  
using namespace std;



class tree{

public:
	char arr[100];

	tree() { // 构造函数  
		// 初始化arr数组中的所有元素为'0'  
		for (int i = 0; i < 100; ++i) {
			arr[i] = '0';
		}		
	}


	//与其他节点之间的联系
	int parent(int pos) {
		return (pos - 1) / 2;
	}

	int leftchild(int pos) {
		return 2 * pos + 1;
	}

	int rightchild(int pos) {
		return 2 * pos + 2;
	}

	bool insertch(char ch, int i) {
		if (arr[i] == '0') {
			arr[i] = ch;
			return true;
		}
		if (int(arr[i]) >= 97) { // 当前节点是小写字母  
			// 尝试左子节点  
			if (insertch(ch, leftchild(i))) {
				return true;
			}
			// 左子节点失败，尝试右子节点  
			return insertch(ch, rightchild(i));
		}
		if (int(arr[i]) >= 65 && int(arr[i]) <= 90) { // 当前节点是大写字母，不允许在其下插入  
			return false;
		}
	}


	void insert(char ch) {
		insertch(ch, 0);
	}

	void print() {
		for (int i = 0; i < 100; i++) {
			if (arr[i] == '0') {
				continue;
			}
			cout << arr[i];
		}
		cout << endl;
	}

};


int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; j++) {
		tree t;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			t.insert(str[i]);
		}
		t.print();
	}
	return 0;
}