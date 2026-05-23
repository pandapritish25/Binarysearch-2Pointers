// this is one of the exeptional problems inside the one means that this problem is basically based on the intermediate value theorm
// so what happens whenever we have a number at greater and smaller so this will come having a peak

// thus this is simple if (v[mid] < v[mid + 1]) lo = mid + 1 else hi = mid; and as we are keeping the hi at mid thus we can be able to return hi
// thus we can say that if v[mid] < v[mid + 1] and then that would be the ans;
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int findPeakElement(vector<int>& nums) {
    int lo = 0 , hi = nums.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < nums[mid + 1]) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    return lo;
}
void solve() {
    int n; cin >> n; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

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
