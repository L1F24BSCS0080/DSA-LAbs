#include "array.h"
#include<string>
class Word {
	string defination;
	string word;
	string pofspeach;
public:

	Word(string defination = "",string word = "",string pofspeach = "") {
		this->defination = defination;
		this->word = word;
		this->pofspeach = pofspeach;
	}
	void display() {
		cout << "defination: " << defination << endl;
		cout << "word: " << word << endl;
		cout << "pofspeach: " << pofspeach << endl;
	}
	string getname() {
		return word;
	}
	bool operator==(Word& p) {
		return this->word == p.getname();
	}
	friend ostream& operator<<(ostream& out, Word& p);
};
ostream& operator<<(ostream& out, Word& p) {
	out << "defination: " << p.defination << endl;
	out << "word: " << p.word << endl;
	out << "pofspeach: " << p.pofspeach << endl;
	return out;
}
int main() {
	Array<Word> arr(5);
	string word, def, pos;
	for (int i = 0; i < 2; i++) {
		cout << "enter word name: ";
		getline(cin, word);
		cout << "enter defination: " ;
		getline(cin, def);
		cout << "\nenter part of speech\n";
		getline(cin, pos);
		Word w(word, def, pos);
		arr.insertval(w);
	}
	arr.display();
}