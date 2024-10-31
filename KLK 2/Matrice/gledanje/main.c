#include <stdio.h>

void put_matrix(int n, int m, int a[n][m]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d\t", a[i][j]);
		putchar('\n');
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n][m];
	int curr = 1;
	for (int i = 0; i < m; ++i) {
		if (i % 2) {
			for (int j = n - 1; j >= 0; --j)
				a[j][i] = curr++;
		} else {
			for (int j = 0; j < n; ++j)
				a[j][i] = curr++;
		}
	}
	put_matrix(n, m, a);
	return 0;
}
