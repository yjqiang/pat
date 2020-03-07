#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;


// sets[0]表示手，1表示眼，2表示嘴
vector<string> sets[3];

int main() {
	string s;
	string s0;
	int n;

	int i, h, start;
	for (i = 0; i < 3; ++i) {
		getline(cin, s);
		n = s.size();
		for (h = 0; h < n; ++h)
			if (s[h] == '[') {
				++h;
				start = h;
				for (; s[h] != ']'; ++h);
				sets[i].push_back(s.substr(start, h - start));
			}
		
	}

	int K;
	cin >> K;
	int reqs[5];
	for (i = 0; i < K; ++i) {
		for (h = 0; h < 5; ++h)
			cin >> reqs[h];

		if (reqs[0] <= sets[0].size() && reqs[0] >= 1&&
			reqs[1] <= sets[1].size() && reqs[1] >= 1 &&
			reqs[2] <= sets[2].size() && reqs[2] >= 1 &&
			reqs[3] <= sets[1].size() && reqs[3] >= 1 &&
			reqs[4] <= sets[0].size() && reqs[4] >= 1) {

			cout << sets[0][reqs[0] - 1] << "(" << sets[1][reqs[1] - 1] << sets[2][reqs[2] - 1] << sets[1][reqs[3] - 1] << ")" << sets[0][reqs[4] - 1] << endl;
		}
		else
			cout << "Are you kidding me? @\\/@" << endl;
	}

	system("pause");
	return 0;
}