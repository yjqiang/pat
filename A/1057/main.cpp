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
// a[i]表示数字i出现的次数，c为i对应的树状数组
int c[key_MAX] = { 0 };

int lowbit(int i) {
	// -i xxx10000-> (!x)(!x)(!x)01111 + 1 = (!x)(!x)(!x)10000   补码相反数等于取反加一
	// i & (-i)  -> 00010000   最末尾的1提取，剩余位抹零
	return i & (-i);
}

// a[x] += v
// O(lgn)
void T_add(int x, int v) {
	int i;
	// 统计只到100000即可，c也只要到这里就行
	// i 包含在 c[j] 的要求是 j - 2^k < i < j; j > i 两者高位补0对齐后，从高位开始一一比较，第一个不同的数字，j对应为1，i对应为0
	// j - lowbit(j) < i， 则j与i对应高位不同的1 和 j的低位1  必须是同一个1
	// 这样根据i求j，就是找i的0位，改成1，之后的位全部抹0
	// 就是i += lowbit(i)
	for (i = x; i < key_MAX; i += lowbit(i))
		c[i] += v;
}

// O(lgn)
// sum(x)就是a[1] + ... + a[x]；表示了从1到x这个范围内出现的数字的总次数
int T_sum(int x) {
	int i;
	int result = 0;
	for (i = x; i > 0; i -= lowbit(i))
		result += c[i];
	return result;
}

// 二分查找
// 因为sum(x)表示了从1到x范围内的数字个数，那么找第k小的数字（从1开始），需要sum(i)>=k且sum(i-1)<k，即满足大于等于k的最小值
int T_find() {
	//合并逻辑
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
	// 一定有结果
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
		// a[i] += -1，对应树状数组也得更新 
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
			// a[num] += 1，对应树状数组也得更新 
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