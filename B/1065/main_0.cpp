#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

map<int, int>couples;
set<int> all_people;

int main() {
	int N;
	scanf("%d", &N);

	int i;
	int couple_ID0, couple_ID1;
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &couple_ID0, &couple_ID1);
		couples[couple_ID0] = couple_ID1;
		couples[couple_ID1] = couple_ID0;
	}
		
	// 拿set做一个快速查找的index
	int M;
	scanf("%d", &M);
	int ID;
	for (i = 0; i < M; ++i) {
		scanf("%d", &ID);
		all_people.insert(ID);
	}

	vector<int> result;

	// 重新迭代一次
	set<int>::iterator set_i;
	for (set_i = all_people.begin(); set_i != all_people.end(); ++set_i) {
		ID = *set_i;
		// 有配偶且配偶也参与了
		if (couples.find(ID) != couples.end() && all_people.find(couples[ID]) != all_people.end())
			continue;
		result.push_back(ID);
	}

	sort(result.begin(), result.end());

	int n_result = result.size();
	printf("%d\n", n_result);
	if (n_result) {
		printf("%05d", result[0]);
		for (i = 1; i < n_result; ++i)
			printf(" %05d", result[i]);
	}

	system("pause");
	return 0;
}