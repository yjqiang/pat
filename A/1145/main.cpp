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

// Msize_MAX Ҫ�ϵ������������
#define Msize_MAX 20000
int Msize, N, M;

// Ĭ��Ϊ0����ʾ��λ�ÿ�ȱ
int hash_table[Msize_MAX] = { 0 };


bool isPrime(int num) {
	if (num <= 1)
		return false;
	if (num % 2 == 0 && num != 2)
		return false;
	int end = (int)sqrt(num) + 1;
	int i;
	for (i = 3; i <= end; ++i)
		if (num % i == 0)
			return false;
	return true;
}

int sum_search_time = 0;

void mySearch(int num) {
	int i;
	int position;
	for (i = 0; i < Msize; ++i) {
		position = (num + i * i) % Msize;
		// hash_table[position] == 0 λ�ÿ�ȱ�������˵����ѯʧ����
		// hash_table[position] == num ��ѯ�ɹ�
		if (hash_table[position] == 0 || hash_table[position] == num) {
			sum_search_time += i + 1;
			return;
		}
	}

	// �Ҿ���Ӧ�ü���Msize�ģ���Ȼ�������ǵ�����˵զ�Ӿ�զ��
	sum_search_time += Msize + 1;
}


int main() {
	
	scanf("%d%d%d", &Msize, &N, &M);
	while (!isPrime(Msize))
		++Msize;

	int num, position;
	int i, h;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);

		// (Msize+x)^2  = Msize*Msize + 2*x*Msize + x^2   �� x^2  Ч��һ����
		for (h = 0; h < Msize; ++h) {
			position = (num + h * h) % Msize;
			// λ�ÿ�ȱ
			if (hash_table[position] == 0) {
				hash_table[position] = num;
				break;
			}
			
		}
		if (h == Msize)
			printf("%d cannot be inserted.\n", num);
	}

	
	for (i = 0; i < M; ++i) {
		scanf("%d", &num);
		mySearch(num);
		
	}
	printf("%.1lf", (double)sum_search_time / M);


	system("pause");
	return 0;
}