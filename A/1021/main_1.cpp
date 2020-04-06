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
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define N_MAX 10001
int N;

// 邻接表
vector<int> edges[N_MAX];



// N个点，N-1条边，若非树，则必有非连通点
// dfs
int depths[N_MAX];
bool visited[N_MAX];
void dfs(int r, int depth) {
	// 只有为树时，depth的赋值才被使用的
	depths[r] = depth;
	visited[r] = true;

	int cur;

	int i;
	int n_size = edges[r].size();
	for (i = 0; i < n_size; ++i) {
		cur = edges[r][i];
		if (!visited[cur])
			dfs(cur, depth + 1);
	}
		
}

int main() {
	scanf("%d", &N);

	int i;
	int node0, node1;
	// N-1条边录入
	for (i = 1; i < N; ++i) {
		scanf("%d %d", &node0, &node1);
		edges[node0].push_back(node1);
		edges[node1].push_back(node0);
	}

	


	// 第一轮，随便找一个点X，找出距离X最远距离的所有点
	// dfs 查找connected components
	for (i = 1; i <= N; ++i)
		visited[i] = false;
	int count = 0;
	for (i = 1; i <= N; ++i)
		if (!visited[i]) {
			++count;
			dfs(i, 0);
		}

	if (count != 1) {
		printf("Error: %d components\n", count);
		system("pause");
		return 0;
	}
	
	set<int>result;
	int max_depth = -1;
	// 先搜索出最深的depth
	for (i = 1; i <= N; ++i)
		if (depths[i] > max_depth)
			max_depth = depths[i];
	// 根据depth输出result
	for (i = 1; i <= N; ++i)
		if (depths[i] == max_depth)
			result.insert(i);




	// 第二轮，根据上一轮的远距离点，二次dfs
	for (i = 1; i <= N; ++i)
		visited[i] = false;
	// dfs
	dfs(*result.begin(), 0);

	max_depth = -1;
	// 先搜索出最深的depth
	for (i = 1; i <= N; ++i)
		if (depths[i] > max_depth)
			max_depth = depths[i];
	// 根据depth输出result
	for (i = 1; i <= N; ++i)
		if (depths[i] == max_depth)
			result.insert(i);

	set<int>::iterator set_i;
	for (set_i = result.begin(); set_i != result.end(); ++set_i)
		printf("%d\n", *set_i);


	system("pause");
	return 0;
}