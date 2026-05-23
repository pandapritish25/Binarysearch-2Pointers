#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int calc_nc2(int n) {
    if (n % 2 == 0) {
        int ans1 = n / 2; int ans2 = n - 1;
        int prod = ans1 * ans2 * 1LL;
        return prod;
    }
    else {
        int ans1 = (n - 1) / 2;int ans2 = n; 
        int prod = ans1 * ans2 * 1LL;
        return prod;
    }
    return 0;
}

int check(const vector<int> &v , int mid , int x) {
    return v[mid] > x;
}

int upperbound(const vector<int> &v , int x) {
    int lo = 0 , hi = v.size() - 1; int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(v , mid , x)) {
            ans = mid; hi = mid - 1;
        }
        else lo = mid + 1;
    }
    if (ans == -1) ans = v.size();
    return ans;
}

void solve() {  
    int n , k; cin >> n >> k;
    vector<int> v(n);

    int sum = 0;
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        int ans1 = upperbound(v , v[i] + k);
        int curr_index = i + 1; int needed_index = ans1;
        int rem_index = needed_index - curr_index;
        sum += calc_nc2(rem_index);
    }
    cout << sum << endl;
}    


signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t --) {
        solve();
    }
}