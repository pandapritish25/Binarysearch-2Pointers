//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

vector<int> twoSum(vector<int>& numbers, int target) {
    ll left = 0 , right = numbers.size() - 1;

    while(left < right) {
        ll ans = numbers[left] + numbers[right]; 
        if (ans == target) {
            vector<int> x = {left + 1 , right + 1}; return x;
        }
        else if (ans > target) right --;
        else if (ans < target) left ++;
    }
    return {0};
}
void solve() {
    int n , x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans = twoSum(v , x); for (auto x : ans) cout << x << " ";
    cout << endl;
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