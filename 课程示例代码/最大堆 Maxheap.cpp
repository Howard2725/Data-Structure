#include<iostream>  
using namespace std;


template<class Elem>
class Maxheap {
private:

	Elem* heap;
	int size;
	int n;

public:

	Maxheap(Elem* h, int size, int n) {
		this->heap = h;
		this->size = size;
		this->n = n;
		build_maxheap();
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

	//检测自身是否是叶子节点
	bool isleaf(int pos) {
		return (pos >= n / 2) && (pos < n);
	}

	//按照最大堆的定义对原来的 pos 位置上的元素进行排序
	void sitdown(int pos) {
		while (!isleaf(pos)) {
			int j = leftchild(pos);
			int rc = rightchild(pos);
			if (rc < n && heap[j] < heap[rc]) {
				j = rc;
			}
			if (heap[pos] >= heap[j]) {
				return;
			}
			Elem temp = heap[pos];
			heap[pos] = heap[j];
			heap[j] = temp;
			pos = j;
		}
	}

	//对原有的数组 h 进行排列
	void build_maxheap() {
		for (int i = n / 2; i >= 0; i--) {
			sitdown(i);
		}
		return;
	}

	//打印输出
	void printHeap() {
		for (int i = 0; i < n; i++) {
			cout << heap[i] << " ";
		}
		cout << endl;
	}

	//移除并返回堆顶元素
	Elem removetop() {

		if (n == 0) {
			return false;
		}

		Elem top = heap[0];
		heap[0] = heap[n - 1];  
		n--;  
		sitdown(0);  

		return top; 
	}

	//移除并返回堆顶元素
	bool insert(const Elem& new_item) {
		if (n >= size) {
			return false;
		}

		int cur = n++;
		heap[cur] = new_item;
		while (cur != 0 && heap[cur] > heap[parent(cur)]) {
			Elem temp = heap[cur];
			heap[cur] = heap[parent(cur)];
			heap[parent(cur)] = temp;
			cur = parent(cur);
		}
		return true;
	}


};


int main() {
	int h[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Maxheap<int> heap(h, 20, 10);
	heap.printHeap();
	heap.removetop();
	heap.printHeap();
	heap.insert(10);
	heap.printHeap();

}