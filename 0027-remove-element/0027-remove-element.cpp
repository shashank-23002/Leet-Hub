class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> v;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                cnt++;
               v.push_back(nums[i]); 
            }
        }
        
        for(int i=v.size();i<nums.size();i++)
        {
            v.push_back(101);
        }
        nums=v;
        return cnt;
    }
};