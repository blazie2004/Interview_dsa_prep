class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int>mp;
        int n=fruits.size();

        int i=0;
        int j=0;
        int k=2;
        int maxi=0;

        while(j<n){
            mp[fruits[j]]++;
            int len=j-i+1;

           if(mp.size()<=2){
              maxi=max(maxi,len);
           }

            
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
                len--;
                

            }
            j++;
        }
        return maxi;

    }

    // 0-1 len=1 //0 i=1
    // 1-1 len=2
    // 2-1 len=3;

};