//Approach 1 using DP to prevent recursion overlapping.
  T.C. = O(N);
  S.C. = O(N) + O(N);

#include <bits/stdc++.h> 
int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
    return solve(n-1, heights, dp);
}

//using tabulation of previous one with optimal S.C.= 0(N) without using DP

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
     int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(heights[i]-heights[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(heights[i]-heights[i-2]);
    
      int cur_i = min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
  return prev;
}
