#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long double lld;
#define all(x) (x).begin(), (x).end()

bool search(vector<int>& nums, int target) {
    
    int lo = 0 , hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return true;
        if (nums[mid] == nums[lo] && nums[mid] == nums[hi]) lo ++ , hi --;
        else if (nums[lo] <= nums[mid]) {
            if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        else if (nums[mid] <= nums[hi]) {
            if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }   
    return false;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int target; cin >> target;
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