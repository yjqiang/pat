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

// m 1 10 100����ʾ��λʮλ��λ��
// С�ڵ���N���Ҷ�Ӧλ��Ϊ1���������x
// ����ҪN/m >= 1����m��Ӧλ�������m��λ����
int findX(int N, int m) {
	// N % (m*10) / m��ʾ��Ӧλ
	// // ��ӦλΪ1������N
	if (N % (m * 10) / m == 1)
		return N;
	// ��Ӧλ����1����Ѹ�λ��Ϊ1���ɣ���λ��Ϊ999...999
	if (N % (m * 10) / m > 1)
		return N / (m * 10) * (m * 10) + 1 * m + (1* m-1);

	// ��ӦλС��1��Ϊ0������Ѹ�λ��һ���ɣ���λ��Ϊ999...999
	// ������Ա�֤ N / (m * 10) >= 1
	return (N / (m * 10) - 1) * (m * 10) + (1 * m - 1);

}

int main() {
	int N;
	scanf("%d", &N);

	int m = 1;
	int x;
	int sum = 0;
	for (m = 1; N / m >= 1; m *= 10) {
		x = findX(N, m);
		
		sum += (x / (m * 10)) * m + x % m + 1;
		// printf("m=%d  x=%d sum=%d\n", m, x, sum);
	}
	printf("%d", sum);

	

	system("pause");
	return 0;
}