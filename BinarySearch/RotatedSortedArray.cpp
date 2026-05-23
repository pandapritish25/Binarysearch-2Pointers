#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int find_first_one(vector<int> v) {
    int last_element = v.back();
    int lo = 0; int hi = v.size() - 1; int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] <= last_element) {
            ans = mid; 
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n; 
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << find_first_one(v) << endl;
}


signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    cin >> t;
    while (t --) {
        solve();
    }
}