//https://codeforces.com/problemset/problem/1324/D
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;


void solve() {
    int n; cin >> n;
    vector<int> x(n) , y(n); 
    for (int i = 0; i < n; i++) cin >> x[i]; for (int i = 0; i < n; i++) cin >> y[i];
    vector<int> z_function;

    for (int i = 0; i < n; i++) {
        int diff = x[i] - y[i];
        z_function.push_back(diff);
    }
    sort(z_function.begin() , z_function.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int z_factor = (-1 * z_function[i]); z_factor ++;
        int ans1 = lower_bound(z_function.begin() + i + 1 , z_function.end() , z_factor) - z_function.begin();
        ans = ans + (n - ans1);
    }
    cout << ans << endl;
}                       
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}