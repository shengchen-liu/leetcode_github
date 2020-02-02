class Solution {
public:
 vector<int> prisonAfterNDays(vector<int>& cells, int N) {      
      // map day to cell state (day 0 is initial state)
      int day2state[(2<<8)+1]; // 2<<8: number of all states
      
      // map cell state to day
      unordered_map<int, int> state2day;
      
      // initial state
      int state = 0;
      for (int cell : cells)
        (state<<=1) += cell;
            
      int day = 0;
      while (day < N && state2day.count(state) == 0) {
        state2day[state] = day;
        day2state[day] = state;
        
        nextState(state);
        day++;
      }
      
      // found a repeat state
      if (state2day.count(state) > 0) {
        int prev_day = state2day[state];
        state = day2state[(N-prev_day)%(day-prev_day) + prev_day];
      }
            
      // convert state to cells
      for (int i = 0; i < 8; i++) {
        cells[7-i] = state & 1;
        state >>= 1;
      }
      
      return cells;
    }
  
    // get next state by the rules 
    void nextState(int& state) {
      int next = 0;
      for (int bit_pos = 1; bit_pos < 7; bit_pos++) {
        if (((state>>(bit_pos+1)) & 1) == ((state>>(bit_pos-1)) & 1))
          next |= (1<<bit_pos);
      }
      state = next;
    }
};