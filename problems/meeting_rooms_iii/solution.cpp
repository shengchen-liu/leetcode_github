/*
n rooms
Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free.
When a room becomes unused, meetings that have an earlier original start time
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

e.g: n = 2
[0,10],[1,5],[2,7],[3,4]             
0 1 2 3 4 5 6 7 8 9 10 11 12            meeting      room 
0 0 0 0 0 0 0 0 0 0 0              [0,10]            0
  1 1 1 1 1                        [1,5]             1
          1 1 1 1 1 1              [2,7]->[5,10]     1 
                    0  0           [3,5]->[10,11]    0
1. sort by start 
pq min heap store end time
count: vector(n)
2. for each meeting:    
    if start <= pq.top:
        use the same room
        pq.pop
        pq.push(meeting.end)
        count[room]++
    else: 
        if pq.size < n:
            use a new room: roomIdx = pq.size()
            pq.push({meeting.end, roomIdx})
            count[roomidx]++
        else:
            # delay
            pq.pop => end, room_id
            newMeeting = [end, duration + end]
            count[room_id]++
            pq.push(newMeeintg.end, room_id)

3. return max(count)

*/
bool compare(vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
}
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        /* Sort the meetings based on start_time */
        sort(meetings.begin(), meetings.end(), compare);
        
        /* Create a priority queue for engaged rooms. Each node of PQ will store {current_meeting_ending_time, room_number} */
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged;
        
        /* Create a priority queue for non-engaged rooms. Each node of PQ will store {room_number} */
        priority_queue<int, vector<int>, greater<int>> unused;
        
        /* Frequency map to store the frequency of meetings in each room */
        unordered_map<int, int> freq;
        
        /* Currently all the rooms are mepty */
        for(int i = 0; i < n; i++) {
            unused.push(i);
        }
        
        for(auto x:meetings) {
            int s = x[0], e = x[1];
            
            /* Move the meeting rooms in engaged, with ending_time <= s, to unused */ 
            while(engaged.size() > 0 && engaged.top().first <= s) {
                int room = engaged.top().second;
                engaged.pop();
                
                unused.push(room);
            }
            
            /* If there are multiple empty rooms, choose the one with lower room_number */
            if(unused.size() > 0) 
            {
                int room = unused.top();
                unused.pop();
                
                freq[abs(room)] += 1;
                
                /* Mark the room as engaged */
                engaged.push({e, room});
            }
            /* If there are no empty rooms, wait for the engaged room with nearest ending time to empty */
            else 
            {
                pair<long long, int> topmost = engaged.top();
                engaged.pop();
            
                freq[abs(topmost.second)] += 1;
                
                /* Since duration has to be the same, the newEnd will be sum(end_time_of_the_prev_meeting, duration) */ 
                long long newEnd = topmost.first;
                newEnd += (e - s);
                
                /* Mark the room as engaged */
                engaged.push({newEnd, topmost.second});
            }
        }
        
        /* Find the lowest room_number with maximum frequency */
        int maxi = 0;
        for(int i = 1; i < n; i++) {
            if(freq[i] > freq[maxi])
                maxi = i;
        }
        return maxi;
    }
};