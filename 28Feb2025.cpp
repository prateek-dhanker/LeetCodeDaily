class Solution {
    public:
        string scs(string str1,string str2,unordered_map<string,string>& dp){
            if(str1.size()==0 && str2.size()==0)
                return "";
            
            if(str1.size()==0)
                return str2;
            
            if(str2.size()==0)
                return str1;
            
            string check = str1 + " " + str2;
            if(dp.find(check)!=dp.end())
                return dp[check];
            
            if(str1[0] == str2[0])
                return dp[check] =  str1[0] + scs(str1.substr(1,str1.size()-1),str2.substr(1,str2.size()-1),dp);
            
            string res1 = str1[0] + scs(str1.substr(1,str1.size()-1),str2,dp);
            string res2 = str2[0] + scs(str1,str2.substr(1,str2.size()-1),dp);
    
            return dp[check] = res1.size()>res2.size() ? res2 : res1;
        }
        string shortestCommonSupersequence(string str1, string str2) {
            unordered_map<string,string> dp;
            return scs(str1,str2,dp);
        }
    };