#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book {

private:
	char* author, * title;
	float* price;
public:
	book() {
		author = new char[20];
		title = new char[20];
		price = new float;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[], char[]);
	void buybook();

};

void book::feeddata() {
	cin.ignore();
	cout << "\nAuthor Name: "; cin.getline(author, 20);
	cout << "Title Name: "; cin.getline(title, 20);
	cout << "Price: "; cin >> *price;

}

void book::editdata() {

	cout << "\nAuthor Name: "; cin.getline(author, 20);
	cout << "Title Name: "; cin.getline(title, 20);
	cout << "Price: "; cin >> *price;

}

void book::showdata() {
	cout << "\nAuthor Name: " << author;
	cout << "\nTitle Name: " << title;
	cout << "\nPrice: " << *price;

}

int book::search(char tbuy[20], char abuy[20]) {
	if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)
		return 1;
	else return 0;

}

void book::buybook() {
	int count;
	cout << "\nNumber Of Books to buy: ";
	cin >> count;
	if (count <= *title) {
		*title = *title - count;
		cout << "\nBooks Bought Sucessfully";
		cout << "\nAmount: $" << (*price) * count;
	}
	else
		cout << "\nBook is not in Stock";
}

int main() {
	book* B[20];
	int i = 0, r, t, choice;
	char titlebuy[20], authorbuy[20];
	while (1) {
		cout << "\n\nBookstore Management System"
			<< "\n1. Add Book"
			<< "\n2. Buy Book"
			<< "\n3. Search Book"
			<< "\n4. Edit Book"
			<< "\n5. Exit"
			<< "\n\nEnter your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:	B[i] = new book;
			B[i]->feeddata();
			i++;
			break;

		case 2: cin.ignore();
			cout << "\nTitle: "; cin.getline(titlebuy, 20);
			cout << "Author: ";  cin.getline(authorbuy, 20);
			for (t = 0;t < i;t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					B[t]->buybook();
					break;
				}
			}
			if (t == 1)
				cout << "\nThis Book is Not in Stock";

			break;
		case 3: cin.ignore();
			cout << "\nTitle: "; cin.getline(titlebuy, 20);
			cout << "Author: ";  cin.getline(authorbuy, 20);

			for (t = 0;t < i;t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					cout << "\nBook Found Successfully";
					B[t]->showdata();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in Stock";
			break;

		case 4: cin.ignore();
			cout << "\nTitle: "; cin.getline(titlebuy, 20);
			cout << "Author: ";  cin.getline(authorbuy, 20);

			for (t = 0;t < i;t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					cout << "\nBook Found Successfully";
					B[t]->editdata();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in Stock";
			break;

		case 5: exit(0);
		default: cout << "\nInvalid Choice Entered";

		}
	}




	return 0;
}