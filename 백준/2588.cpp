#include <bits/stdc++.h>

int main() {
	int a, b, t;
	scanf_s("%d%d", &a, &b);
	t = b;
	if (t < 10) {
		printf("%d", a * b);
		return 0;
	}
	while (t !=0) {
		printf("%d\n", (t%10)*a);
		t /= 10;
	}
	printf("%d", a * b);
	return 0;
}