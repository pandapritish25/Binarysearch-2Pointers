#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

void solve() {
    double n; cin >> n;
    vector<double> cor(n) , speed(n);
    for (int i = 0; i < n; i++) cin >> cor[i]; for (int i = 0; i < n; i++) cin >> speed[i];

    // checking in this time where these would be 
    auto check = [&](double mid) {
        double max1 = INT_MIN , min1 = INT_MAX;
        for (double i = 0; i < n; i++) {
            double left = cor[i] - speed[i] * mid;
            double right = cor[i] + speed[i] * mid;

            max1 = max(max1 , left); min1 = min(min1 , right);
        }
        return max1 <= min1;
    };

    double lo = 0 , hi = 1e13 , ans = 0;

    for (int i = 0; i < 100; i++) {
        double mid = lo + (hi - lo) / 2;
        // I need to check if a smaller intersection can interact or not
        if (check(mid)) ans = mid , hi = mid; else lo = mid;
    }
    cout << setprecision(12) << fixed << ans;
}   

signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}