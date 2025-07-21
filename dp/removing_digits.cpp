#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define pii pair<ll, ll>
#define vi vector<ll>
#define mii map<ll, ll>
#define all(x) x.begin(), x.end()
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define tern(x, y, z) ((x) ? (y) : (z))
#define PB push_back
#define F first
#define S second
#define asc(i, a, b) for (int i = a; i <= b; i++)
#define desc(i, a, b) for (int i = a; i >= b; i--)

const int M = 1e9 + 7;
const int N = 1e5 + 5;
const int maxint = 2e9 + 1;

vi dp(1e6 + 10, -1);

int func(int n){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    vi digits;
    int n1 = n;
    while(n1){
        digits.PB(n1%10);
        n1 /= 10;
    }
    int ans = maxint;
    for(auto &x: digits){
        if(!x) continue;
        ans = min(func(n - x) + 1, ans);
    }
    return dp[n] = ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin>>n;
    cout<<func(n)<<endl;
}