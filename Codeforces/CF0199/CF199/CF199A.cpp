#include <bits/stdc++.h>
using namespace std;

int index(int a, std::vector<int> b) {
	int len = b.size();
  	for (int i = 0; i < len; i++)
  	{
  		if (b[i] == a)
  		{
  			return i;
  		}
  	}
  	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	vector<int> fib = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733};
  	if (n == 0)
  	{
  		cout<<"0 0 0";
  	}
  	else if (n == 1)
  	{
  		cout<<"1 0 0";
  	}
  	else
  	{
  		int j = index(n, fib);
  		cout<<fib[j-1]<<" "<<fib[j-2]<<" 0";
  	}
  	return 0;
}