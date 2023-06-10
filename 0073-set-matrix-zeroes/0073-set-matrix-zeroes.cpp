class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> st;
        vector<int> v;
        int n=matrix.size();
        int z=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<z;j++)
            {
                if(matrix[i][j]==0)
                {
                    v.push_back(j);
                    st.insert(i); 
                }
            }
        }
        
        sort(v.begin(),v.end());
        
        for(auto i:st)
        {
            for(int j=0;j<z;j++)
            {
                matrix[i][j]=0;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<v.size();j++)
            {
                int k=v[j];
                matrix[i][k]=0;
            }
        }
    }
};