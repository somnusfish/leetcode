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
    static int leftSearch(vector<Interval>& intervals, Interval newInterval){
        int left = 0;
        int right = intervals.size()-1;
        int middle;
        while(left<=right){
            middle = (left+right)/2;
            if(intervals[middle].start == newInterval.start){
                return middle;
            }
            else if(intervals[middle].start > newInterval.start){
                right = middle - 1;
            }
            else{
                left = middle+1;
            }
        }
        return left;
    }
    static vector<Interval> merge(vector<Interval>& intervals) {
        int start;
        int end;
        vector<Interval> ret;
        if(intervals.size()<=1){
            return intervals;
        }
        
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
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        if(intervals.size()<=0){
            ret.push_back(newInterval);
            return ret;
        }
        int left = leftSearch(intervals, newInterval);
        intervals.insert(intervals.begin()+left, newInterval);
        
        return merge(intervals);
        
        
    }
};
