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
#include <unordered_map>

using namespace std;

#define ID_MAX 10000

struct Node {
	int C;
	int D;
	bool operator< (const Node& b) const {
		if (C != b.C)
			return C < b.C;
		return D < b.D;
	}
};

// A 喜欢 B
int A, B;

// 邻接表
vector<int> edges[ID_MAX];
bool is_negative[ID_MAX];
// 防止挑人挑到了重复的
bool visited[ID_MAX] = { false };

vector<Node>results;
vector<int>tmp;


// begin 不带符号
void subset(int begin) {
	if (tmp.size() == 4) {
		// 同号这里办法很牛逼
		if (tmp[3] == B && is_negative[tmp[1]] == is_negative[A] && is_negative[tmp[2]] == is_negative[B])
			results.push_back(Node{ tmp[1], tmp[2] });
		return;
	}

	int i;
	int n_size = edges[begin].size();
	int cur;
	for (i = 0; i < n_size; ++i) {
		cur = edges[begin][i];
		if (!visited[cur]) {
			tmp.push_back(cur);
			visited[cur] = true;

			subset(cur);

			tmp.pop_back();
			visited[cur] = false;
		}
	}

}

void check() {
	results.clear();

	tmp.push_back(A);
	visited[A] = true;

	subset(A);

	// 这样执行完后，所有的辅助东西均reset了
	tmp.pop_back();
	visited[A] = false;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	int ID0, ID1;
	// 有-0000这种sb玩意儿
	char str_ID0[6], str_ID1[6];
	for (i = 0; i < M; ++i) {
		scanf("%s%s", str_ID0, str_ID1);
		ID0 = abs(atoi(str_ID0));
		ID1 = abs(atoi(str_ID1));

		edges[ID0].push_back(ID1);
		edges[ID1].push_back(ID0);

		is_negative[ID0] = (str_ID0[0] == '-');
		is_negative[ID1] = (str_ID1[0] == '-');

	}

	int K;
	int n_size;
	int h;
	scanf("%d", &K);
	for (i = 0; i < K; ++i) {
		scanf("%d%d", &A, &B);
		A = abs(A);
		B = abs(B);

		check();
		n_size = results.size();
		printf("%d\n", n_size);

		sort(results.begin(), results.end());

		
		for (h = 0; h < n_size; ++h)
			printf("%04d %04d\n", results[h].C, results[h].D);
	}

	system("pause");
	return 0;
}