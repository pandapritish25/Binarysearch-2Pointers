#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()


void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int size = ((n) * (n + 1)) / 2;
    int median = (size + 1) / 2;


    auto no_of_sb = [&](int k) {
        int head = -1 , tail = 0 , sum = 0 , ans = 0;
        while (tail < n) {
            while(head + 1 < n && sum + v[head + 1] <= k) {
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
        return ans;
    };

    auto check = [&](int mid) {
        int ans1 = no_of_sb(mid); 
        return ans1 >= median;
    };

    int sum = 0; for (auto x : v) sum += x;
    int lo = 0 , hi = sum , ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) ans = mid , hi = mid - 1;
        else lo = mid + 1;
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