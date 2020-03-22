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

#define N_MAX 50001

// numΪ1,2...N
// count����counts[num]
struct Record {
	int num;
	int count;

	// ע�⣡����������������������������������������������������
	bool operator<(const Record& b) const{
		if (count != b.count)
			return count > b.count;
		return num < b.num;
	}
};

// records�洢��Record��numһ�����ظ���
set<Record> records;

// ͳ��
int counts[N_MAX] = { 0 };


int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	int i;
	int num;
	int count_K;
	set<Record>::iterator set_i;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		// ��һ��Ԫ��֮ǰû��ͳ�����ݣ�����ӡ
		if (i > 0) {
			printf("%d:", num);

			for (set_i = records.begin(), count_K = 0; set_i != records.end() && count_K < K; ++set_i, ++count_K)
				printf(" %d", set_i->num);
			printf("\n");
		}
		// ˢ��records
		// ��num�����¼�ˣ�ɾ���ϵģ�ˢ���¼�¼
		// û��num��¼��ˢ��Record{num, 1}
		set_i = records.find(Record{ num, counts[num] });
		if (set_i != records.end())
			records.erase(set_i);
		++counts[num];
		records.insert(Record{ num, counts[num] });
	}


	system("pause");
	return 0;
}