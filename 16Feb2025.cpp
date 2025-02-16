// 1718. Construct the Lexicographically Largest Valid Sequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool fillSeq(int n, vector<int>& sequence , vector<bool>& cnt,int index){
            if(index == sequence.size())
                return true;
            
            if(sequence[index]!=0)
                return fillSeq(n,sequence,cnt,index+1);
            
            for(int i=n-1;i>0;i--){
                if(i!=1 && index+i>=2*n-1)
                    continue;
    
                if(cnt[i]) 
                    continue;
                
                if(i!=1 && sequence[index+i])
                    continue;
    
                sequence[index] = i;
                if(i!=1)
                    sequence[index+i] = i;
                cnt[i] = true;
                bool correct = fillSeq(n,sequence,cnt,index+1);
    
                if(correct)
                    return true;
                
                sequence[index] = 0;
                if(i!=1)
                    sequence[index+i] = 0;
                cnt[i] = false;
            }
    
            return false;
    
        }
        vector<int> constructDistancedSequence(int n) {
            if(n==1)
                return {1};
            vector<int> sequence(2*n-1,0);
            vector<bool> cnt(n,false);
    
            sequence[0] = n;
            sequence[n] = n;
    
            fillSeq(n,sequence,cnt,0);
    
            return sequence;
        }
    };