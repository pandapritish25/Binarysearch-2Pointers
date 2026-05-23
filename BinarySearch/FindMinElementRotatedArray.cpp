#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// basically this check function would be basically telling or helping us in constructing the 0 1 array 
// if I would be having every element as mid and then I can check that the last element would be then I would be getting the 0 1 array
// then I would be having the solution
int check(vector<int> v , int mid) {
    int last = v.back();
    return v[mid] <= last;
}

// this is the normal binaryt search
int binary_search(vector<int> v) {
    int lo = 0 , hi = v.size() - 1; int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(v , mid) == 1) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    return ans;
}
int findMin(vector<int>& nums) {
    int ans1 =  binary_search(nums);
    int ans = nums[ans1]; 
    return ans;
}


void solve() {
    int n; cin >> n; vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    cout << findMin(v) << endl;
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
