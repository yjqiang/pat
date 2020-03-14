#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

#define N_MAX 3000
char a[N_MAX], b[N_MAX], result[N_MAX];

// a ��ת�õ� b����ȥ����λ0������2��
void myReverse(int n) {
	int i, k;
	for (i = 0, k = n - 1; i < n; ++i, --k)
		b[i] = a[k];
	// ��ֹ����
	b[n] = '\0';
}

// �����a�����λ��0
// ���ص�����ͣ��Լ�������ַ�������
int add(int n) {
	// a + b => ��a[n-1] + a[0] ��ʼ�õ�result�ĸ�λ������a[n-1]Ϊa�ĸ�λ��a[0]Ϊ��a�ĸ�λ
	int i, k;
	int sum = 0;
	for (i = 0, k = n - 1; i < n; ++i, --k) {
		sum += a[k] - '0' + a[i] - '0';
		result[i] = sum % 10 + '0';
		sum /= 10;
	}
	// ��λ��λ
	if (sum) {
		result[i] = sum + '0';
		++i;
	}

	n = i;
	for (i = 0, k = n - 1; i < k; ++i, --k)
		swap(result[i], result[k]);

	// result�����λresult[0]һ����0����Ϊa�����λ��0��sum�ж����ж�
	return n;
}

int main() {
	scanf("%s", a);

	int n = strlen(a); // a b��Ϊ��ת��λ��һ������λ0Ҳ�������ڣ���ȥ����λ0������2����
	int i;

	// ��ת��(����д������һ������Ϊ��ת�ͻ����ж��߼�˳������)
	myReverse(n);
	// �����ж����ж�ԭ�����Ƿ���ǻ�������
	if (strcmp(a, b) == 0) {
		printf("%s is a palindromic number.", a);
		system("pause");
		return 0;
	}

	// �ӷ�=>�Ա�����ж�=>��һ���ӷ�
	for (i = 0; i < 10; ++i) {
		// ����
		n = add(n);
		printf("%s + %s = %s\n", a, b, result);

		strcpy(a, result);

		// ��תresult
		myReverse(n);

		// �����ж�
		if (strcmp(a, b) == 0) {
			printf("%s is a palindromic number.", a);
			system("pause");
			return 0;
		}
			
	}
	printf("Not found in 10 iterations.");
	
	system("pause");
	return 0;
}