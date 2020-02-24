# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>

using namespace std;


int main(){
	double a[1001] = {0};
	int k, i, index;
	double tmp;
	
	scanf("%d", &k);
	for (i = 0; i < k; ++i){
		scanf("%d", &index);
		scanf("%lf", a + index);
	}

	scanf("%d", &k);
	for (i = 0; i < k; ++i) {
		scanf("%d", &index);
		scanf("%lf", &tmp);
		a[index] += tmp;
	}

	int sum = 0;
	for (i = 0; i < 1001; ++i){
		if (a[i] != 0)
			++sum;
	}

	printf("%d", sum);

	for (i = 1000; i >= 0; --i) {
		if (a[i] != 0)
			printf(" %d %.1lf", i, a[i]);
	}
		

	system("pause");
	return 0;
}