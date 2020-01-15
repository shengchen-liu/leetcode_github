class Solution {
public:
     void subsetsWithDup( vector< int > &nums, int index, vector< int > &result, vector< vector< int > > &results ) {
        results.push_back( result );
        for( int i = index ; i < nums.size() ; ++i ) {
            result.push_back( nums[ i ] );
            subsetsWithDup( nums, i + 1, result, results );
            result.pop_back();
            
            /*
                To remove consecutive duplicate elements
            */
            int k = i + 1;
            while( k < nums.size() && nums[ i ] == nums[ k ] ) {
                ++i; ++k;
            }
            if( k == nums.size() ) break;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        vector< vector< int > > results;
        vector< int > result;
        subsetsWithDup( nums, 0, result, results );
        return results;
    }
};