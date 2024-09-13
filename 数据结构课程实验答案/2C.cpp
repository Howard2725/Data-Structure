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