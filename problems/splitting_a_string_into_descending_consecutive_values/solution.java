class Solution {
    public boolean splitString(String s) {
        return dfs(s, null);
    }
    private boolean dfs(String s, Long previous) {
        long current =0;
        for(int i=0;i<s.length();i++) {
            current = current * 10 + s.charAt(i)-'0';
            if(previous == null) {
                if (dfs(s.substring(i+1), current)) 
                    return true;
            } else if(current == previous - 1 && (i==s.length()-1 || dfs(s.substring(i+1), current)))
                return true;
        }
        return false;
    }
}
