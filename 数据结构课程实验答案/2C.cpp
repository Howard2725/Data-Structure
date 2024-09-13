/*Description
Please implement a simple program to manage a digital library. You  need to realize the operations on the library  including:  

(1)  Add a book: Each book is recorded as a triple (name, author,  price). The name and author of a book is presented as a string and the price is  presented as a float number.

(2)    Remove a book given its  name and author.

(3)    Find a book given its  name. If multiple books have a same name, all the matched books should be  found.

Input
The input consists of T operations. The number T is given in the  first line of the input. Each one of the following T lines contains a string  representing an operation. Each operation is belonging to one of the following  3  formats:

(1) ADD (name) (author)  (price)

(2) REMOVE (name)  (author)

(3) FIND  (name)

Output
The output consists of T lines. The No i  lines presents the result of the No. i operation. The result is belonging to one  of the following 3 cases:

(1) The case when the operation input is ¡®ADD (name) (author) (price)¡¯. If  there is another book in the library with the same name and author as the input,  print ¡®FAIL¡¯. Otherwise, add the book into the library and print  ¡®SUCCESS¡¯

(2) The case when the operation input is ¡®REMOVE (name) (author)¡¯. If  there is no book in the library with the same name and author as the input,  print ¡®FAIL¡¯. Otherwise, remove the book from the library and print  ¡®SUCCESS¡¯.

(3) The case when the operation input is ¡®FIND (name)¡¯. Print the  count of the books in the library with the name as the input.

Sample Input
6
ADD (Data Structure) (Clifford A. Shaffer) (30.50)
ADD (Data Structure) (Clifford A. Shaffer) (100.50)
ADD (Data Structure) (Will A. Shaffer) (10.50)
REMOVE (Data Structure) (Jimmy Lud)
FIND (Data Structure) 
REMOVE (Data Structure) (Will A. Shaffer)


Sample Output
SUCCESS
FAIL
SUCCESS
FAIL
2
SUCCESS
*/

#include<iostream>
#include<string>
using namespace std;

class book {

public:
	string name;
	string author;
	string price;

	book(string n, string a, string p) {
		this->name = n;
		this->author = a;
		this->price = p;
	}
	book() {
	}
	bool operator== (book& b) {
		return ((this->name == b.name) && (this->author == b.author));
	}
};



class Library :public book {
public:
	int book_size = 0;
	book* book_list = new book[100];

	void insert(string name, string author, string price) {
		book temp_book(name, author, price);
		for (int i = 0; i < book_size; i++) {
			if (book_list[i] == temp_book) {
				cout << "FAIL" << endl;
				return;
			}
		}
		book_list[book_size++] = temp_book;
		cout << "SUCCESS" << endl;

	}
	void remove(string name, string author, string price = "null") {
		book temp_book(name, author, price);
		for (int i = 0; i < book_size; i++) {
			if (book_list[i].name == temp_book.name && book_list[i].author == temp_book.author) {
				for (int j = i; j < book_size - 1; j++) {
					book_list[j] = book_list[j + 1];
				}
				book_size--;
				cout << "SUCCESS" << endl;
				return;
			}
		}
		cout << "FAIL" << endl;
	}
	void find(string name, string author = "null", string price = "null") {
		book temp_book(name, author, price);
		int flag = 0;
		for (int i = 0; i < book_size; i++) {
			if (book_list[i].name == temp_book.name) {
				flag++;
			}
		}
		cout << flag << endl;
	}
};

int main() {
	int n;
	cin >> n;
	cin.ignore();
	Library lib;
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		string temp[4];
		string tr = "";
		int t = 0;
		for (int n = 0; n < str.length(); n++)
		{
			if (str[n] == '(')
			{
				if (tr[tr.length() - 1] == ' ')
				{
					tr.erase(tr.length() - 1);
				}
				if (t != 0)
				{
					temp[t] = "(";
				}
				temp[t] += tr;
				tr = "";
				t++;
				temp[t] = "(";
				continue;
			}
			tr += str[n];
		}
		if (tr[tr.length() - 1] == ' ')
		{
			tr.erase(tr.length() - 1);
		}
		if (t != 0)
		{
			temp[t] = "(";
		}
		temp[t] += tr;
		if (temp[0] == "ADD") {
			lib.insert(temp[1], temp[2], temp[3]);
		}
		else if (temp[0] == "REMOVE") {
			lib.remove(temp[1], temp[2]);
		}
		else if (temp[0] == "FIND") {
			lib.find(temp[1]);
		}

	}

}