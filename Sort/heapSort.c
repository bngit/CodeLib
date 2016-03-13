#include <stdio.h>

#define LEFT(x) ((((x) + 1) << 1) - 1)
#define RIGHT(x) (((x) + 1) << 1)

void maxHeapify(int a[], int i, int heapSize)
{
	int lidx, ridx;
	int largest;
	int temp;

	lidx = LEFT(i);
	ridx = RIGHT(i);

	largest = (lidx <= heapSize - 1 && a[lidx] > a[i]) ? lidx : i;
	if (ridx <= heapSize - 1 && a[ridx] > a[largest]) largest = ridx;

	if (largest != i) {
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		maxHeapify(a, largest, heapSize);		
	}
}

void buildMaxHeap(int a[], int len)
{
	int i;

	for (i = len / 2; i > 0; i --)
		maxHeapify(a, i, len);
}

void heapSort(int a[], int len)
{
	int i;
	int temp;

	buildMaxHeap(a, len);
	for (i = len - 1; i >= 0; i --) {
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		maxHeapify(a, 0, i);
	}
}

int main()
{
	int a[] = {7, 3, 4, 2, 1, 6};
	int len = sizeof(a) / sizeof(int);
	int i = 0;

	printf("len = %d\n", len);
	heapSort(a, len);
	printf("The sorted array is : \n");
	for (i = 0; i < len; i ++) {
		printf("%d\t", a[i]);
	}
	printf("\n");

	return 0;
}

