/*
SAMPLE GRADER for task BOOKS

USAGE:
place together with your solution and books.h in the same directory, then:
g++ <flags> sample_grader.cpp <solution_file>
e.g.:
g++ -std=c++17 sample_grader.cpp books.cpp

INPUT/OUTPUT:
The sample grader expects on standard input two lines. The first line should
contain the four integers N, K, A and S. The second line should contain a list
of N integers, the sequence of difficulties x_1 x_2 ... x_N which has to be
strictly increasing. Then, the grader writes to standard output a protocol of
all grader functions called by your program.
At the end, the grader prints your verdict.
*/
#include<vector>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<cstdarg>
#include<cassert>
#include"books.h"

using namespace std;

typedef long long ll;

void __attribute__((noreturn)) __attribute__((format(printf, 1, 2))) result(const char *msg, ...)
{
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(0);
}

namespace
{
    int N, K, S, sUsed;
    long long A;
    vector<long long> seq;
}

void impossible()
{
    result("Impossible (not checked): %d book(s) skimmed", sUsed);
    exit(0);
}

long long skim(int pos)
{
    printf("skim(%d): ", pos);
	if (pos<1 || pos>N) result("Invalid skim");
    printf("%lld\n", seq[pos]);
	sUsed++;
	if (sUsed>S) result("Out of books to skim");
    return seq[pos];
}

void answer(vector<int> v)
{
    printf("answer({");
    for(int i = 0; i < (int) v.size(); ++i)
    {
        printf("%d", v[i]);
        if(i + 1 != (int) v.size()) printf(", ");
    }
    printf("})\n");

	if ((int) v.size() != K) result("Invalid answer");
   	ll sum = 0;
	for(auto x: v) {
		if (x<1 || x>N) result("Invalid answer");
		sum += seq[x];
	}	
	if (sum < A || 2*A<sum) result("Wrong answer");

	result("Correct: %d book(s) skimmed", sUsed);
    exit(0);
}

int main()
{
    if(scanf("%d %d %lld %d", &N, &K, &A, &S) != 4)
        result("Invalid input");

    seq.resize(N + 1);
    for(int i = 1; i <= N; ++i) {
    	if(scanf("%lld", &(seq[i])) != 1) result("Invalid input");
		if(i>1 && seq[i]<=seq[i-1]) result("Invalid input");
   	}

    solve(N, K, A, S);

    result("No answer");
}
