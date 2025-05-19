// 3024. Type of Triangle
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];

        if(a == b && b == c)
            return "equilateral";
        
        if(a+b <= c || a+c<=b || b+c<=a)
            return "none";
        
        if(a==b || a==c || b==c)
            return "isosceles";
        
        return "scalene";

    }
};