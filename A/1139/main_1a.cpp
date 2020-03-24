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

// A ϲ�� B
int A, B;

int C, D;

// �ڽӱ�
vector<int> edges[ID_MAX];
bool is_negative[ID_MAX];

// һ��������������ab���� a*10000+b �� a+b*10000 ����ʾ��������ab֮���Ƿ��б�
set<int> connected;

vector<Node>results;


void check() {
	results.clear();
	int i, h;
	
	for (i = edges[A].size() - 1; i >= 0; --i) {
		C = edges[A][i];
		// C �� A �бߣ�CAͬ�ţ�C!= B
		if (is_negative[A] == is_negative[C] && C != B) {
			for (h = edges[C].size() - 1; h >= 0; --h) {
				D = edges[C][h];
				// D �� C �бߣ�D �� B �бߣ�D �� B ͬ�ţ�D != A
				if (connected.find(D * 10000 + B) != connected.end() && is_negative[D] == is_negative[B] && D != A)
					results.push_back(Node{ C, D });
			}
		}
	}
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i;
	int ID0, ID1;
	// ��-0000����sb�����
	char str_ID0[6], str_ID1[6];
	for (i = 0; i < M; ++i) {
		scanf("%s%s", str_ID0, str_ID1);
		ID0 = abs(atoi(str_ID0));
		ID1 = abs(atoi(str_ID1));

		edges[ID0].push_back(ID1);
		edges[ID1].push_back(ID0);

		is_negative[ID0] = (str_ID0[0] == '-');
		is_negative[ID1] = (str_ID1[0] == '-');

		connected.insert(ID0 * 10000 + ID1);
		connected.insert(ID0 + ID1 * 10000);
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