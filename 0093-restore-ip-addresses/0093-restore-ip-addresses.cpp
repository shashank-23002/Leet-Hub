class Solution {
public:
    
    bool check(string &s)
    {
        int l=s.size();
        if(l<=0 || l>3)
        {
            return false;
        }
        
        if(s[0]=='0' && l>1)
        {
            return false;
        }
        
        int k=stoi(s);
        if(k<0 || k>255)
        {
            return false;
        }
        
        return true;
        
    }
    
    string generate(string &s,int n,int i,int j,int k)
    {
        string s1=s.substr(0,i+1);
        string s2=s.substr(i+1,j-i);
        string s3=s.substr(j+1,k-j);
        string s4=s.substr(k+1,n-1-k);
        
        if(check(s1) && check(s2) && check(s3) && check(s4))
        {
            return s1+"."+s2+"."+s3+"."+s4;
        }
        
        return "";
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    string p=generate(s,n,i,j,k);
                    if(p.size()>0)
                    {
                        v.push_back(p);
                    }
                    
                }
            }
        }
        
        return v;
    }
    
};