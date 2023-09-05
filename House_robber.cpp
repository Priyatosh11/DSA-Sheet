//Approach 1 using DP 
// T.C. = O(N);
// S.C. = O(N) + O(N);
class Solution {
private:
int solveUtil(int ind, vector<int>& nums, vector<int>& dp){
    
    if(ind==0) return nums[ind];
    if(ind<0)  return 0;

    if(dp[ind]!=-1) return dp[ind];
    
    int pick= nums[ind]+ solveUtil(ind-2, nums,dp);
    int nonPick = 0 + solveUtil(ind-1, nums, dp);
    
    return dp[ind]=max(pick, nonPick);
}    
public:
    int rob(vector<int>& nums) {
       int n= nums.size();
        vector<int> dp(n,-1);
    return solveUtil(n-1, nums, dp); 
};

//Approach 2 without using DP
// T.C. = O(N);
// S.C. = O(N);

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
    int prev = nums[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = nums[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev; 
    }
};
