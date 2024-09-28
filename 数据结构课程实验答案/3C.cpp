#include<iostream>  
#include<string>
using namespace std;


class tree {
public:
	int n = 0;
	int arr[15];

	tree() { // 构造函数  

		// 初始化arr数组中的所有元素为 -1  
		for (int i = 0; i < 15; ++i) {
			arr[i] = -1;
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

	void insert(int num) {
		arr[n++] = num;
	}

	bool isleaf(int pos) {
		return (pos >= n / 2) && (pos < n);
	}

	void print(int i = 0) {
		if (i >= n ) {  
			return;
		}

		// 左子树  
		print(leftchild(i));

		// 右子树  
		print(rightchild(i));

		// 当前节点  
		if (arr[i] != -1) {
			cout << arr[i] << " ";
		}
	}

	int findsmall(int k) {
		int* arr1 = new int[n];
		for (int i = 0; i < n; i++) {
			arr1[i] = arr[i];
		}
		for (int i = 0; i < n - 1; i++) {

			for (int j = 0; j < n - i - 1; j++) {
				if (arr1[j] > arr1[j + 1]) {
					// 交换 arr[j] 和 arr[j+1]  
					int temp = arr1[j];
					arr1[j] = arr1[j + 1];
					arr1[j + 1] = temp;
				}
			}
		}
		int flag = 0;
		int i = 0;
		for (; i < n; i++) {
			if (arr1[i] == -1) {
				continue;
			}
			if (flag == k - 1) {
				break;
			}
			flag++;
		}
		return arr1[i];
	}
	
		

};


int main() {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		tree t;
		string str;
		getline(cin, str);

		str += ' ';
		int temp = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == 'n') {
				t.insert(-1);
				j++;
				continue;
			}
			if (str[j] != ' ')
			{
				temp *= 10;
				temp += str[j] - '0';
				continue;
			}

			t.insert(temp);
			temp = 0;
		}

		t.print();
		cout << endl;
		int k = 0;
		cin >> k;
		cin.ignore();
		cout << t.findsmall(k) << endl;
		
	}
	return 0;
}