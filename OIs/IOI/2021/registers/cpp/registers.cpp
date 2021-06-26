#include "registers.h"
#include <bits/stdc++.h>
using namespace std;

void construct_instructions(int s, int n, int k, int q) {
	append_right(1, 0, 2);
	append_and(2, 0, 1);
	//append_print(0);
	append_xor(3, 0, 1); //EF
	append_right(3, 3, 1);
	//append_print(3);
	vector<bool> w(2000, 0);
	w[0] = 1;
	append_store(5, w);
	//append_print(5);
	append_and(6, 3, 5); //0/1 based on E
	//append_print(6);
	append_add(8, 6, 6);
	append_add(8, 6, 8); //00 or 11 based on E
	w[1] = 1;
	append_store(9, w);
	append_xor(10, 8, 9);
	//append_print(8);
	//append_print(10);
	append_and(69, 2, 10); //sets 69 to & if E = 0
	
	append_right(11, 0, 1);
	append_right(12, 1, 1);
	append_or(11, 0, 11);
	append_or(12, 1, 12);
	append_and(11,5,11);
	append_and(12,5,12);
	append_and(13,11,12);
	//append_print(13);
	append_and(14,8,13);
	append_add(0,69,14);
	
	//append_print(69);
	return;
}

/**
0 2 2 1000
1 3

**/
