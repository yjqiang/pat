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

// 邻接表
vector<int> edges[ID_MAX];

// 每条边有两个顶点ab，均4位数字。用 (a*10000+b) 和 (a+b*10000)表示一条边
// lines[(a*10000+b)] = line  lines[(a+b*10000)] = line
unordered_map<int, int>lines;

vector<int> result;
vector<int> tmp;
bool visited[ID_MAX] = { false };

int min_dist, min_line;

int source, destination;

int getLines(vector<int>& path) {
	int n_line = 0;
	int	pre_line = -1;
	int n_size = path.size();
	int i, cur_line;
	

	for (i = 1; i < n_size; ++i) {
		// 每条边有两个顶点ab，均4位数字。用 (a*10000+b) 和 (a+b*10000)表示一条边
		cur_line = lines[(path[i - 1] * 10000 + path[i])];
		if (cur_line != pre_line)
			++n_line;
		pre_line = cur_line;
	}
	return n_line;
}

// last 就是最后节点
void func(int last) {
	int n_size;
	if (last == destination) {
		n_size = tmp.size();
		int n_line = getLines(tmp);

		if (n_size < min_dist || n_size == min_dist && n_line < min_line) {
			min_dist = n_size;
			min_line = n_line;
			result = tmp;
		}
		return;
	}
	int i, cur;
	n_size = edges[last].size();
	for (i = 0; i < n_size; ++i) {
		cur = edges[last][i];
		if (!visited[cur]) {
			visited[cur] = true;
			tmp.push_back(cur);

			func(cur);

			visited[cur] = false;
			tmp.pop_back();
		}
	}
}

void check() {
	min_dist = INT_MAX; 
	min_line = INT_MAX;

	visited[source] = true;
	tmp.push_back(source);
	func(source);
	// 注意这里就让visited数组重置为false了
	// tmp 同理
	visited[source] = false;
	tmp.pop_back();

}

int main() {
	int N;
	scanf("%d", &N);

	int i, h;
	int M;
	int S0, S1;
	for (i = 1; i <= N; ++i) {
		scanf("%d %d", &M, &S0);
		
		for (h = 1; h < M; ++h) {
			scanf("%d", &S1);
			edges[S0].push_back(S1);
			edges[S1].push_back(S0);

			lines[S1 * 10000 + S0] = i;
			lines[S1 + S0 * 10000] = i;

			S0 = S1;
		}
	}

	int K;
	scanf("%d", &K);

	int cur_line, n_size, start;
	
	for (h = 0; h < K; ++h) {
		scanf("%d%d", &source, &destination);
		check();

		// 打印 result
		printf("%d\n", min_dist - 1);

		n_size = result.size();

		for (i = 1; i < n_size; ) {
			// 直接循环到本line完成
			start = result[i - 1];
			cur_line = lines[result[i - 1] * 10000 + result[i]];
			for (++i; i < n_size; ++i)
				if (cur_line != lines[result[i - 1] * 10000 + result[i]])	
					break;

			printf("Take Line#%d from %04d to %04d.\n", cur_line, start, result[i - 1]);
		}
	}

	system("pause");
	return 0;
}