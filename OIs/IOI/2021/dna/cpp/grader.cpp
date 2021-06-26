#include "dna.h"
#include <cstdio>
#include <cassert>
#include <string>
#include <vector>

int main() {
	int n, q;
	assert(scanf("%d %d", &n, &q) == 2);
	char A[n+1], B[n+1];
	assert(scanf("%s", A) == 1);
	assert(scanf("%s", B) == 1);
	std::string a = std::string(A);
	std::string b = std::string(B);
	std::vector<int> x(q), y(q);
	for (int i = 0; i < q; i++) {
		assert(scanf("%d %d", &x[i], &y[i]) == 2);
	}
	fclose(stdin);
	std::vector<int> results(q);
	init(a, b);
	for (int i = 0; i < q; i++) {
		results[i] = get_distance(x[i], y[i]);
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", results[i]);
	}
	fclose(stdout);
	return 0;
}
