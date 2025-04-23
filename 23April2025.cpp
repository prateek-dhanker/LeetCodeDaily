// 1399. Count Largest Group
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int cntDigi(int n){
            int sum = 0;
            while(n>0){
                sum += n%10;
                n /= 10;
            }
            return sum;
        }
        int countLargestGroup(int n) {
            unordered_map<int,int> hashMap;
    
            int maxi = 0, cnt = 0;
            for(int i=1;i<=n;i++){
                int sum = cntDigi(i);
                hashMap[sum]++;
    
                if(hashMap[sum]>maxi){
                    maxi = hashMap[sum];
                    cnt = 1;
                }
                else if(hashMap[sum]==maxi)
                    cnt++;
            }
    
            return cnt;
        }
    };