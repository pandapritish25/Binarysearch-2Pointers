#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin() , nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1 , k = n - 1;

        while(j < k) {
            if (nums[i] + nums[j] + nums[k] == 0) {
                ans.push_back({nums[i] , nums[j] , nums[k]});
                j ++; k --;
                while(j < k && nums[j] == nums[j - 1]) j ++;
                while(j < k && nums[k] == nums[k + 1]) k --;
            }
            else if (nums[i] + nums[j] + nums[k] > 0) k --;
            else if (nums[i] + nums[j] + nums[k] < 0) j ++;
        }
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> ans = threeSum(v);
    for (auto x : ans) {
        for (auto i : x) cout << i << " ";
        cout << endl;
    }
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