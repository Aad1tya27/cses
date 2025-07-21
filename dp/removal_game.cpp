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
const int maxint = 2e14 + 1;

pii dp[5002][5002][2];
 
pii func(int l , int r , vi &a, int turn){
    if(dp[l][r][turn] != make_pair(maxint, maxint)) return dp[l][r][turn];
 
    pii o1 = { a[l] , 0 };
    pii o2 = { 0 , a[l] };
    if(l == r) return tern(turn, o1, o2);
 
    pii ans1 = func(l+1, r, a, !turn);
    pii ans2 = func(l, r - 1, a, !turn);

    if(turn){
        ans1 = { ans1.F + a[l] , ans1.S };
        ans2 = { ans2.F + a[r], ans2.S };
        if(ans1.F != ans2.F){
            return dp[l][r][1] = tern(ans1 > ans2, ans1, ans2);
        }else return dp[l][r][1] = ans1;
    }else{
        ans1 = { ans1.F , ans1.S + a[l] };
        ans2 = { ans2.F , ans2.S + a[r] };
        if(ans1.S != ans2.S){
            return dp[l][r][0] = tern(ans1.S > ans2.S, ans1, ans2);
        }else return dp[l][r][0] = ans2;
    }
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n; cin>>n;
    vi a(n); asc(i, 0, n-1) cin>>a[i];

    asc(l, 0, 5000){
        asc(r, l, 5000){
            dp[l][r][0] = { maxint, maxint }; 
            dp[l][r][1] = { maxint, maxint }; 
        }
    }

    pii ans = func(0, n-1, a, 1);
    cout<<ans.F<<endl;
}