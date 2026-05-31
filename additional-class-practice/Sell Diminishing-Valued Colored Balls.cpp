#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

// one of the good questions in which we would be needing to find exactly till which place can be taken
using ll = long long;
const int MOD = 1e9 + 7;

ll ceil_div(ll n) {
    if (n % 2 == 0) {
        ll ans1 = n / 2; ll ans2 = n + 1; ll ans = ans1 * ans2;
        return ans;
    }
    else {
        ll ans1 = (n + 1) / 2; ll ans2 = n; ll ans = ans1 * ans2;
        return ans;
    }
}
int maxProfit(vector<int>& v, int orders) {
    ll n = v.size();
    sort(v.begin() , v.end());
    auto check = [&](int mid) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            int balls_above = max(v[i] - mid + 1 , 0LL);
            sum += balls_above;
        }
        return sum;
    };
    ll lo = 1 , hi = *max_element(v.begin() , v.end()) , ans = 0;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid) >= orders) ans = mid , lo = mid + 1;
        else hi = mid - 1;
    }
    ll last_layer = ans + 1;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll balls_above = max(v[i] - last_layer + 1 , 0LL);
        sum += ceil_div(v[i]) - ceil_div(v[i] - balls_above);
        sum %= MOD;
    }
    
    // no of balls in last layer and no of balls in last layer - 1
    ll ans1 = check(last_layer);
    ans1 %= MOD;

    ll need_to_take = orders - ans1;
    need_to_take %= MOD;

    sum = sum + need_to_take * (last_layer - 1);
    sum %= MOD;
    return sum;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int orders; cin >> orders;

    cout << maxProfit(v , orders);
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