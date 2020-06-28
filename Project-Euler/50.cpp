/*
*                                 Name : chaitanya
*
*                         Institute : ANITS,Visakhapatnam
*   "Don't regret anything you do, because in the end it makes you who you are."
*
*/
#include<cstdio>
#include<iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<complex>
#include<cstring>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<numeric>
#include<limits>
#include<climits>
#include<cfloat>
#include<functional>
#include<iterator>
#include <random>
#include<sstream>
#define infy  1000000000
#define all(x) begin(x),end(x)
#define ll long long int
#define ff first
#define ss second
#define pb push_back
const ll m = 1000000007;
#pragma GCC optimization ("O3")
using namespace std;

const int  N = 100 * 10000 + 4;
vector <bool> isPrime(N,true);
vector <int> primes;
void  seive()
{
    for (int i = 2; i*i <= N ; ++i)
    {
        if(isPrime[i])
        {
            for (int j = i*i; j <= N ; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; ++i)
    {
        if(isPrime[i])
            primes.pb(i);
    }
}
int main()
{
    seive();
    int sum = 0,ans = -1;

    for (int i = 0; i < primes.size(); ++i)
    {
        sum =0;
        for (int j = 0; j < primes.size(); ++j)
        {
            sum += primes[j];
            if (sum < 1000000 && isPrime[sum])
            {
                ans = max(ans,j-i+1);
            }
            if (sum > 1000000)
            {
                break;
            }
        }
    }
    cout << primes[ans];
    return 0;
}