#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

#define K_MAX 2501
// 26^4
// string students[500000];
vector<string> courses[K_MAX];

int main() {
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;

	string name;
	int C, course_id;
	int i, h;
	for (i = 0; i < N; ++i) {
		cin >> name >> C;
		for (h = 0; h < C; ++h) {
			cin >> course_id;
			courses[course_id].push_back(name);
		}
	}
	int n;
	for (i = 1; i <= K; ++i) {
		sort(courses[i].begin(), courses[i].end());
		n = courses[i].size();
		printf("%d %d\n", i, n);
		for (h = 0; h < n; ++h)
			printf("%s\n", courses[i][h].c_str());
	}
	

	system("pause");
	return 0;
}