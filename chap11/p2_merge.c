#include <stdio.h>

#define LEN 8

int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

void merge(int start, int mid, int end)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int left[n1], right[n2];
	int i, j, k;

	/* left holds a[start...mid] */
	for (i = 0; i < n1; i++) {
		left[i] = a[start + i];
	}

	/* right holds a[mid+1...end] */
	for (j = 0; j < n1; j++) {
		right[j] = a[mid + 1 + j];
	}

	i = j = 0;
	k = start;
	while (i < n1 && j < n2) {
		if (left[i] < right[j]) {
			a[k++] = left[i++];
		} else {
			a[k++] = right[j++];
		}
	}

	/* left[] is not exhausted */
	while (i < n1) {
		a[k++] = left[i++];
	}
	/* right[] is not exhausted */
	while (j < n2) {
		a[k++] = right[j++];
	}
}

void sort(int start, int end)
{
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		printf("sort\t(%d-%d, %d-%d)\t%d %d %d %d %d %d %d %d\n", start, mid, mid + 1, end, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
		sort(start, mid);
		sort(mid + 1, end);
		merge(start, mid, end);
		printf("merge\t(%d-%d, %d-%d)\t%d %d %d %d %d %d %d %d\n", start, mid, mid + 1, end, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
	}
}

int main(void)
{
	sort(0, LEN - 1);
	return 0;
}
