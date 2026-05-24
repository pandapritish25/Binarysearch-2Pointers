#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n , x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

    int head = -1 , tail = 0 , ans = 0 , sum = 0;

    while (tail < n) {
        while(head + 1 < n && sum + v[head + 1] <= x) {
            head ++; sum += v[head];
        }
        ans = ans + (head - tail + 1);
        if (tail <= head) {
            sum -= v[tail];
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
        }
    }

    cout << ans << endl;
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