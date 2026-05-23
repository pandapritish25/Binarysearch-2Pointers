//https://leetcode.com/problems/count-number-of-nice-subarrays/description/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll max(ll a , ll b) {
    if (a >= b) return a;
    return b;
}

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    ll prefix_sum[n + 1]; ll suffix_sum[n + 1]; ll sum = 0;
    prefix_sum[0] = 0 , suffix_sum[0] = 0;
    for (int i = 0; i < n; i++) sum += cardPoints[i] , prefix_sum[i + 1] = sum;

    sum = 0;
    reverse(cardPoints.begin() , cardPoints.end());
    for (int i = 0; i < n; i++) sum += cardPoints[i], suffix_sum[i + 1] = sum;
    reverse(cardPoints.begin() , cardPoints.end()); reverse(suffix_sum , suffix_sum + (n + 1));

    int left = 0 , right = k , max1 = 0;

    for (int i = 0; i < k + 1; i++) {
        ll left_sum = prefix_sum[left]; ll right_sum = suffix_sum[n - right];
        ll tot_sum = left_sum + right_sum;
        max1 = max(max1 , tot_sum);
        left ++; right --;
    }
    return max1;
}
void solve() {
    int n , x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << maxScore(v , x) << endl;
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