#include <iostream>

using namespace std;

void draw(int dy, int dx) {
	while (dy != 0) {
		if (dy % 3 == 1 && dx % 3 == 1) {
			printf(" ");
			return;
		}
		dy /= 3;
		dx /= 3;
	}
	printf("*");
}

void callDraw(int n) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			draw(y, x);
		}
		printf("\n");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	callDraw(n);
}

/** NOT my own source !
