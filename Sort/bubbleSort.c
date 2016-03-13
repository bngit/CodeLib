#include <stdio.h>

void bubbleSort(int a[], int len)
{
	int i, j;
	int	temp;

	for (i = 0; i < len - 1; i ++) 
		for (j = len - 1; j > i; j --) 
			if (a[j] < a[j - 1]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
}

int main()
{
	int a[] = {7, 3, 4, 2, 1, 6};
	int len = sizeof(a) / sizeof(int);
	int i = 0;

	printf("len = %d\n", len);
	bubbleSort(a, len);
	printf("The sorted array is : \n");
	for (i = 0; i < len; i ++) {
		printf("%d\t", a[i]);
	}
	printf("\n");

	return 0;
}

