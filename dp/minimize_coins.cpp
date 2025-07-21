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
    
const int max_val = 1e6 + 2;
vi dp(max_val, -1);
int func(vi &c, int rem){
    if(!rem) return 0;
    if(rem < 0) return maxint;

    if(dp[rem] != -1) return dp[rem];
    int n = c.size();
    int ans = maxint;
    asc(i, 0, n-1){
        ans = min(ans, func(c, rem - c[i]) + 1);
    }
    return dp[rem] = ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,x; cin>>n>>x;
    vi c(n); asc(i, 0, n-1) cin>>c[i];

    int ans = func(c, x);
    cout<<tern(ans == maxint, -1, ans)<<endl;
}