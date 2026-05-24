#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n , k , d; cin >> n >> k >> d;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int head = -1 , tail = 0, max1 = LLONG_MIN , sum = 0 , count = 0;
    multiset<int> s; 

    vector<int> psum; for (int i = 0; i < n; i++) sum += v[i] , psum.push_back(sum);
    while(tail < n) {
        while(head + 1 < n &&((count < k && v[head + 1]) || (count <= k && v[head + 1] % 2 == 0))) {
            head ++;
            if (v[head] % 2) count ++; 
            s.insert(psum[head]);
        }
        int base = (tail == 0 ? 0 : psum[tail - 1]);
        auto it = s.upper_bound(base + d);
        if (it != s.begin()) {
            it --; max1 = max(max1 , *it - base);
        }
        if (tail <= head) {
            if (v[tail] % 2) count --;
            s.erase(s.find(psum[tail]));
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
        }
    }

    if (max1 == LLONG_MIN) cout << "IMPOSSIBLE\n";
    else cout << max1 << "\n";
    
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