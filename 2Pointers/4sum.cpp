#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); vector<vector<int>> ans;
    sort(nums.begin() , nums.end());

    for (int i = 0; i < n ;i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;
            int k = j + 1 , l = n - 1;
            while(k < l) {
                ll sum = nums[i]; sum += nums[j]; sum += nums[k]; sum += nums[l];
                if (sum == target) {
                    ans.push_back({nums[i] , nums[j] ,  nums[k] , nums[l]});
                    k ++; l --;
                    while(k < l && nums[k] == nums[k - 1]) k ++;
                    while(k < l && nums[l] == nums[l + 1]) l --;
                }
                else if (sum > target) l --;
                else if (sum < target) k ++;
            }
        }
    } 
    return ans;
} 
void solve() {
    int n , x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> ans = fourSum(v , x);
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