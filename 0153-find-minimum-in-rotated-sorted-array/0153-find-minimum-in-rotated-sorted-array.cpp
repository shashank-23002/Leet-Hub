class Solution {
public:
    int findMin(vector<int>& nums) {
        set<int> st;
        for(auto x: nums)
        {
            st.insert(x);
        }

        int ans=0;
        for(auto i:st)
        {
            ans=i;
            break;
        }

        return ans;
    }
};