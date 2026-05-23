#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// just normal classic binary_search with some addons
bool check_lower_bound(vector<int> v ,  int x , int mid) {
    if (v[mid] >= x) return true;
    return false;
}

bool check_upper_bound(vector<int> v ,  int x , int mid) {
    if (v[mid] > x) return true;
    return false;
}

int lower_bound(vector<int> v , int x) {
    // we would be taking the lo as 0. , hi as v.size() - 1 and also the ans as v.size()
    int lo = 0; int hi = v.size() - 1; int ans = v.size();

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check_lower_bound(v , x , mid)) {
            ans = mid; 
            hi = mid - 1;
        }
        else  {
            lo = mid + 1;
        }
    }

    return ans;
}
int upper_bound(vector<int> v , int x) {
    // we would be taking the lo as 0. , hi as v.size() - 1 and also the ans as v.size()
    int lo = 0; int hi = v.size() - 1; int ans = v.size();

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check_upper_bound(v , x , mid)) {
            ans = mid; 
            hi = mid - 1;
        }
        else  {
            lo = mid + 1;
        }
    }

    return ans;
}


void solve() {
    vector<int> v;
    int n; cin >> n; int y; cin >> y;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    int ans1 = lower_bound(v , y);
    cout << ans1 << endl;
    int ans2 = upper_bound(v , y);
    cout << ans2 << endl;
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
