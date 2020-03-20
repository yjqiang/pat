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

#define N_MAX 1001
#define HOBBY_NAX 1001

// ���ڲ���ĳhobby�Ķ�Ӧĳ���û�������һ�����ɣ�����Ϊindexʹ��
int who_like[HOBBY_NAX] = { 0 };

// ���鼯
int parents[N_MAX] = { 0 };

// counts[root] = ��rootΪ����set��Ԫ�ظ���
int counts[N_MAX] = { 0 };

int myFindRoot(int a) {
	int root = a;
	while (parents[root] != 0)
		root = parents[root];

	int tmp;
	while (a != root) {
		tmp = parents[a];
		parents[a] = root;
		a = tmp;
	}
	return root;
}

void myUnion(int a, int b) {
	int root_a = myFindRoot(a);
	int root_b = myFindRoot(b);
	if (root_a != root_b)
		parents[root_a] = root_b;
}

int main() {
	int N;
	scanf("%d", &N);

	int i, h;
	int K, hobby;
	for (i = 1; i <= N; ++i){
		scanf("%d:", &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", &hobby);

			if (who_like[hobby] == 0)
				who_like[hobby] = i;

			//����ͬ�����õ������˺ϲ�Ϊһ������
			myUnion(who_like[hobby], i);
		}
	}

	for (i = 1; i <= N; ++i)
		++counts[myFindRoot(i)];

	vector<int> results;
	for (i = 1; i <= N; ++i)
		if (counts[i] != 0)
			results.push_back(counts[i]);
	sort(results.begin(), results.end());
	printf("%d\n", results.size());
	printf("%d", results.back());
	for (i = results.size() - 2; i >= 0; --i)
		printf(" %d", results[i]);
	
	system("pause");
	return 0;
}