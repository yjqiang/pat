#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

using namespace std;


int main() {
	int N;
	scanf("%d", &N);

	double result = 0;
	double double_tmp;
	int i;
	for (i = 0; i < N; ++i) {
		scanf("%lf", &double_tmp);
		// �±�Ϊi��Ԫ��������Ƭ�γ��ִ���(i + 1) * (N - i)��i��������i����i-0+1�֣��Ҳ����i����N-1-i+1�֣����

		//������һд���Ǵ�ģ���Ϊn���Ϊ10��5�η���(i + 1)* (n - i)���ܻᳬ��int�Ĵ洢��Χ��������
		//        sum+=(i+1)*(n-i)*double_tmp;
		result += double_tmp * (i + 1) * (N - i);
	}


	
	printf("%.2f", result);

	system("pause");
	return 0;
}