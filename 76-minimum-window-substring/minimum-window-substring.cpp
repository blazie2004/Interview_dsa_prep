class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto it:t){
            mp[it]++;
        }
        int count=mp.size();
        int n=s.length();
        int i=0;
        int j=0;

        int idx=-1;
        int idx2=-1;
        int mini=INT_MAX;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                //we encountered the element present in t;
                mp[s[j]]--;

                if(mp[s[j]]==0)count--;
                //one element of a particular type got cancelled;
            }

            //now when we will figure out the whole string t is encountered??
            //once the count is 0;

            while(count==0){
                //here at this jth position says this is position index of s where u can find whole string t;
                int window_size=j-i+1;

                if(window_size<mini){
                    idx=i;
                    idx2=j;
                    mini=window_size;
                }

                //store the string size 
                //but its possible that we can find another same string t further in s
                // we are hitting the case of string s found when count==0;
                // for that increase the count in mp;
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count++;
                    }
                }
                i++;

            }
            j++;

        }
        
        cout<<"min len substring"<<mini<<""<<endl;

        if(mini==INT_MAX)return "";

        return s.substr(idx,idx2-idx+1);
    }
};