#include <iostream>
//#include "Profiler.h";

using namespace std;

void listHeap(int H[], int n)
{
	for (int i = 0; i <= n; i++)
		printf("%d ", H[i]);
	printf("\n");
}

/// <summary>
/// Implementarea functiei HEAPIFY(H, i)
/// </summary>
/// <param name="H"></param>
/// <param name="n"></param>
int left(int i)
{
	return i * 2 + 1;
}
int right(int i)
{
	return i * 2 + 2;
}
int INDEX_OF_MAX(int a, int b, int c)
{
	int maximum = a;
	if (b > maximum)
		maximum = b;
	else
		if (c > maximum)
			maximum = c;
	return maximum;
}
void HEAPIFY(int H[], int i)
{
	int largest = INDEX_OF_MAX(H[i], H[left(i)], H[right(i)]);
	if (largest != i)
	{
		int aux = H[i];
		H[i] = H[largest];
		H[largest] = aux;
		HEAPIFY(H, largest);
	}
}
///Implementarea functiei build heap, strategie bottom-up
void BUILD_HEAP_bottomUp(int H[])
{
	int n = 5;
	for (int i = n / 2; i >= 1; i--)
	{
		HEAPIFY(H, i);
	}
}




void demo()
{
	int H[5] = {2, 1, 3, 5, 9};
	int n = 5;
	BUILD_HEAP_bottomUp(H);
	listHeap(H, n);
}
int main()
{
	demo();
	return 0;
}