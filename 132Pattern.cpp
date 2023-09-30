class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int> st;
        int thirdNumber = INT_MIN;
        for(int i = nums.size()-1; i>=0; i--){
            if(nums[i] < thirdNumber) return true;
            while(!st.empty() && st.top() < nums[i]){
                thirdNumber = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
