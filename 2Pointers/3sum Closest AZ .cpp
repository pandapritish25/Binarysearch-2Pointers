#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()


void solve() {
    int n , x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));

    int res = v[0] + v[1] + v[2];

    for (int i = 0; i < n; i++) {
        int j = i + 1 , k = n - 1;
        while(j < k) {
            int ans1 = v[i] + v[j] + v[k];
            if (ans1 == x) {
                cout << 0 << endl; return;
            }
            if (abs(ans1 - x) < abs(res - x)) res = ans1;
            if (ans1 > x) k --;
            else j ++;
        }
    }
    cout << abs(res - x) << endl;
}                        
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}