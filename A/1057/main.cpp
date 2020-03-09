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

using namespace std;

#define key_MAX 100001

char commands[3][11] = { "Push", "Pop", "PeekMedian" };

vector<int> s;
// a[i]��ʾ����i���ֵĴ�����cΪi��Ӧ����״����
int c[key_MAX] = { 0 };

int lowbit(int i) {
	// -i xxx10000-> (!x)(!x)(!x)01111 + 1 = (!x)(!x)(!x)10000   �����෴������ȡ����һ
	// i & (-i)  -> 00010000   ��ĩβ��1��ȡ��ʣ��λĨ��
	return i & (-i);
}

// a[x] += v
// O(lgn)
void T_add(int x, int v) {
	int i;
	// ͳ��ֻ��100000���ɣ�cҲֻҪ���������
	// i ������ c[j] ��Ҫ���� j - 2^k < i < j; j > i ���߸�λ��0����󣬴Ӹ�λ��ʼһһ�Ƚϣ���һ����ͬ�����֣�j��ӦΪ1��i��ӦΪ0
	// j - lowbit(j) < i�� ��j��i��Ӧ��λ��ͬ��1 �� j�ĵ�λ1  ������ͬһ��1
	// ��������i��j��������i��0λ���ĳ�1��֮���λȫ��Ĩ0
	// ����i += lowbit(i)
	for (i = x; i < key_MAX; i += lowbit(i))
		c[i] += v;
}

// O(lgn)
// sum(x)����a[1] + ... + a[x]����ʾ�˴�1��x�����Χ�ڳ��ֵ����ֵ��ܴ���
int T_sum(int x) {
	int i;
	int result = 0;
	for (i = x; i > 0; i -= lowbit(i))
		result += c[i];
	return result;
}

// ���ֲ���
// ��Ϊsum(x)��ʾ�˴�1��x��Χ�ڵ����ָ�������ô�ҵ�kС�����֣���1��ʼ������Ҫsum(i)>=k��sum(i-1)<k����������ڵ���k����Сֵ
int T_find() {
	//�ϲ��߼�
	int k = (s.size() + 1) / 2;
	int low = 1, high = key_MAX - 1;

	int mid;
	while (low < high) {
		mid = (low + high) / 2;
		if (T_sum(mid) >= k)
			high = mid;
		else
			low = mid + 1;
	}
	// һ���н��
	return low;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void push(int num) {
	s.push_back(num);
}
void pop() {
	if (s.empty())
		printf("Invalid\n");
	else {
		int i = s.back();
		printf("%d\n", i);
		// a[i] += -1����Ӧ��״����Ҳ�ø��� 
		T_add(i, -1);
		s.pop_back();
	}
}

void peekMedian() {
	if (s.empty())
		printf("Invalid\n");
	else
		printf("%d\n", T_find());
}


int main() {
	int N;
	scanf("%d", &N);
	
	int i;
	char command[11];
	int num;
	for (i = 0; i < N; ++i) {
		scanf("%s", command);

		if (strcmp(command, commands[0]) == 0) {
			scanf("%d", &num);
			push(num);
			// a[num] += 1����Ӧ��״����Ҳ�ø��� 
			T_add(num, 1);
		}	
		else if (strcmp(command, commands[1]) == 0)
			pop();
		else
			peekMedian();
	}

	system("pause");
	return 0;
}