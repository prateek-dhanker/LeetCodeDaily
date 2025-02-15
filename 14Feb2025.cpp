// 1352. Product of the Last K Numbers

#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    public:
        int n;
        vector<int> prefix;
    
        ProductOfNumbers() {
            n = 0;
            prefix = {1};
        }
        
        void add(int num) {
            if(num){
                prefix.push_back(num*prefix[n]);
                n++;
            }
    
            else{
                n = 0;
                prefix = {1};
            }
    
        }
        
        int getProduct(int k) {
            if(k>n)
                return 0;
            
            return prefix[n]/prefix[n-k];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */