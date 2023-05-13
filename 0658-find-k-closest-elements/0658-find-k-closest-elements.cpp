class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> mp;
        multiset<int> st;
        for(auto i:arr)
        {
            mp.push_back({abs(i-x),i});
        }
        sort(mp.begin(),mp.end());
        int cnt=0;
        vector<int> ans;
        for(auto j:mp)
        {
            cnt++;
            st.insert(j.second);
            // ans.push_back(j.second);
            if(cnt==k)
            {
                break;
            }
        }
        
        for(auto it:st)
        {
            ans.push_back(it);
        }
        
        return ans;
    }
};