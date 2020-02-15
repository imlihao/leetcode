#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Solution
{
public:
    //Solution() = default;
    Solution(int sz)
    {
        this->map_s_ptr = this->generateMap(sz, sz);
        n = m = sz;
    };

    void findAndShowPath(pair<int, int> &st, pair<int, int> &ed)
    {
        vector<pair<int, int>> vec{st, ed};
        this->showPath(vec);
        auto timeS = clock();
        auto vec1 = this->findPathBFS(st, ed);
        auto timeE = clock();
        cout << "timeSpan:" << (double)(timeE - timeS) / CLOCKS_PER_SEC << endl;
        this->showPath(vec1);
        auto vec2 = this->findPathDijastra(st, ed);
        this->showPath(vec2);
        auto vec3 = this->findPathAStar(st, ed);
        this->showPath(vec3);
    }

private:
    shared_ptr<vector<vector<int>>> map_s_ptr;
    int m, n;
    vector<pair<int, int>> findNbr(pair<int, int> &st)
    {
        vector<pair<int, int>> drs{{0, 1},
                                   {0, -1},
                                   {1, 0},
                                   {-1, 0}};
        vector<pair<int, int>> ans;
        for (auto dr : drs)
        {

            int a = st.first + dr.first;
            int b = st.second + dr.second;
            if (((a) < m) && ((a) >= 0) && ((b) < n) && ((b) >= 0))
            {
                ans.push_back({a, b});
            }
        }
        return ans;
    };

    static std::shared_ptr<vector<vector<int>>> generateMap(int m, int n)
    {
        std::shared_ptr<vector<vector<int>>> ptr(new vector<vector<int>>(n, vector<int>(m, 1)));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                (*ptr)[i][j] = (i == 3 && j >= 0 && j < m - 1) ? 0 : 1;
            }
        }
        return ptr;
    }

    static void showMap(std::shared_ptr<vector<vector<int>>> ptr)
    {
        for (auto a : *ptr)
        {
            for (auto b : a)
            {
                cout << setw(4) << b;
            }
            cout << endl;
        }
        cout << endl;
    }

    void showPath(vector<pair<int, int>> const &pths)
    {
        vector<vector<int>> vec(*map_s_ptr);
        for (int i = 0; i < pths.size(); i++)
        {
            auto ph = pths[i];
            vec[ph.first][ph.second] = i + 2;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << setw(4) << vec[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    /**
     * BFS
     * */
    vector<pair<int, int>> findPathBFS(pair<int, int> &st, pair<int, int> &ed)
    {
        vector<pair<int, int>> path;
        vector<pair<int, int>> que;
        que.push_back(st);
        set<pair<int, int>> closed{st};
        map<pair<int, int>, int> mp;
        bool isFind = false;
        pair<int, int> fakeEd;
        int edV = 0;
        mp.insert(make_pair(st, edV));
        while (!que.empty())
        {
            int siz = que.size();
            ++edV;
            //cout << "EDV:" << edV << " " << siz << endl;
            for (int i = 0; i < siz; i++)
            {
                auto pt = que[i];
                auto nbrs = findNbr(pt);
                for (auto nbr : nbrs)
                {
                    if (closed.find(nbr) == closed.end() && (*map_s_ptr)[nbr.first][nbr.second] != 0)
                    {
                        que.push_back(nbr);
                        //(*map_s_ptr)[nbr.first][nbr.second] = edV + 1;
                        mp.insert(make_pair(nbr, edV));
                        closed.insert(nbr);
                        fakeEd.first = nbr.first;
                        fakeEd.second = nbr.second;
                        if (nbr == ed)
                        {
                            goto here;
                        }
                    }
                }
            }
            que.erase(que.begin(), que.begin() + siz);
        }
    here:
        //this->showMap(this->map_s_ptr);
        while (edV > 0)
        {
            auto nbrs = findNbr(fakeEd);
            for (auto nbr : nbrs)
            {
                auto mpNb = mp.find(nbr);
                if (mpNb != mp.end() && mpNb->second == edV - 1)
                {
                    edV--;
                    path.insert(path.begin(), fakeEd);
                    fakeEd = mpNb->first;
                    break;
                }
            }
        }
        path.insert(path.begin(), st);
        return path;
    };

    vector<pair<int, int>> findPathDijastra(pair<int, int> &st, pair<int, int> &ed)
    {
        int len = m * n;
        vector<int> dis(len, 1000);
        vector<int> path_i(len, -1);
        vector<bool> vis(len, false);
        vector<pair<int, int>> path;
        int st_i = pair2num(st);
        int ed_i = pair2num(ed);
        dis[st_i] = 0;
        vis[st_i] = true;
        int curPt;
        auto nbrs = findNbr(st);
        for (auto nbr : nbrs)
        {
            int nbr_i = pair2num(nbr);
            if ((*map_s_ptr)[nbr.first][nbr.second] == 1)
            {
                dis[nbr_i] = 1;
                path_i[nbr_i] = st_i;
            }
        }
        while (curPt > -1)
        {
            curPt = -1;

            for (int i = 0; i < len; i++)
            {
                if (!vis[i])
                {
                    curPt = curPt == -1 ? i : (dis[i] < dis[curPt] ? i : curPt);
                }
            }
            if (curPt > -1)
            {
                vis[curPt] = true;
                auto curPr = num2pair(curPt);
                // vector<pair<int, int>> drs{{0, 1},
                //                            {0, -1},
                //                            {1, 0},
                //                            {-1, 0}};
                // vector<pair<int, int>> ans;
                // for (auto dr : drs)
                // {

                //     int a = curPr.first + dr.first;
                //     int b = curPr.second + dr.second;
                //     if (((a) < m) && ((a) >= 0) && ((b) < n) && ((b) >= 0))
                //     {
                //         ans.push_back({a, b});
                //     }
                // }
                auto ans = findNbr(curPr);
                for (auto n : ans)
                {
                    auto n_i = pair2num(n);
                    if (!vis[n_i] && ((*map_s_ptr)[n.first][n.second] == 1))
                    {
                        if (dis[curPt] != 1000 && (dis[n_i] > dis[curPt] + 1))
                        {
                            dis[n_i] = dis[curPt] + 1;
                            path_i[n_i] = curPt;
                        }
                    }
                }
            }
        }
        int cpt = ed_i;
        path.push_back(num2pair(cpt));
        if (path_i[ed_i] != -1)
        {
            while (cpt != st_i)
            {
                path.insert(path.begin(), num2pair(path_i[cpt]));
                cpt = path_i[cpt];
            }
        }
        return path;
    }

    pair<int, int> num2pair(int pos)
    {
        return pair<int, int>(pos / n, pos % m);
    }

    int pair2num(pair<int, int> &pr)
    {
        return pr.first * n + pr.second;
    }

    vector<pair<int, int>> findPathAStar(pair<int, int> &st, pair<int, int> &ed)
    {
        int len = m * n;
        vector<int> dis(len, 10000);
        vector<int> path_i(len, -1);
        vector<bool> vis(len, false);
        vector<pair<int, int>> path;
        vector<int> que;
        int st_i = pair2num(st);
        int ed_i = pair2num(ed);
        que.push_back(st_i);
        dis[st_i] = 0;
        while (!que.empty())
        {
            int curPt = -1, curF = INT_MAX, pos = 0;
            for (int i = 0; i < que.size(); i++)
            {
                int value = que[i];
                int F_i = clcF(value, ed_i) + dis[value];
                if (F_i < curF)
                {
                    curF = F_i;
                    curPt = value;
                    pos = i;
                }
            }
            if (curPt != -1)
            {
                que.erase(que.begin() + pos);
            }
            //cout << curPt << " " << vis[curPt] << " " << dis[curPt] << endl;
            if (curPt > -1)
            {
                vis[curPt] = true;
                auto curPr = num2pair(curPt);
                auto ans = findNbr(curPr);
                for (auto next : ans)
                {

                    if ((*map_s_ptr)[next.first][next.second] == 1)
                    {
                        auto n_i = pair2num(next);
                        if (next == ed)
                        {
                            path_i[n_i] = curPt;
                            goto here;
                        }
                        int newCost = dis[curPt] + 1;
                        if (!vis[n_i])
                        {
                            // cout << curPt << ":" << n_i << ":";
                            // cout << vis[n_i] << " " << newCost << " " << dis[n_i] << endl;
                            dis[n_i] = newCost;
                            path_i[n_i] = curPt;
                            if (std::find(que.begin(), que.end(), n_i) == que.end())
                            {
                                que.push_back(n_i);
                            }
                        }
                        else if (newCost < dis[n_i])
                        {
                            dis[n_i] = newCost;
                            path_i[n_i] = curPt;
                        }
                    }
                }
            }
        }
    here:
        int cpt = ed_i;
        path.push_back(num2pair(cpt));
        if (path_i[ed_i] != -1)
        {
            while (cpt != st_i)
            {
                path.insert(path.begin(), num2pair(path_i[cpt]));
                cpt = path_i[cpt];
            }
        }
        return path;
    };

    int clcF(int pt_i, int ed_i)
    {
        auto pt = num2pair(pt_i);
        auto ed = num2pair(ed_i);
        int mahadun = abs(pt.first - ed.first) + abs(pt.second - ed.second);
        int m2 = std::pow(pt.first - ed.first, 2) + std::pow(pt.second - ed.second, 2);
        return m2;
    }
};

class Node
{
public:
    int val;
    Node(int v) : val(v)
    {
        cout << "create Node " << val << ":" << this << endl;
    }
    ~Node()
    {
        cout << "destroy Node" << val << ":" << this << endl;
    }
};
Node createNode(int v)
{
    return Node(v);
}

void test()
{
    vector<Node> vec;
    cout << "xunhuan" << endl;
    for (int i = 1; i < 2; i++)
    {
        cout << "i:"
             << " strat" << endl;
        auto a = createNode(i);
        vec.push_back(a);
        cout << "i:"
             << " end" << endl;
    }
    cout << "xunhuanEnd" << endl;
    cout << &vec[0] << endl;
}

void test2()
{
    Node c(4);
    c = NULL;
    c = Node(1);
}
int main()
{
    Solution slu(10);
    pair<int, int> a{0, 0};
    pair<int, int> b{7, 2};
    slu.findAndShowPath(a, b);
    system("pause");
}
