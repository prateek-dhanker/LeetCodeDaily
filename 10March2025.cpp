// 3306. Count of Substrings Containing Every Vowel and K Consonants II

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isVowel(char ch){
            return (ch == 'u' || ch == 'o' || ch == 'i' || ch == 'e' || ch == 'a');
        }
        long long countOfSubstrings(string word, int k) {
            int n = word.length();
            long long res = 0;
            unordered_map<char,int> vowels;
            int cons = 0;
    
            vector<int> nextCons(n);
            int lastCons = n;
            for(int i=n-1;i>=0;i--){
                nextCons[i] = lastCons;
    
                if(!isVowel(word[i]))
                    lastCons = i;
            }
    
            int l = 0 , r = 0;
            while(r<n){
                if(isVowel(word[r]))
                    vowels[word[r]]++;
                
                else
                    cons++;
                
                while(l<=r && cons>k){
                    if(isVowel(word[l])){
                        if(--vowels[word[l]] == 0)
                            vowels.erase(word[l]);
                    }
                    else
                        cons--;
                    
                    l++;
                }
    
                while(l<r && cons == k && vowels.size() == 5){
                    res += (nextCons[r] - r);
                    if(isVowel(word[l])){
                        if(--vowels[word[l]] == 0)
                            vowels.erase(word[l]);
                    }
                    else
                        cons--;
                    
                    l++;
                }
    
                r++;
            }
            return res;
        }
    };