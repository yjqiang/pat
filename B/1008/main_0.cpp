# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <cstdio>
# include <vector>
# include <ctime>
# include <iostream>
# include <cstring>
# include <climits>
# include <cmath>

using namespace std;

int a[100];
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	
	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", a + i);

	M = M % N;
	
	int index, element, tmp_index, tmp_element;
	int count = 0;
	int start;
	for (start = 0; count < N; ++start) {
		index = start;
		element = a[index];
		do {
			tmp_index = (index + M) % N;
			tmp_element = a[tmp_index];

			a[tmp_index] = element;

			index = tmp_index;
			element = tmp_element;
			++count;
		} while (index != start);
	}

	printf("%d", a[0]);
	for (i = 1; i < N; ++i)
		printf(" %d", a[i]);
	system("pause");
	return 0;
}