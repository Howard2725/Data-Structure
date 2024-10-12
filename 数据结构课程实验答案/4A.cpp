/*Description
Given a collection of characters with their frequencies, please try to build the Huffman code for them,  and use the code to encode the input string. Finally,  you are required to output the length of encoded string.



Input
The first line indicates the number  of the test cases, N . In each of the following N test cases, the first line indicates the number of the characters  needed to code, Ti.   Each of the following Ti lines shows a character and its freqency. The final line of each test case is the input string needed to encode.

Output
The output consits of N lines. The No. i line is the length of the encoded string of No. i test case.

Sample Input
2
3
A 1
B 2
C 5
ABC
6
A 1
B 2
C 4
D 5
E 6
F 10
AABBCEF

Sample Output
5
23*/


#include <iostream>  
#include <vector>  
#include <string>  
#include <unordered_map> 
#include <algorithm>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left, * right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};


// �Զ���Ƚ���������sort  
bool compareNodes(Node* a, Node* b) {
    return a->freq < b->freq; // ע��������С�ڣ���Ϊ����Ҫģ����С��  
}


// ģ�����ȶ��У���С�ѣ��� push �� pop ����  
void pushHeap(vector<Node*>& heap, Node* node) {
    heap.push_back(node);
    sort(heap.begin(), heap.end(), compareNodes); // ����������������  
}


Node* popHeap(vector<Node*>& heap) {
    if (heap.empty()) {
        return nullptr;
    }

    Node* minNode = heap.front();
    heap.erase(heap.begin());
    return minNode;
}


// ����Huffman���ļ򻯰棬ʹ��vectorģ�����ȶ���  
Node* buildHuffmanTree(vector<pair<char, int>>& freqList) {
    vector<Node*> heap;

    // �������ַ��ڵ����ģ�����С��  
    for (auto& pair : freqList) {
        pushHeap(heap, new Node(pair.first, pair.second));
    }

    // �ϲ��ڵ�ֱ��ֻʣһ�����ڵ�  
    while (heap.size() > 1) {
        Node* left = popHeap(heap);
        Node* right = popHeap(heap);
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pushHeap(heap, newNode);
    }

    return heap.empty() ? nullptr : heap.front();
}


// �ݹ�����Huffman���룬ʹ��vector<bool>ģ�������̣�����Ϊ�˼򻯣����洢����ϣ���У�  
void generateHuffmanCodes(Node* root, string code, vector<string>& codes, unordered_map<char, string>& codeMap) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes.push_back(code);
        codeMap[root->ch] = code; // �����ַ��������ӳ��  
    }
    else {
        generateHuffmanCodes(root->left, code + "0", codes, codeMap);
        generateHuffmanCodes(root->right, code + "1", codes, codeMap);
    }
}


// �ͷ�Huffman��ռ�õ��ڴ�  
void freeHuffmanTree(Node* root) {
    if (!root) return;
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    delete root;
}


int main() {
    int N;
    cin >> N;
    while (N--) {
        int Ti;
        cin >> Ti;

        vector<pair<char, int>> freqList;
        for (int i = 0; i < Ti; ++i) {
            char ch;
            int freq;
            cin >> ch >> freq;
            freqList.push_back(make_pair(ch, freq));
        }

        // ����Huffman��  
        Node* root = buildHuffmanTree(freqList);

        // ����Huffman������ַ��������ӳ��  
        vector<string> huffmanCodes;
        unordered_map<char, string> huffmanCodeMap;
        generateHuffmanCodes(root, "", huffmanCodes, huffmanCodeMap);

        // ����������һ�������ַ�����Ҫ����  
        string inputString;
        cin >> inputString;

        // �������ַ�������Huffman����  
        string encodedString;
        for (char ch : inputString) {
            if (huffmanCodeMap.find(ch) != huffmanCodeMap.end()) {
                encodedString += huffmanCodeMap[ch];
            }
            else {
                cerr << "Error: Character '" << ch << "' not found in Huffman code map." << endl;
            }
        }

        // ����������ַ���  
        cout << "Encoded string: " << encodedString << endl;

        // �ͷ��ڴ�  
        freeHuffmanTree(root);

        
    }
    return 0;
}