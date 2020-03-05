#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define N_MAX 40000
#define K_MAX 2501

map<string, set<int>>indexes;

int main() {
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;

	int course_id, Ni;
	string name;
	int i, h;
	for (i = 0; i < K; ++i) {
		cin >> course_id >> Ni;
		for (h = 0; h < Ni; ++h) {
			cin >> name;
			indexes[name].insert(course_id);
		}
	}

	set<int>::iterator i_set;
	for (i = 0; i < N; ++i) {
		cin >> name;
		printf("%s", name.c_str());
		if (indexes.find(name) != indexes.end()) {
			printf(" %d", indexes[name].size());
			for (i_set = indexes[name].begin(); i_set != indexes[name].end(); ++i_set) {
				printf(" %d", *i_set);
			}
			printf("\n");
		}
		else
			printf(" 0\n");
	}
	system("pause");
	return 0;
}