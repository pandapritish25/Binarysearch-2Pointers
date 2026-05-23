#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long double lld;
#define all(x) (x).begin(), (x).end()

int findPeakElement(vector<int>& nums) {
    int lo = 0 , hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < nums[mid + 1]) lo = mid + 1;
        else hi = mid;
    }
    return hi;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << findPeakElement(v) << endl;
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