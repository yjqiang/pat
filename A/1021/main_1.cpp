#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

vector<int> paths[10005];
bool visited[10005];
int max_depth = INT_MIN;
vector<int> result;
set<int> s;


void dfs(int root, int depth) {
	visited[root] = true;

	if (depth > max_depth) {
		result.clear();
		result.push_back(root);
		max_depth = depth;
	}
	else if (depth == max_depth)
		result.push_back(root);

	int i;
	for (i = paths[root].size() - 1; i >= 0; --i) {
		if (!visited[paths[root][i]])
			dfs(paths[root][i], depth + 1);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	int from, to;
	for (i = 1; i < N; ++i) {
		scanf("%d%d", &from, &to);
		paths[from].push_back(to);
		paths[to].push_back(from);
	}
	
	max_depth = INT_MIN;
	for (i = 1; i <= N; ++i)
		visited[i] = false;
	result.clear();
	
	int count = 0;
	for (i = 1; i <= N; ++i)
		if (!visited[i]){
			dfs(i, 0);
			++count;
		}

	if (count > 1)
		printf("Error: %d components", count);
	else {
		for (i = result.size() - 1; i >= 0; --i)
			s.insert(result[i]);

		max_depth = INT_MIN;
		for (i = 1; i <= N; ++i)
			visited[i] = false;
		result.clear();

		dfs(*(s.begin()), 0);
		for (i = result.size() - 1; i >= 0; --i)
			s.insert(result[i]);
		for (set<int>::iterator index_set = s.begin(); index_set != s.end(); ++index_set)
			printf("%d\n", *index_set);
	}
	system("pause");
	return 0;
}