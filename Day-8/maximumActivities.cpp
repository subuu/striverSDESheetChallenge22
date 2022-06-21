#include<algorithm>
#include<vector>

struct act{
    int start;
    int end;
};

bool static comparison(act a, act b){
    return a.end < b.end;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    
    int n = start.size();
    struct act activities[n];
    
    for(int i=0;i<n;i++){
        activities[i].end = finish[i];
        activities[i].start = start[i];
    }
    
    sort(activities, activities+n, comparison);
    
    int ans  = 1, limit = activities[0].end;
    for(int i=1;i<n;i++){
        if(activities[i].start >= limit){
            ans++; limit = activities[i].end;
        }
    }    
    
    return ans;
}
