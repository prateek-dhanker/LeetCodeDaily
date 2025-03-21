// 2115. Find All Possible Recipes from Given Supplies
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool cook(int i,vector<string>& recipes, vector<vector<string>>& ingredients,unordered_set<string>& available ,unordered_map<string,int>& isRecipe, unordered_set<string>&visited){
            string recipe = recipes[i];
    
            if(visited.find(recipe)!=visited.end())
                return available.find(recipe)!=available.end() ? true : false;
            
            visited.insert(recipe);
    
            bool possible = true;
            for(string ingredient:ingredients[i]){
                if(isRecipe.find(ingredient)!=isRecipe.end()){
                    if(cook(isRecipe[ingredient],recipes,ingredients,available,isRecipe,visited)==false){
                        possible = false;
                        return false;
                    }
                }
                else if(available.find(ingredient)==available.end()){
                    possible = false;
                    break;
                }
            }
            if(possible)
                available.insert(recipe);
    
            return possible;
        }
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_set<string> available, visited;
            unordered_map<string,int> isRecipe;
    
            for(auto supply : supplies)
                available.insert(supply);
            
            for(int i=0;i<recipes.size();i++)
                isRecipe[recipes[i]] = i;
    
            
            vector<string> res;
    
            for(int i=0;i<recipes.size();i++){
                if(cook(i,recipes,ingredients,available , isRecipe, visited))
                    res.push_back(recipes[i]);
            }
    
            return res;
        }
    };