#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
/**
 * 
 * search intervals,find newInterval[0] pos1,newInterval[1] pos2;
 * 
 * 
 * 
 * mearge intervals[pos1] - intervals[pos2] - newInterval
 * 
 * 
 * */
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        if (intervals.size() < 1)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int pos1 = 0, pos2 = intervals.size() - 1;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0])
            {
                pos1 = i;
            }
            if (i > 0 && intervals[i - 1][1] < newInterval[0] && intervals[i][0] > newInterval[0])
            {
                pos1 = i;
            }
            if (i == intervals.size() - 1 && intervals[i][1] < newInterval[0]) //
            {
                pos1 = i;
            }
            if (intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[1])
            {
                pos2 = i;
            }
            if (i < intervals.size() - 1 && intervals[i][1] < newInterval[1] && intervals[i + 1][0] > newInterval[1])
            {
                pos2 = i;
            }
        }
        vector<vector<int>>::iterator it1 = intervals.begin() + pos1;
        vector<vector<int>>::iterator it2 = intervals.begin() + pos2 + 1;
        if (pos1 == pos2 && intervals[pos1][0] < newInterval[0] ? intervals[pos1][1] < newInterval[0] : intervals[pos1][0] > newInterval[1])
        {
            intervals.insert(intervals[pos1][0] < newInterval[0] ? intervals.begin() + pos1 + 1 : intervals.begin() + pos1, newInterval);
        }
        else
        {
            newInterval[0] = min(min(newInterval[0], intervals[pos1][0]), intervals[pos2][0]);
            newInterval[1] = max(max(newInterval[1], intervals[pos1][1]), intervals[pos2][1]);
            intervals.erase(it1, it2);
            intervals.insert(it1, newInterval);
        }
        return intervals;
    }
};

int main()
{
    vector<int> vec = {1, 2};
    // vector<vector<int>> vecs = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<vector<int>> vecs = { {7, 10},{22, 66}};
    auto ans = Solution().insert(vecs, vec);
    for (auto an : ans)
    {
        cout << an[0] << "," << an[1] << endl;
    }
    system("pause");
}
