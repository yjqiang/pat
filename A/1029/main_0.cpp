#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

#define N_MAX 200001
int a[N_MAX];



int main() {
	int i;
	int Na, Nb;
	scanf("%d", &Na);

	for (i = 0; i < Na; ++i)
		scanf("%lld", a + i);

	scanf("%d", &Nb);

	int wanted = (Na + Nb + 1) / 2;

	int cur;
	int index_a, index_b;
	int count;
	int element_a, element_b;

	int result;

	scanf("%d", &element_b);
	element_a = a[0];
	count = 0;


	for (index_b = 0, index_a = 0; index_a < Na && index_b < Nb && count < wanted; ++count) {
		if (element_b < element_a) {
			cur = element_b;  // the (count+1)th small num (1, 2, 3 ...)

			++index_b;
			if (index_b < Nb)
				scanf("%d", &element_b);
		}
		else {
			cur = element_a;  // the (count+1)th small num (1, 2, 3 ...)

			++index_a;
			element_a = a[index_a];
		}
	}

	for (; index_a < Na && count < wanted; ++count) {
		cur = element_a;

		++index_a;
		element_a = a[index_a];
	}
	for (; index_b < Nb && count < wanted; ++count) {
		cur = element_b;

		++index_b;
		if (index_b < Nb)
			scanf("%d", &element_b);

	}

	printf("%d", cur);

	system("pause");
	return 0;
}