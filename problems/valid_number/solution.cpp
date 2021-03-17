class Solution {
private:
    bool isSpace(char c){ return c==' ';}
    bool isSgn(char c){ return c=='+'||c=='-';}
    bool isDot(char c){ return c=='.';}
    bool isNum(char c){ return c<='9'&&c>='0';}
    bool isE(char c){ return c=='e'||c=='E';}
    
public:
    bool isNumber(string s) {
        int pos=0;
        bool haveNum = false;

        // Check all the prefix spaces
        while ( pos<s.size() && isSpace(s[pos]) ) pos++;

        // Check the next char if it's a +/- signal
        if ( pos<s.size() && isSgn(s[pos]) ) pos++;

        // Check the numbers before a dot '.'
        while ( pos<s.size() && isNum(s[pos]) ) {haveNum = true; pos++;}

        // Check the dot '.'
        if ( pos<s.size() && isDot(s[pos]) ) pos++;

        // Check the numbers after a dot '.'
        while ( pos<s.size() && isNum(s[pos]) ) {haveNum = true; pos++;}

        // Check the 'e' / 'E'
        if ( haveNum && pos<s.size() && isE(s[pos]) ) {
            haveNum = false; pos++;
            if ( pos<s.size() && isSgn(s[pos]) ) pos++;
        }

        // Check the numbers after 'e' / 'E'
        while ( pos<s.size() && isNum(s[pos]) ) {haveNum = true; pos++;}

        // Check all the remaining spaces
        while ( pos<s.size() && isSpace(s[pos]) ) pos++;

        // Everything is done, if the string not empty, return false.
        return ( pos==s.size() && haveNum );
    }
};