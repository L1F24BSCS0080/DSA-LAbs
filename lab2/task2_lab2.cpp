#include <iostream>
using namespace std;
template <class T>
class leaderboard {
	string name[100];
	T score[100];
	int cur = 0;
	int sz = 100;
public:
	leaderboard() {}
	bool isempty() {
		return cur == 0 ;
	}
	bool isfull() {
		return cur == sz;
	}
	void addplayer(string name, T score) {
		if (isfull()) {
			cout << "leaderboard is full ";
			return;
		}
		this->name[cur] = name;
		this->score[cur++] = score;
	}
	void display() {
		if (isempty()) {
			cout<<"leaderboard is empty ";
			return ;
		}
		for (int i = 0; i < cur; i++) {
			cout << "player " << i + 1 << endl;
			cout << name[i] << ", " << score[i] << endl;
		}
	}
	string getwinner() {
		if (isempty()) {
			return "leaderboard is empty ";
		}
		int max=0;
		int mscore = 0;
		for (int i = 0; i < cur; i++) {
			if (mscore < score[i]) {
				max = i;
				mscore = score[i];
			}
		}
		return name[max];
	}
};
int main() {
	leaderboard <int> board1;
	board1.addplayer("asad",90);
	board1.addplayer("hussain", 99);
	board1.addplayer("ali", 94);
	board1.display();
	cout << board1.getwinner();
	cout << "..........\n";
	leaderboard <float> board2;
	board2.addplayer("asad", 90.5);
	board2.addplayer("hussain", 99.3);
	board2.addplayer("ali", 94.6);
	board2.display();
	cout << board1.getwinner();
}