#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

struct Node {
	int weight;
	// ID ��Ӧ��nodes�����index
	vector<int> children_IDs;
};

#define N_MAX 100
Node nodes[N_MAX];



// Ŀ��S
int S;

// �ݴ�root����ǰ�ڵ��·�����ϵ����о����ĵ�
vector<int> tmp;

// root(ID:00)->...->��ǰ�ڵ�ĸ��ڵ��·����Ϊsum
void pre(int parent_ID, int sum) {
	sum += nodes[parent_ID].weight;
	tmp.push_back(nodes[parent_ID].weight);

	int i;
	int n = nodes[parent_ID].children_IDs.size();

	// ΪҶ�ڵ㣬���ж�һ��
	if (n == 0 && sum == S) {
		int n_result, h;
		printf("%d", tmp[0]);
		n_result = tmp.size();
		for (h = 1; h < n_result; ++h)
			printf(" %d", tmp[h]);
		printf("\n");
	}


	for (i = 0; i < n; ++i)
		pre(nodes[parent_ID].children_IDs[i], sum);

	tmp.pop_back();
}


// �Ӵ�С����
bool cmp(int a, int b) {
	return nodes[a].weight > nodes[b].weight;
}

int main() {
	int N, M;
	int ID, K, child_ID;

	int i, h;

	scanf("%d %d %d", &N, &M, &S);
	// id ��0->(N-1)
	for (i = 0; i < N; ++i)
		scanf("%d", &(nodes[i].weight));

	for (i = 0; i < M; ++i) {
		scanf("%d %d", &ID, &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", &child_ID);
			nodes[ID].children_IDs.push_back(child_ID);
		}
		// ֱ�ӶԺ��ӽڵ�������������֤��dfs��˳����ǴӴ�С
		sort(nodes[ID].children_IDs.begin(), nodes[ID].children_IDs.end(), cmp);
	}
	int sum = 0;
	pre(0, sum);

		
	system("pause");
	return 0;
}