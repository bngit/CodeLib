#include <stdio.h>

void directSort(int a[], int n)
{
	int i, j;
	int temp;

	for (i = 1; i < n; i ++) {
		j = i - 1;
		temp = a[i];
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j]; 
			a[j --] = temp;
		}
	}
}

int main()
{
	int a[] = {7, 3, 4, 2, 1, 6};
	int len = sizeof(a) / sizeof(int);
	int i = 0;

	printf("len = %d\n", len);
	directSort(a, len);
	printf("The sorted array is : \n");
	for (i = 0; i < len; i ++) {
		printf("%d\t", a[i]);
	}
	printf("\n");

	return 0;
}

