#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin() , nums.end());
    int res = nums[0] + nums[1] + nums[2]; int n = nums.size();
    for (int i = 0; i < n; i++) {
        int j = i + 1 , k = n - 1;
        while(j < k) {
            int ans1 = nums[i] + nums[j] + nums[k];
            if (ans1 == target) return target;
            else if (ans1 > target) k --;
            else if (ans1 < target) j ++;

            if (abs(ans1 - target) < abs(res - target)) {
                res = ans1;
            }
        }
    }
    return res;
}
void solve() {
    int n , x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int ans = threeSumClosest(v , x);
    cout << ans;
}                        
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}