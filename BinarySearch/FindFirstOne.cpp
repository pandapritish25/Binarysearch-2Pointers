#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


// find the index for the 1st one inside the array

int find_first_one(vector<int> v) {
    // redefining the lo and hi and also the ans

    int lo = 0; int hi = v.size() - 1; int ans = -1;
    // finding the first one in a span of integers
    while (lo <= hi) {
        // mid is nothing but hi + lo / 2
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == 1) {
            // reducing the search space inside the array
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
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

    cout << find_first_one(v) << endl;
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
