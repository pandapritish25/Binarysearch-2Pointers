//https://atcoder.jp/contests/abc302/tasks/abc302_d
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve() {
    int n , m , x;
    cin >> n >> m >> x;
    vector<int> v(n) , y(m);
    for (int i = 0; i < n; i++) cin >> v[i]; for (int i = 0; i < m; i++) cin >> y[i];

    sort(v.begin() , v.end()); sort(y.begin() , y.end());
    reverse(v.begin() , v.end()); reverse(y.begin() , y.end());

    if (n < m) {
        swap(n , m); swap(v , y);
    }

    int left1 = 0 , left2 = 0 , max1 = INT_MIN;

    while(left1 < n && left2 < m) {
        int ans1 = abs(v[left1] - y[left2]);
        if (ans1 <= x) {
            max1 = max(max1 , v[left1] + y[left2]);
        }
        
        if (v[left1] >= y[left2]) left1 ++;
        else if (v[left1] < y[left2]) left2 ++;
    }
    if (max1 == INT_MIN) cout << -1 << endl;
    else cout << max1 << endl;
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