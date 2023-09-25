#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int target)
{
    // Write your code here.
    int n= num.size();
    vector<int> prev(target+1, 0), curr(target+1, 0);

    for(int T = 0; T <= target; T++ ){
        if(T % num[0] == 0){
            prev[T] = T/num[0];
        }else{
            prev[T] = INT_MAX;
        }
    }

    for(int ind= 1; ind < n; ind++){
        for(int T = 0; T <= target; T++){
            int notTake = 0 + prev[T];
            int take = 1e9;
            if(num[ind] <= T){
                take = 1 + curr[T - num[ind]];
            }
            curr[T] = min(take, notTake);
        }
        prev = curr;
    }
    int ans = prev[target];
    if(ans >= 1e9) return -1;
    return ans;
}
