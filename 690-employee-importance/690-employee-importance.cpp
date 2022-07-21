/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int solve(vector<Employee*> &emp,unordered_map<int,int> &mp,int i)
    {
        int x=0;
        int in=mp[i];
        x+=emp[in]->importance;
        
        for(auto y:emp[in]->subordinates)
        {
            x+=solve(emp,mp,y);
        }
        
        return x;
    }
    
    int getImportance(vector<Employee*> emp, int id) {
        
        unordered_map<int,int> mp;
        int n=emp.size();
        for(int i=0;i<n;i++)
        {
            mp[emp[i]->id]=i;
        }
        
        return solve(emp,mp,id);
    }
};