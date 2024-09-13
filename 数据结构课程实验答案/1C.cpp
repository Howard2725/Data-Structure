/*【问题描述】一个链表节点的定义如下： struct ListNode { int val; ListNode* next; }; 现在要求输入两个有序链表（长度N满足0<=N<=100)，
将两个链表合并为一个有序链表，输出合并后链表每个节点的值。要求:使用结构体完成。

【输入形式】输入包含多个样例，第一行输入两个链表的长度N1与N2；第二行与第三行分别输入第一个与第二个链表中每个节点的值，
按递增顺序输入。如果某个链表长度为0，则相应行不需要输入数据。

【输出形式】输出为一行，以空格隔开，并按递增的顺序输出；如果输出的链表为空链表，则输出“NULL”。

KeyWord(s) that Must be Used
struct

KeyWord(s) that Mustn't be Used
[ ]

【样例输入】
0 1
1
1 2
1
2 3
3 3
1 3 5
2 4 6

【样例输出】
1
1 2 3
1 2 3 4 5 6

*/

#include<iostream>  
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}

};

struct List {
    ListNode* head = nullptr;

    void insert(int x) {

        ListNode* n = new ListNode(x);

        if (head == nullptr || head->val >= x) {
            n->next = head;
            head = n;
        }
        else {
            ListNode* current = head;
            while (current->next != nullptr && current->next->val < x) {
                current = current->next;
            }
            n->next = current->next;
            current->next = n;
        }
    }

     
    void printList() {
        ListNode* current = head;   
        while (current != nullptr) { 
            cout << current->val << " ";
            current = current->next;  
        }
        cout << endl;
    }
    static ListNode* PlusLists(ListNode* l1, ListNode* l2) {
          
        ListNode sentinel(0);
        ListNode* current = &sentinel;
  
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

         
        if (l1 != nullptr) {
            current->next = l1;
        }
        if (l2 != nullptr) {
            current->next = l2;
        }

         
        return sentinel.next;
    }

    void PlusWith(List* other) {
        head = PlusLists(head, other->head);
    }
};

 
int main() {
    int a, b;
    while (cin >> a) {
        cin >> b;
        List* l1 = new List;
        for (int i = 0; i < a; i++) {
            int temp;
            cin >> temp;
            l1->insert(temp);
        }


        List* l2 = new List;
        for (int i = 0; i < b; i++) {
            int temp;
            cin >> temp;
            l2->insert(temp);
        }
        l1->PlusWith(l2);
        l1->printList();
    }
}