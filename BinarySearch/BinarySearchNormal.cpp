#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long double lld;
#define all(x) (x).begin(), (x).end()

int search(vector<int>& nums, int target) {
    int lo = 0 , hi = nums.size() - 1 , ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            ans = mid; break;
        }
        else if (nums[mid] > target) hi = mid - 1;
        else if (nums[mid] < target) lo = mid + 1;
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); int target;
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> target;
    cout << search(v , target) << endl;
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