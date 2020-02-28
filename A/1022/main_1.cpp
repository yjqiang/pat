#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <string>

using namespace std;

map<string, set<int>> titles, authors, keys, publishers, years;
void myFind(map<string, set<int>> &indexes, int num, string& s) {
	cout << num << ": " << s << endl;
	set<int>::iterator i;
	if (indexes.find(s) != indexes.end()) {
		for (i = indexes[s].begin(); i != indexes[s].end(); ++i)
			printf("%07d\n", *i);

	}
	else
		printf("Not Found\n");
		

}

int main() {
	int N, M;

	cin >> N;
	int i;
	int ID;
	string s;
	for (i = 0; i < N; ++i) {
		cin >> ID;
		cin.get();

		getline(cin, s);
		titles[s].insert(ID);

		getline(cin, s);
		authors[s].insert(ID);

		while (true) {
			cin >> s;
			keys[s].insert(ID);
			if (cin.get() == '\n')
				break;
		}

		getline(cin, s);
		publishers[s].insert(ID);

		getline(cin, s);
		years[s].insert(ID);
	}

	cin >> M;
	int num;
	for (i = 0; i < M; ++i) {
		cin >> num;
		cin.get();
		cin.get();
		getline(cin, s);

		if (num == 1)
			myFind(titles, num, s);
		else if (num == 2)
			myFind(authors, num, s);
		else if (num == 3)
			myFind(keys, num, s);
		else if (num == 4)
			myFind(publishers, num, s);
		else if (num == 5)
			myFind(years, num, s);

	}


	system("pause");
	return 0;
}