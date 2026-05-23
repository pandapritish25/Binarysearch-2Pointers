#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long double lld;
#define all(x) (x).begin(), (x).end()

int check(vector<int> &arr , int target , int mid) {
    return arr[mid] >= target;
}
int lower_bound(vector<int>& arr, int target) {    
    int lo = 0 , hi = arr.size() - 1 , ans = arr.size();
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(arr , target , mid)) ans = mid , hi = mid - 1;
        else lo = mid + 1;
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); int target;
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> target;
    cout << lower_bound(v , target) << endl;
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