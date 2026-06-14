#include<bits/stdc++.h>
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int ans=0;
        int n=s.length();

        int i=0; int j=0;
        while(j<n){
            mp[s[j]]++;
            int len=j-i+1;

            int maxi=0;
            for(auto it:mp){
                maxi=max(maxi,it.second);
            }
            if(len-maxi<=k){
                //possible
                ans=max(ans,len);
            }
            else if (len-maxi>k){
                //u cant convert now;
                while(len-maxi>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                    len--;
                }
            }

            j++;
        }
        return ans;
    }
};