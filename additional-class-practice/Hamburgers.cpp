#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void solve() {
    string s; cin >> s;
    vector<int> has(3) , cost(3); int money;
    for (int i = 0; i < 3; i++) cin >> has[i]; for (int i = 0; i < 3; i++) cin >> cost[i]; cin >> money;

    int countb = 0 , counts = 0 , countc = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') countb ++;
        else if (s[i] == 'S') counts ++;
        else countc ++;
    }

    auto check = [&](int mid) {
        int needb = countb * mid; int needc = countc * mid; int needs = counts * mid;
        needb -= has[0]; needs -= has[1]; needc -= has[2]; needb = max(needb , 0LL); needs = max(needs , 0LL); needc = max(needc , 0LL);

        int total_money = needb * cost[0] + needs * cost[1] + needc * cost[2];
        return total_money <= money;
    };

    int lo = 0 , hi = 1e13 , ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) ans = mid , lo = mid + 1;
        else hi = mid - 1;
    }
    cout << ans;
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