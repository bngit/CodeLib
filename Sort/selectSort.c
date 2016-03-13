#include <stdio.h>

void selectSort(int a[], int n)
{
	int i, j;
	int k;
	int temp;

	for (i = 0; i < n - 1; i ++) {
		k = i;
		for (j = i + 1; j < n; j ++) {
			if (a[j] < a[k])
				k = j;
		}
		if (k != i) {
			temp = a[k]; a[k] = a[i]; a[i] = temp;
		}
	}
}

int main()
{
	int a[] = {7, 3, 4, 2, 1, 6};
	int len = sizeof(a) / sizeof(int);
	int i = 0;

	printf("len = %d\n", len);
	selectSort(a, len);
	printf("The sorted array is : \n");
	for (i = 0; i < len; i ++) {
		printf("%d\t", a[i]);
	}
	printf("\n");

	return 0;
}

