//https://atcoder.jp/contests/abc130/tasks/abc130_d
// Enough Array https://atcoder.jp/contests/abc130/tasks/abc130_d
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve() {
    int n , k; cin >> n >> k; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int head = -1 , tail = 0 , sum = 0 , ans = 0;
    while(tail < n) {
        while(head + 1 < n &&  sum < k) {
            sum += v[head + 1];
            head ++;
        }
        if (sum >= k) ans += (n - head);
        if (tail <= head) {
            sum -= v[tail];
            tail ++;
        }
        else {
            tail ++; head = tail - 1; sum = 0;
        }
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