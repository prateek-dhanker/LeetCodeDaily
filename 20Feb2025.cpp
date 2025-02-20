// 1980. Find Unique Binary String

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        long long toDigi(string& bin){
            long long pow2 = 1 , res = 0;
    
            for(int i=bin.size()-1;i>=0;i--){
                if(bin[i]=='1')
                    res += pow2;
                
                pow2 *= 2;
            }
            return res;
        }
        string toString(long long num,int n){
            string res = "";
    
            while(num){
                res += num&1 ? "1" : "0";
                num = num>>1;
            }
    
            while(res.size()<n)
                res.push_back('0');
            
            reverse(res.begin(),res.end());
    
            return res;
        }
        string findDifferentBinaryString(vector<string>& nums) {
            long long n = nums.size();
    
            unordered_map<long long,bool> numsMap;
    
            for(auto str:nums){
                long long num = toDigi(str);
                cout<<num<<endl;
                numsMap[num] = true;
            }
    
            for(long long i=0;i<=n;i++){
                if(numsMap[i]==false)
                    return toString(i,n);
            }
            return "";
        }
    };