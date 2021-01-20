/*
number of different transformationations among all words
gin:--...-.
zen:--...-.
gig:--...--.
msg:--...--.

*/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        int res = 0;
        for (string word : words) {
            // convert to mos
            string tmp = convert(word);
            s.insert(tmp);
        }
        return s.size();
    }
    
    string convert(const string& word) {
        string tmp;
        vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (char a : word) {
            string code = table[a -'a'];
            tmp += code;
        }
        return tmp;
    }
};