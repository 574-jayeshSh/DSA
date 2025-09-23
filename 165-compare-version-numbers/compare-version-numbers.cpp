
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size() , m = version2.size();

        while(i < n || j < m){
            string s1 = "", s2 = "";
            for( ; i<n ; i++){
                if(version1[i] != '.'){
                    s1 += version1[i];
                }
                else{ 
                    i++;
                    break;
                }
            }
            for(; j<m ; j++){
                if(version2[j] != '.'){
                    s2 += version2[j];
                }
                else{ 
                    j++;
                    break;
                }
            }

            int n1 = s1.empty() ? 0 : stoi(s1);
            int n2 = s2.empty() ? 0 : stoi(s2);

            if (n1 < n2) return -1;
            else if (n1 > n2) return 1;
        }

        return 0;
    }
};