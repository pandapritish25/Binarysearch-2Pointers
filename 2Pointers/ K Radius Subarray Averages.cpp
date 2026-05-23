//https://leetcode.com/problems/k-radius-subarray-averages/description/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;
vector<int> getAverages(vector<int>& nums, int k) {    
    int n = nums.size(); ll prefix_sum[n + 1];
    if (k == 0) return nums;
    if (2 * k + 1 > n) {
        vector<int> ans; for (int i = 0; i < n; i++) ans.push_back(-1);
        return ans;
    }

    ll sum = 0;
    prefix_sum[0] = 0; for (int i = 0; i < n; i++) sum += nums[i] , prefix_sum[i + 1] = sum;
    vector<int> store_ans;

    for (int i = 0; i < k; i++) store_ans.push_back(-1);

    for (int i = k; i < n - k; i++) {
        ll right = i + k; ll left = i - k;
        ll ans = prefix_sum[right+1] - prefix_sum[left], size = 2 * k + 1;
        ll ans1 = ans / size; store_ans.push_back(ans1);
    }

    for (int i = n - k; i < n; i++) store_ans.push_back(-1);
    return store_ans;
}

void solve() {
    int n , k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans = getAverages(v , k); for (auto x : ans) cout << x << " ";
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