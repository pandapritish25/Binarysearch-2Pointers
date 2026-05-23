//https://leetcode.com/problems/count-number-of-nice-subarrays/description/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll func(vector<int> &nums , int k) {
    int n = nums.size();
    ll head = -1 , tail = 0 , sum = 0;
    ll count = 0;
    while(tail < n) {
        while(head + 1 < n && (count < k || nums[head + 1] % 2 == 0)) {
            head ++;
            if (nums[head] % 2 == 1) count ++;
        }
        sum = sum + (head - tail + 1);
        if (tail <= head) {
            if (nums[tail] % 2 == 1) count --;
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
            count = 0;
        }
    }
    return sum;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    ll ans1 = func(nums , k); ll ans2 = func(nums , k - 1);
    ll diff = ans1 - ans2; return diff;
}
void solve() {
    int n , x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << numberOfSubarrays(v , x);
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