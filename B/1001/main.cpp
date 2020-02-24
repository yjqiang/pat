# define _CRT_SECURE_NO_WARNINGS
# include <iostream>

using namespace std;

int main(){
	int a;
	scanf("%d", &a);

	
	int i = 0;
	while (a != 1){
		if (a % 2)
			a = (a * 3 + 1) / 2;
		else
			a = a / 2;
		++i;
	}
	printf("%d", i);
	
	system("pause");
	return 0;
}