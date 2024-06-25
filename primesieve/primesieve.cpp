/* Given Q queries and in each query number n
check whether the given number is prime or not */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> isprime(n + 1, 1);

	isprime[1] = 0;

	for (int i = 2; i * i <= n;)
	{

		if (isprime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				isprime[j] = 0;
			}
		}
		if (i == 2)
		{
			i++;
		}
		else
		{
			i += 2;
		}
	}
	vector<int> store(n + 1, 0);
	int previous = -1;

	for (int i = n; i >= 0; i--)
	{
		store[i] = previous;
		if (isprime[i])
		{
			previous = i;
		}

	}
	for(int i=0;i<n;i++){
	cout<<store[i]<<" ";
	}
}
