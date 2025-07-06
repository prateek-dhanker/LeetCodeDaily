// 1865. Finding Pairs With a Certain Sum
#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    unordered_map<int,int> freq;
    vector<int> nums1,nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int num:nums2)
            freq[num]++;
    }
    
    void add(int index, int val) {
        int num = nums2[index];
        nums2[index] += val;

        freq[num]--;
        freq[num+val]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int num:nums1){
            int required = tot - num;

            if(freq.find(required) != freq.end())
                cnt += freq[required];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */