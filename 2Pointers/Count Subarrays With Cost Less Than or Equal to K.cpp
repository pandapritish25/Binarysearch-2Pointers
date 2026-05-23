//https://leetcode.com/problems/count-subarrays-with-cost-less-than-or-equal-to-k/submissions/2010959278/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;
long long countSubarrays(vector<int>& nums, long long k) {
    multiset <ll> ms; ll head = -1 , tail = 0 , ans = 0 , n = nums.size();

    while(tail < n) {
        while (head + 1 < n) {
            ms.insert(nums[head + 1]);
            ll max1 = *ms.rbegin() , min1 = *ms.begin() , diff = max1 - min1 , size = head - tail + 2;
            ll curr_prod = size * diff;
            if (curr_prod <= k) head ++;
            else {
                auto it = ms.find(nums[head + 1]);
                if (it != ms.end()) ms.erase(it);
                break;
            }
        }
        ans = ans + (head - tail + 1);
        if (tail <= head) {
            auto it = ms.find(nums[tail]);
            if (it != ms.end()) ms.erase(it);
            tail ++;
        }
        else {
            tail ++ , head = tail - 1;
        }
    }
    return ans;
}

void solve() {
    int n , k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << countSubarrays(v , k) << endl;
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