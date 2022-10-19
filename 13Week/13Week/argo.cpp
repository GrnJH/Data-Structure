#include <stdio.h>

void Selection(int A[], int N) {

	for (int last = N - 1; last >= 1; --last) {
		int Largest = 0;
		for (int current = 1; current <= last; current++) {
			if (A[current] > A[Largest])
				Largest = current;
		}
		int Temp = A[last];
		A[last] = A[Largest];
		A[Largest] = Temp;
	}
}

int main() {
	int A[5] = { 5, 3, 7, 2, 9 };

	Selection(A, 5);

	for (int i = 0; i < 5 ; i++) {
		printf("%d ", A[i]);
	}
}