class Solution {
public:
    string reverseWords(string s) {
        string result="";
         int i=s.size()-1;
        while(i>=0) { // if spaces,move pointer
            while(i>=0 && s[i]==' ') {
                i--;
            }
            if(i<0) {
                break;
            }
            int end=i;
            while(i>=0 && s[i]!=' ') { // if not spaces, still move pointer
                i--;
            }
            if(!result.empty()) { // ifresult is  not empty, add one space
                result+=" ";
            }

            string word=s.substr(i+1,end-i); // take out substring from i+1 to last index of that word
            result+=word;

            
            
        }
        return result;
        
        
    }
};