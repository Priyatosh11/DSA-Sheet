#include<vector>
int lcs(string &s1, string &s2){
    // Write your code here.
     int n = s1.size();
    int m = s2.size();
    
    // Create a 2D DP table with dimensions (n+1) x (m+1)
    vector<int> prev(m+1, 0), curr(m+1, 0);

    int ans = 0; // Initialize the answer variable

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                int val = 1 + prev[j-1]; // Characters match, increment substring length
                curr[j] = val; // Update the DP table
                ans = max(ans, val); // Update the maximum substring length found so far
            }
            else
                curr[j] = 0; // Characters don't match, substring length becomes 0
        }
        prev = curr;
    }
    
    return ans;

}
