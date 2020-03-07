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


int main() {
	int N;
	scanf("%d", &N);
	// m=1 10 100  ��λʮλ��λ
	int m = 1;
	// ��ǰλ����࣬��ǰλ���Ҳ�
	int left, mid, right;
	int sum = 0;
	for (m = 1; N / m >= 1; m *= 10) {
		left = N / (m * 10);
		mid = N / m % 10;
		right = N % m;

		if (mid == 1)
			// (0-(left-1))1(0-999..99) ���������� left * m����(left)1(0-right) һ��right + 1��
			sum += left * m + (right + 1);
		else if (mid == 0)
			// (0-(left-1))1(0-999..99) ���������� left * m��
			sum += left * m;
		else
			// (0-left)1(0-999..99) ���������� (left+1) * m��
			sum += (left + 1) * m;
	
	}
	printf("%d", sum);

	

	system("pause");
	return 0;
}