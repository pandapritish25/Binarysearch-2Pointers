#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// one of the good problems , in this problem , you would be needing to check for each of the machines for this reason you would be needing 
// to have all the values inside the array and you would be needing to check if x / n is greater than that element or not
bool check(const vector<int> &v , int mid , int x) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) sum += (mid / v[i]);
    return sum >= x;
}

void solve() {  
    int n , k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

    int lo = 0; int mini = *min_element(v.begin() , v.end()); int ans = mini * k;
    int hi = ans;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(v , mid , k)) {
            ans = mid; hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << ans << endl;
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
