/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

1(5) <- 2(3)
     <- 3(3)
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        for (Employee* employee : employees) {
            if (employee->id == id) {
                res += employee->importance;
                for (int sub : employee->subordinates){
                    res += getImportance(employees, sub);
                }
            break;
            }
        }
        return res;
    }
};