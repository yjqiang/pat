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


vector<int> indexes[26 * 26 * 26 * 26];


int strHash(char* s) {
	int i = 0;
	int result = 0;
	for (i = 0; i < 3; ++i)
		result = result * 26 + s[i] - 'A';
	result = result * 26 + s[i] - '0';
	return result;
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	int course_id, Ni;
	char name[5];
	int i, h;
	int hash_name;
	for (i = 0; i < K; ++i) {
		scanf("%d%d", &course_id, &Ni);
		for (h = 0; h < Ni; ++h) {
			scanf("%s", name);
			hash_name = strHash(name);
			indexes[hash_name].push_back(course_id);
		}
	}

	for (i = 0; i < N; ++i) {
		scanf("%s", name);
		printf("%s", name);
		hash_name = strHash(name);
		printf(" %d", indexes[hash_name].size());
		sort(indexes[hash_name].begin(), indexes[hash_name].end());
		for (h = 0; h < indexes[hash_name].size(); ++h)
			printf(" %d", indexes[hash_name][h]);
		printf("\n");
	}
	system("pause");
	return 0;
}