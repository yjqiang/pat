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

string name;
// ��ֹ�ظ��н�
set<string> lucky_dogs;

int main() {
	int M, N, S;
	cin >> M >> N >> S;

	// ��һ�����˶����±�
	int next_lucky_dog = S;
	int i;
	for (i = 1; i <= M; ++i) {
		cin >> name;
		if (i == next_lucky_dog) {
			if (lucky_dogs.find(name) == lucky_dogs.end()) {
				printf("%s\n", name.c_str());
				next_lucky_dog += N;
				lucky_dogs.insert(name);
			}
			else
				// �ظ��н�������������һ����
				++next_lucky_dog;
		}
	}

	// Mδ����S��һ��û���н���
	// ����һ�����н�
	if (M < S)
		printf("Keep going...");

	system("pause");
	return 0;
}