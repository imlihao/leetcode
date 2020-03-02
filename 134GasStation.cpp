//134. Gas Station
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int needStep = gas.size();
        int sumG = 0;
        queue<int> indexQue;
        for (int i = 0; i < needStep; i++)
        {
            gas[i] = gas[i] - cost[i];
            sumG += gas[i];
        }
        if (sumG < 0)
            return -1;
        int j = 0;
        vector<int> posArr;
        int i = 0;
        while(i<needStep)
        {
            posArr.push_back(i);
            int cSum = 0;
            if (gas[i] < 0)
            {
                while (  i < needStep&&gas[i] < 0)
                {
                    cSum += gas[i];
                    i++;
                }
            }
            else
            {
                while ( i < needStep && gas[i] >= 0 )
                {
                    cSum += gas[i];
                    i++;
                }
            }
            gas[j] = cSum;
            j++;
        }
        int step = 0;
        while (step < j)
        {
            int s1 = step;
            int s2 = j;
            int cr = 0;
            bool bol = true;
            while (s2 > 0)
            {
                cr += gas[s1];
                s1 = (s1 + 1) % j;
                if (cr < 0)
                {
                    bol = false;
                    break;
                }
                s2--;
            }
            if (bol)
                return posArr[step];
            step++;
        }
        return -1;
    }
};

int main()
{
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    cout << Solution().canCompleteCircuit(gas, cost) << endl;
    system("pause");
}