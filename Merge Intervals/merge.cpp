/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    static bool myCompare (Interval i,Interval j) { 
        return (i.start<j.start); 
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        int start;
        int end;
        vector<Interval> ret;
        if(intervals.size()<=1){
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end(),myCompare);
        
        start = intervals[0].start;
        end = intervals[0].end;
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start>end){
                Interval temp(start,end);
                ret.push_back(temp);
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else{
                if(intervals[i].end > end){
                    end = intervals[i].end;
                }
            }
        }
        Interval temp(start,end);
        ret.push_back(temp);
        return ret;
    }
};
