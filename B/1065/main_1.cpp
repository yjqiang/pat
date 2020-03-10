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
		
	// ��set��һ�����ٲ��ҵ�index
	int M;
	scanf("%d", &M);
	int ID;
	for (i = 0; i < M; ++i) {
		scanf("%d", &ID);
		// ����ż  ���� ��ż����all_people����
		if (couples.find(ID) == couples.end() || all_people.find(couples[ID]) == all_people.end())
			all_people.insert(ID);
		else // ��ż��all_people����
			// �Ƴ���ż
			all_people.erase(couples[ID]);
	}

	int n_result = all_people.size();
	set<int>::iterator set_i;
	printf("%d\n", n_result);
	if (n_result) {
		set_i = all_people.begin();
		printf("%05d", *set_i);
		++set_i;
		for (; set_i != all_people.end(); ++set_i)
			printf(" %05d", *set_i);
	}

	system("pause");
	return 0;
}