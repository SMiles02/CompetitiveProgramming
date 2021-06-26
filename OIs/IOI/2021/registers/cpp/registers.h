#include <vector>

void append_move(int t, int x);
void append_store(int t, std::vector<bool> v);
void append_and(int t, int x, int y);
void append_or(int t, int x, int y);
void append_xor(int t, int x, int y);
void append_not(int t, int x);
void append_left(int t, int x, int s);
void append_right(int t, int x, int s);
void append_add(int t, int x, int y);
void append_print(int t);
void construct_instructions(int s, int n, int k, int q);
