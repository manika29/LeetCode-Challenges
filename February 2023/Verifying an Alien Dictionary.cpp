class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        //store char and their index in the map
        int index=0;
        unordered_map<char,int>mp;
        for(auto &c : order)
            mp[c]=index++;

        //traverse the words array to check the lexicographical order
        for(int i=1; i<words.size(); i++){
            bool flag=false;
            string first=words[i-1];
            string second=words[i];

            int minLen=min(first.size(),second.size());
            for(int j=0; j<minLen; j++){
                if(mp[first[j]]<mp[second[j]]){
                    flag=true;
                    break;
                }

                if(mp[first[j]]>mp[second[j]])
                return false;
            }

            if(!flag && first.size()>second.size())
            return false;
        }

        return true;
    }
};