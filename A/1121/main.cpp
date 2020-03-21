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
#include <unordered_set>

using namespace std;

#define ID_MAX 1000000
// couples[a] = b �� couples[b] = a����һ�����
map<int, int> couples;

// ��ʾ�����ҵ���/��ż���ڣ������ܼ���
set<int> joiners;

int main() {

	int N, M;
	scanf("%d", &N);

	int i;
	int ID0, ID1;
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &ID0, &ID1);
		couples[ID0] = ID1;
		couples[ID1] = ID0;
	}

	scanf("%d", &M);

	int ID;
	for (i = 0; i < M; ++i) {
		scanf("%d", &ID);
		// �����¶����ˣ����һ�����ֵ��˻����set���ڶ��˵�ʱ�򣬻ᱻ���������ʱ�ѵ�һ��ɾ���Ҳ�����ڶ���
		if (couples.find(ID) != couples.end() && joiners.find(couples[ID]) != joiners.end())
			joiners.erase(couples[ID]);
		else
			joiners.insert(ID);
	}

	printf("%d\n", joiners.size());
	if (joiners.size()) {

		set<int>::iterator set_i = joiners.begin();
		printf("%05d", *set_i);
		for (++set_i; set_i != joiners.end(); ++set_i)
			printf(" %05d", *set_i);
	}

	system("pause");
	return 0;
}