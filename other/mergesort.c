#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIST_SIZE 11


int *MergeSort(int *L, int l, int r);
void Merge(int *L, int l, int m, int r);
void PrintList(int *L, int start, int end);

int main(int argc, char const *argv[]) {
	int myList[LIST_SIZE] = {11, 7, 9, 1, 3, 4, 8, 6, 2, 10, 5}, i;

	for (i = 0; i < LIST_SIZE; i++) {
		printf("%d ", myList[i]);
	}
	printf("\n");

	MergeSort(myList, 0, LIST_SIZE - 1);

	for (i = 0; i < LIST_SIZE; i++) {
		printf("%d ", myList[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}

int *MergeSort(int *L, int l, int r) {
	int m;
	if (l < r) {
		m = floor((l + r) / 2);

		MergeSort(L, l, m);

		MergeSort(L, m + 1, r);

		Merge(L, l, m, r);
	}
	return L;
}

void Merge(int *L, int l, int m, int r) {
	int i, j, index;

	int *L1 = malloc(sizeof(int) * (m - l));
	int *L2 = malloc(sizeof(int) * (r - m + 1));

	i = 0;
	for (j = l; j <= m; j++) {
		L1[i++] = L[j];
	}
	i = 0;
	for (j = m + 1; j <= r; j++) {
		L2[i++] = L[j];
	}

	i = 0; j = 0, index = l;
	while (i <= m - l && j <= r - m - 1) {
		if (L1[i] < L2[j]) {
			L[index++] = L1[i++];
		} else if (L1[i] > L2[j]) {
			L[index++] = L2[j++];
		} else {
			L[index++] = L1[i++];
			L[index++] = L2[j++];
		}
	}
	while (i <= m - l) {
		L[index++] = L1[i++];
	}
	while (j <= r - m - 1) {
		L[index++] = L2[j++];
	}
}

void PrintList(int *L, int start, int end) {
	int i;
	for (i = start; i <= end; i++) {
		printf("%d ", L[i]);
	}
}
