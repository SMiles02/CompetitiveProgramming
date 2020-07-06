#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

bool op (const string &a, const string &b)
{
	int n=a.size();
	int m=b.size();
    if (n < m) return true;
    if (m < n) return false;
 
    for (int i = 0;i < n;i++)
    {
        if (a[i] < b[i]) return true;
        if (b[i] < a[i]) return false;
    }
    return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin>>s;
	if (op(s,"127"))
	{
		cout<<"byte";
	}
	else if (op(s,"32767"))
	{
		cout<<"short";
	}
	else if (op(s,"2147483647"))
	{
		cout<<"int";
	}
	else if (op(s,"9223372036854775807"))
	{
		cout<<"long";
	}
	else
	{
		cout<<"BigInteger";
	}
	return 0;
}