#include <stdio.h>

int qsPartition(int a[], int p, int r)
{
	int x = a[r];
	int i = p - 1;
	int j, temp;

	for (j = p; j < r; j ++) {
		if (a[j] <= x) {
			i ++;
			temp = a[i]; a[i] = a[j]; a[j] = temp;
		}
		temp = a[i + 1]; a[i + 1] = a[r]; a[r] = temp;
	}

	return i + 1;
}

void quickSort(int a[], int p, int r)
{
	int pivotpos;

	if (p < r) {
		pivotpos = qsPartition(a, p, r);
		quickSort(a, p, pivotpos - 1);
		quickSort(a, pivotpos + 1, r);
	}
}

int main()
{
	int a[] = {7, 3, 4, 2, 1, 6};
	int len = sizeof(a) / sizeof(int);
	int i = 0;

	printf("len = %d\n", len);
	quickSort(a, 0, len - 1);
	printf("The sorted array is : \n");
	for (i = 0; i < len; i ++) {
		printf("%d\t", a[i]);
	}
	printf("\n");

	return 0;
}

