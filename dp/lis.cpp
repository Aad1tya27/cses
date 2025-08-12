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

// prints len(lis) and also the longest sequence
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n; cin>>n;
    vi a(n); asc(i, 0, n-1) cin>>a[i];

    vi dp; dp.PB(-maxint);
    int l = 0;    
    vi p(n+1, -1);
    vi idx(n+1, -1);
    asc(i, 0, n-1){
        if(a[i] > dp[l]){
            dp.PB(a[i]);
            l++;
            idx[l] = i;
            p[i] = idx[l-1];
        }else{
            auto it = lower_bound(all(dp), a[i]);
            if((*it) == a[i]) continue;
            int id = it - dp.begin();
            dp[id] = a[i];
            idx[id] = i;
            p[i] = idx[id-1];
        }
    }
    cout<<l<<endl;
    vi seq;
    int pos = idx[l];
    while(pos != -1){
        seq.PB(a[pos]);
        pos = p[pos];
    }
    reverse(all(seq));
    for(auto &x: seq) cout<<x<<" ";
    cout<<endl;
} // O(nlogn)

// two auxiallary arrays are constructed to store the idx: current index of the dp array els
//                                                    p : parent / ancestor of the current el