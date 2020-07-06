#include <bits/stdc++.h>
#define ll long long
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
  cout<<(n/2)*3;
  return 0;
}