# include "leaderboard.h"
int main() {

	cout << "........................" << endl;
	cout << "seperate file interface " << endl;
	cout << "........................" << endl;
	leaderboard <int> board1;
	board1.addplayer("asad", 90);
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