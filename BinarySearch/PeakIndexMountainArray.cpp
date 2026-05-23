#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// basically this is the check function
bool check (vector<int> v , int mid) {
    if (mid != v.size() - 1 && v[mid] > v[mid + 1]) return true;
    return false;
}
// this is the binary search function
int binarySearch(vector<int> v) {
    int lo = 0 , hi = v.size() - 1 , ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(v , mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return ans;
}
// calling the peak index
int peakIndexInMountainArray(vector<int>& arr) {
    return binarySearch(arr);
}
void solve() {
    int n; cin >> n; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << peakIndexInMountainArray(v) << endl;
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
