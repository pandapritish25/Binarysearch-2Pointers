// https://leetcode.com/problems/subarrays-with-k-different-integers/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

int subarraysWithDistinct(vector<int>& nums, int k) {
    int freq[30000] , n = nums.size();
    ll head = -1 , tail = 0 , ans = 0 , distinct = 0;
    memset(freq , 0 , sizeof(freq));

    while(tail < n) {
        while(head + 1 < n && (distinct < k || freq[nums[head + 1]] > 0)) {
            head ++; 
            if (freq[nums[head]] == 0) distinct ++;
            freq[nums[head]] ++;
        }
        ans = ans + (head - tail + 1);
        if (tail <= head) {
            freq[nums[tail]] --;
            if (freq[nums[tail]] == 0) distinct --;
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
            memset(freq , 0 , sizeof(freq));
        }
    }

    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int ans1 = subarraysWithDistinct(nums, k);
    int ans2 = subarraysWithDistinct(nums, k - 1);
    int diff = ans1 - ans2;
    return diff;
}
void solve() {
    int n , k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int ans = subarraysWithKDistinct(v , k) - subarraysWithKDistinct(v , k - 1);
    cout << ans << endl;
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