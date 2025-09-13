class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> vowel(5,0);
        unordered_map<int,int>consonants;
        for(auto it : s){
            if(it == 'a') vowel[0]++;
            else if(it == 'e') vowel[1]++;
            else if(it == 'i') vowel[2]++;
            else if(it == 'o') vowel[3]++;
            else if(it == 'u') vowel[4]++;
            else consonants[it]++;
        }
        int vowelMax = 0;
        for(int i = 0; i<5; i++){
            vowelMax = max(vowelMax,vowel[i]);
        }

        int consonantMax = 0;
        for(auto it : consonants){
            consonantMax = max(consonantMax,it.second);
        }

        return vowelMax+consonantMax;
    }
};