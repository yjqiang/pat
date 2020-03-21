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

#define BIRD_MAX 10001


// 并查集(鸟的有效编号都是从1开始的，为0表示根了)
int parents[BIRD_MAX] = { 0 };

set<int> Bird_IDs;
set<int> roots;

int myFindRoot(int x) {
	int r = x;
	while (parents[r] != 0)
		r = parents[r];

	int tmp;
	while (x != r) {
		tmp = parents[x];
		parents[x] = r;
		x = tmp;
	}
	return r;
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
	int K, Bird_ID;
	// 每张图的第一个鸟
	int first;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &K);
		first = -1;
		for (h = 0; h < K; ++h) {
			scanf("%d", &Bird_ID);

			Bird_IDs.insert(Bird_ID);

			if (h == 0)
				first = Bird_ID;
			else
				// 每张图片的所有鸟都放在同一个set里面
				myUnion(first, Bird_ID);
		}
	}

	set<int>::iterator set_i;
	for (set_i = Bird_IDs.begin(); set_i != Bird_IDs.end(); ++set_i)
		roots.insert(myFindRoot(*set_i));

	printf("%d %d\n", roots.size(), Bird_IDs.size());

	int Q;
	int Bird_ID0, Bird_ID1;
	scanf("%d", &Q);
	for (i = 0; i < Q; ++i) {
		scanf("%d %d", &Bird_ID0, &Bird_ID1);
		if (myFindRoot(Bird_ID0) == myFindRoot(Bird_ID1))
			printf("Yes\n");
		else
			printf("No\n");
	}
		
	system("pause");
	return 0;
}