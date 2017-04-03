#include <iostream>
#include <string>
#include "SplayTree.h"
#include <vector>

using namespace std;

int main()
{
	SplayTree tree = SplayTree();
	Player *pl = new Player();
	cout << "num of teams:";
	int teamsNum,teamNumber;
	cin >> teamsNum;
	vector<Team *>teams(teamsNum);
	for (int i = 0; i < teams.size(); i++)
		teams[i] = new Team();

	int num = 1;
	std::string name = "ABCtrain";

	while (true)
	{
		cout << "Exit?";
		cin >> num;
		if (num < 0)	break;
		/*cout << "enter nam: ";
		cin >> name;
		pl = new Player();
		pl->alphabet = name;
		
		cout << "team: ";
		cin >> teamNumber;
		teamNumber--;
		if (abs(teamNumber) > teams.size())
			teamNumber = 0;
		teams[teamNumber]->players.push_back(pl);*/

		cout << "salary: ";
		cin >> num;
		tree.insert(pl,num);
	}
	tree.show(nullptr,1,0);
	cout << "\n\n\n";
	for (int i = 0; i < teams.size(); i++)
	{
		cout << "team#" << i << ": ";
		teams[i]->display();
		cout << endl;
	}
	system("pause");
	return 0;
}