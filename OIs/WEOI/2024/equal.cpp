#include "equal.h"
#include <vector>
using namespace std;
 
void make_all_equal(int N, int, int) {
    for (int p = 2; p <= N; p *= 2) {
        vector<int> query_indices;
        for (int i = 0; i + p - 1 < N; i += p) {
            for (int j = i; j < i + p / 2; ++j) {
                query_indices.push_back(j);
            }
        }
        for (int i = 18 + __lg(p); i >= 0; --i) {
            add(query_indices, 1 << i);
        }
        query_indices.clear();
        for (int i = 0; i + p - 1 < N; i += p) {
            if (!compare(i, i + p - 1)) {
                for (int j = i; j < i + p / 2; ++j) {
                    query_indices.push_back(j);
                }
            }
        }
        if (!query_indices.empty()) {
            add(query_indices, 1);
        }
    }
}
