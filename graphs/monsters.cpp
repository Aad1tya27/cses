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

/*
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
*/

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> graph(n);
    asc(i, 0, n - 1) cin >> graph[i];

    pii src;

    queue<vi> q;
    asc(i, 0, n-1){
        asc(j, 0, m-1){
            if(graph[i][j] == 'M') q.push({i,j,0});
            if(graph[i][j] == 'A') src = {i, j};            
        }
    }

    vector<vi> dp(n, vi(m, maxint));
    while(!q.empty()){
        auto vec = q.front();
        q.pop();
        int i = vec[0], j = vec[1], cur_lvl = vec[2];

        if(i < 0 || i >= n || j<0 || j >= m || dp[i][j] != maxint || graph[i][j] == '#') continue;
        dp[i][j] = cur_lvl;

        q.push({i+1,j, cur_lvl+1});
        q.push({i-1,j, cur_lvl+1});
        q.push({i,j-1, cur_lvl+1});
        q.push({i,j+1, cur_lvl+1});
    }
    vector<vector<char>> vis(n , vector<char>(m, 'X'));
    queue<pair<vi, char>> q1;
    q1.push({ {src.F, src.S, 0}, 'A'});
    pii flag = {-1, -1};

    while(!q1.empty()){
        auto pr = q1.front();
        q1.pop();
        int i = (pr.F)[0], j = (pr.F)[1], cur_lvl = (pr.F)[2];

        if(i < 0 || i >= n || j < 0 || j >= m || graph[i][j] == '#' || vis[i][j] != 'X') continue;
        vis[i][j] = pr.S;

        if(cur_lvl >= dp[i][j]) continue;

        if(i == 0 || i == n-1 || j == 0 || j == m-1){
            flag = {i ,j};
            break;
        }

        q1.push({{i+1,j, cur_lvl + 1}, 'D'});        
        q1.push({{i-1,j, cur_lvl + 1}, 'U'});
        q1.push({{i,j+1, cur_lvl + 1}, 'R'});
        q1.push({{i,j-1, cur_lvl + 1}, 'L'});
    }
    if(flag.F == -1){
        NO
        return 0;
    }
    YES
    string ans = "";
    while(true){
        if(graph[flag.F][flag.S] == 'A') break;
        ans.PB(vis[flag.F][flag.S]);

        if(vis[flag.F][flag.S] == 'U'){
            flag = { flag.F + 1, flag.S };
        }else if(vis[flag.F][flag.S] == 'D'){
            flag = { flag.F - 1, flag.S };
        }else if(vis[flag.F][flag.S] == 'R'){
            flag = { flag.F, flag.S - 1 };
        }else if(vis[flag.F][flag.S] == 'L'){
            flag = { flag.F, flag.S + 1};
        }
    }
    cout<<ans.size()<<endl;
    reverse(all(ans));
    cout<<ans<<endl;
}