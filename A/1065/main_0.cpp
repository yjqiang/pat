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

using namespace std;

char abs_result[70];

// �Ի�����Ϊ�Ӽ��ǴӸ�λ->ʮλ->������  Ҫ��������λ����
void revert(char* a, int n) {
	int i, k;
	for (i = 0, k = n - 1; i < k; ++i, --k)
		swap(a[i], a[k]);
}

// �������������
int myAdd(char* abs_A, char* abs_B, int n_abs_A, int n_abs_B) {
	revert(abs_A, n_abs_A);
	revert(abs_B, n_abs_B);

	int i;
	int sum = 0;
	int element_A, element_B;
	for (i = 0; i < n_abs_A || i < n_abs_B; ++i) {
		element_A = (i < n_abs_A) ? abs_A[i] - '0' : 0;
		element_B = (i < n_abs_B) ? abs_B[i] - '0' : 0;
		sum += element_A + element_B;
		abs_result[i] = sum % 10 + '0';
		sum /= 10;
	}
	if (sum != 0) {
		abs_result[i] = '0' + sum;
		++i;
	}
	// ��\0
	abs_result[i] = '\0';

	revert(abs_result, i);
	return i;
}

// �����������ļ���������abs_Aһ�����ڵ���abs_B
int mySubstract(char* abs_A, char* abs_B, int n_abs_A, int n_abs_B) {
	revert(abs_A, n_abs_A);
	revert(abs_B, n_abs_B);

	int i;
	int sum = 0;
	int result;
	int element_A, element_B;
	for (i = 0; i < n_abs_A || i < n_abs_B; ++i) {
		element_A = (i < n_abs_A) ? abs_A[i] - '0' : 0;
		element_B = (i < n_abs_B) ? abs_B[i] - '0' : 0;
		result = sum + element_A - element_B;
		if (result < 0) {
			sum = -1; // ��λ
			result += 10;
		}
		else
			sum = 0;
		abs_result[i] = result + '0';
	}
	// assert sum == 0 ������Ϊ�����������Ҫ��abs_Aһ�����ڵ���abs_B��������
	// ��\0
	abs_result[i] = '\0';

	// ȥ����λ��0
	int k;
	for (k = i - 1; k >= 0 && abs_result[k] == '0'; --k)
		abs_result[k] = '\0';
	

	// ���Ϊ0
	if (k == -1) {
		abs_result[0] = '0';
		abs_result[1] = '\0';
		i = 1;
	}
	else {
		i = k + 1;
	}

	revert(abs_result, i);
	return i;
}

// �����������ıȽ�
int myCmp(char* abs_A, char* abs_B, int n_abs_A, int n_abs_B) {
	// λ����ͬ���̵�С
	if (n_abs_A != n_abs_B)
		return n_abs_A - n_abs_B;
	// λ����ͬ���Ӹ�λ��ʼ�Ƚ�
	return strcmp(abs_A, abs_B);
}

int main() {
	int T;
	char A[70], B[70], C[70];
	bool is_negative_A, is_negative_B, is_negative_C;

	bool is_negative_result;
	char* abs_A, * abs_B, * abs_C;  // ��ȡ����ֵ����
	int n_abs_A, n_abs_B, n_abs_C, n_abs_result;

	scanf("%d", &T);
	int i;
	int cmp_result;
	for (i = 1; i <= T; ++i) {
		scanf("%s%s%s", A, B, C);
		// �ж�������
		if (A[0] == '-') {
			is_negative_A = true;
			abs_A = A + 1;
		}
		else {
			is_negative_A = false;
			abs_A = A;
		}

		if (B[0] == '-') {
			is_negative_B = true;
			abs_B = B + 1;
		}
		else {
			is_negative_B = false;
			abs_B = B;
		}

		if (C[0] == '-') {
			is_negative_C = true;
			abs_C = C + 1;
		}
		else {
			is_negative_C = false;
			abs_C = C;
		}

		n_abs_A = strlen(abs_A);
		n_abs_B = strlen(abs_B);
		n_abs_C = strlen(abs_C);

		// A B ����һ�£�����ֵ��ӣ��������������ABһ��
		if (is_negative_A == is_negative_B) {
			n_abs_result = myAdd(abs_A, abs_B, n_abs_A, n_abs_B);
			is_negative_result = is_negative_A;
		}
		else {
			// assert A����ֵ���ڵ���B����ֵ
			cmp_result = myCmp(abs_B, abs_A, n_abs_B, n_abs_A);
			if (cmp_result > 0) {
				swap(abs_A, abs_B);
				swap(is_negative_A, is_negative_B);
			}
			// A B��ţ�A����ֵ���ڵ���B�ľ���ֵ����AΪ�������Ϊ������������Ϊ0����ôis_negative_result Ϊ false
			is_negative_result = is_negative_A && cmp_result != 0 ? true : false;
			n_abs_result = mySubstract(abs_A, abs_B, strlen(abs_A), strlen(abs_B));

		}
		if (is_negative_C == is_negative_result) {
			cmp_result = myCmp(abs_result, abs_C, n_abs_result, n_abs_C);
			if (cmp_result > 0 && !is_negative_result || cmp_result < 0 && is_negative_result)
				printf("Case #%d: true\n", i);
			else
				printf("Case #%d: false\n", i);
		}
		// ���Ϊ����CΪ����
		else if (is_negative_result == true)
			printf("Case #%d: false\n", i);
		else	
			printf("Case #%d: true\n", i);
		// printf("=>   %c%s %d\n", is_negative_result? '-': '+', abs_result, n_abs_result);
	}

	system("pause");
	return 0;
}