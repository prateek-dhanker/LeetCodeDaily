// 2818. Apply Operations to Maximize Score
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        const int MOD = 1e9+7;
        vector<int> primeScore(int  n,vector<int>& nums){
            vector<int> score(n);
    
            for(int i=0;i<n;i++){
                int num = nums[i];
    
                for(int fac=2;fac<=sqrt(num);fac++){
                    if(num%fac==0){
                        score[i]++;
    
                        while(num%fac==0)
                            num /= fac;
                    }
                }
    
                if(num>=2)
                    score[i]++;
            }
    
            return score;
        }
        vector<int> nextGreater(int n,vector<int>& nums){
            vector<int> next(n);
    
            stack<int> st;
            st.push(n);
    
            for(int i=n-1;i>=0;i--){
                while(st.top()!=n && nums[st.top()]<=nums[i])
                    st.pop();
                
                next[i] = st.top();
                st.push(i);
            }
            return next;
        }
        vector<int> prevGreater(int n,vector<int>& nums){
            vector<int> prev(n);
    
            stack<int> st;
            st.push(-1);
    
            for(int i=0;i<n;i++){
                while(st.top()!=-1 && nums[st.top()]<nums[i])
                    st.pop();
                
                prev[i] = st.top();
                st.push(i);
            }
            return prev;
        }
        long long toPower(long long n,long long expo){
            long long res = 1;
    
            while(expo>0){
                if(expo&1)
                    res = (res*n)%MOD;
                
                n = (n*n)%MOD;
                expo = expo>>1;
            }
    
            return res;
        }
        int maximumScore(vector<int>& nums, int k) {
            int  n = nums.size();
            vector<int> score = primeScore(n,nums);
    
            vector<int> next = nextGreater(n,score);
            vector<int> prev = prevGreater(n,score);
    
            priority_queue<pair<int,int>> pq;
    
            for(int i=0;i<n;i++)
                pq.push({nums[i],i});
            
            long long res = 1;
            
            while(pq.size() && k>0){
                auto top = pq.top();
                pq.pop();
    
                int num = top.first, i = top.second;
                cout<<num<<" "<<i<<" ";
    
                long long range = 1LL*(next[i]-i)*(i-prev[i]);
                cout<<range<<endl;
    
                long long expo = min(range,k*1LL);
                
                res = (res*toPower(num,expo))%MOD;
    
                k-=expo;
            }
    
            return res;
        }
    };