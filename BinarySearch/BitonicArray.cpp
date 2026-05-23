#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// this is one of the best concepts regarding globalisation and also keeping the array constant means that if you are basically having an array
// then what needs to be done is and that array is not changing , you would be needing to pass const and vector<int> &v so that it will be directly passing by reference this is much faster
// than the current functions as always

// thus in case your array is not constantly getting modified its always and always recommeded to use const  vector<int> & v; because thats the beauti for time limits
// thus only use vector<int> &v and this would be the best solution
int rotated_pivot_index(const vector<int> &v) {
    int lo = 0 , hi = v.size() - 1; int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] > v[mid + 1]) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return ans;
}

int search(const vector<int> &v , int x) {
    int lo = 0 , hi = v.size() - 1; int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x) {
            ans = mid; hi = mid - 1;
        }
        else if (v[mid] > x) {
            hi = mid - 1;
        }
        else if (v[mid] < x) {
            lo = mid + 1;
        }
    }
    return ans;
}

void solve() {  
    int n , x; cin >> n >> x; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int index = rotated_pivot_index(v);

    vector<int> ans1_pivot , ans2_pivot;
    for (int i = 0; i <= index; i++) ans1_pivot.push_back(v[i]);
    for (int i = index + 1; i < n; i++) ans2_pivot.push_back(v[i]);

    reverse(ans2_pivot.begin() , ans2_pivot.end());
    
    while (x --) {
        int y; cin >> y;
        int ans1 = search(ans1_pivot , y);
        int ans2 = search(ans2_pivot , y);

        if (ans1 != -1 && ans1_pivot.size() > 0) {
            cout << ans1 + 1 << " ";
        }
        if (ans2 != -1 && ans2_pivot.size() > 0) {
            int index_form = ans1_pivot.size() + (ans2_pivot.size() - ans2);
            cout << index_form << " ";
        }
        cout << endl;
    }
    
}    


signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    cin >> t;
    while (t --) {
        solve();
    }
}
