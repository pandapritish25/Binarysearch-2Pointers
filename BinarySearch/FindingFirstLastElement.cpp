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
    int lo = 0; int hi = v.size() - 1; int ans = -1;

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
    int lo = 0; int hi = v.size() - 1; int ans = -1;

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

vector<int> find_first_and_lastPos(vector<int> v , int x) {
    if (v.size() == 0) return {-1 , -1};
    int ans1 = lower_bound(v , x);

    if (ans1 == -1) return {-1 , -1};

    if (ans1 == 0 && v[0] != x) return {-1 , -1};

    if (v[ans1] != x) return {-1 , -1};

    int ans2 = upper_bound(v , x); 
    if (ans2 == 0) return {-1 , -1};
    ans2 --;
    if (v[ans2] != x) return {-1 , -1};
    
    vector<int> ans = {ans1 , ans2};
    return ans;
}


void solve() {
    vector<int> v;
    int n; cin >> n; int y; cin >> y;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    vector<int> ans = find_first_and_lastPos(v , y);
    for (auto x : ans) cout << x << " ";
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
