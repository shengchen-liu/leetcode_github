/*
pos  speed
10   2
8    4
0    1
5    1
3    3


0 1 2 3 4 5 6 7 8 9 10 11 12
                    1
                2
                                   
                           1
                           2
                           
car1's initial pos < car2's initial pos
1. v1 <= v2:
    they never merge => 2 fleets
2. v1 > v2:
    where do they merge
x0 + v1 * t  vs. y0 + v2 * t
*/

class Car {
public:
    int position;
    double time;
    Car (int p, double t) {
        this->position = p;
        this->time = t;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<Car> cars;
        for (int i = 0; i < n; ++i) {
            Car car(position[i], (double) (target - position[i]) / speed[i]);
            cars.emplace_back(car);
        }
        auto comp = [](const Car& car1, const Car& car2){
            return car1.position < car2.position;
        };
        
        sort(cars.begin(), cars.end(), comp);
        
        int res = 0;
        int t = n;
        while (--t > 0) {
            if (cars[t].time < cars[t - 1].time)
                ++res; // front car arrives sooner
            else cars[t - 1] =cars[t];  // else, the back car arrives the same time as front car
        }
        return res + (t == 0 ? 1 : 0);
    }
};

