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

// �ڽӱ�
vector<int> edges[N_MAX];



// N���㣬N-1���ߣ�������������з���ͨ��
// dfs
int depths[N_MAX];
bool visited[N_MAX];
void dfs(int r, int depth) {
	// ֻ��Ϊ��ʱ��depth�ĸ�ֵ�ű�ʹ�õ�
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
	// N-1����¼��
	for (i = 1; i < N; ++i) {
		scanf("%d %d", &node0, &node1);
		edges[node0].push_back(node1);
		edges[node1].push_back(node0);
	}

	


	// ��һ�֣������һ����X���ҳ�����X��Զ��������е�
	// dfs ����connected components
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
	// �������������depth
	for (i = 1; i <= N; ++i)
		if (depths[i] > max_depth)
			max_depth = depths[i];
	// ����depth���result
	for (i = 1; i <= N; ++i)
		if (depths[i] == max_depth)
			result.insert(i);




	// �ڶ��֣�������һ�ֵ�Զ����㣬����dfs
	for (i = 1; i <= N; ++i)
		visited[i] = false;
	// dfs
	dfs(*result.begin(), 0);

	max_depth = -1;
	// �������������depth
	for (i = 1; i <= N; ++i)
		if (depths[i] > max_depth)
			max_depth = depths[i];
	// ����depth���result
	for (i = 1; i <= N; ++i)
		if (depths[i] == max_depth)
			result.insert(i);

	set<int>::iterator set_i;
	for (set_i = result.begin(); set_i != result.end(); ++set_i)
		printf("%d\n", *set_i);


	system("pause");
	return 0;
}