class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[i]=nums[i];
            if(nums[i]==target)
            {
                return i;
            }
        }
    
        for(auto i:mp)
        {
            if(i.second>target)
            {
                return i.first;
                
            }
        }
        
        return nums.size();
    }
};