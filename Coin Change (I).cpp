/***   Bismillahir Rahmanir Rahim   ***/

#include<bits/stdc++.h>
using namespace std;

#define     nn          '\n'
#define     ss          second
#define     ff          first
#define     sp(d, n)    fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());
#define     mem(a, x)   memset(a, x, sizeof a)

using ll =  long long;
using ld =  long double;
using ull = unsigned long long;
const ld pi = acos(-1.0);
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int mod = 100000007;
const int M = 1005;
const int N = 55;

int n, k, a[N], c[N], dp[N][M];
int find_ans(int i, int sum){
    if(sum > k)return 0;
    if(i == n + 1){
        if(sum == k)return 1;
        else return 0;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    int ans = 0;
    for(int j = 0; j <= c[i]; j++){
        ans += find_ans(i + 1, sum + a[i] * j);
        if(ans >= mod){
           ans -= mod;
        }
    }
    dp[i][sum] = ans;
    return ans;
}
void solution(){
    cin >> n >> k; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }

    cout << find_ans(1, 0) << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    cin >> t;
    //cin.ignore();
    while(t--){
        cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
