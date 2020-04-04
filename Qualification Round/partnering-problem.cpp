#include <bits/stdc++.h>

using namespace std;

int main(int argv, const char *argc[])
{
    int test, n;
    vector<pair<int, pair<int, int>>> intervals, seta, setb, setc;
    vector<int> mark;

    cin >> test;

    for (int kase = 1; kase <= test; ++kase)
    {
        cin >> n;

        mark = vector<int>(n, 0);
        seta.clear();
        setb.clear();
        setc.clear();
        intervals.clear();

        for (int i = 0; i < n; ++i)
        {
            int s, e;
            cin >> s >> e;
            intervals.push_back({s, {e, i}});
        }

        sort(begin(intervals), end(intervals), less<pair<int, pair<int, int>>>());

        seta.push_back(intervals[0]);
        mark[seta.back().second.second] = 1;

        for (int i = 1; i < (int)intervals.size(); ++i)
        {
            if (seta.back().second.first <= intervals[i].first)
            {
                seta.push_back(intervals[i]);
                mark[seta.back().second.second] = 1;
            }
            else
            {
                setb.push_back(intervals[i]);
                mark[setb.back().second.second] = 0;
            }
        }

        if(setb.size()>0) setc.push_back(setb[0]);
        for(int i=1; i < setb.size(); i++)
        {
            if(setc.back().second.first<=setb[i].first)
            {
                setc.push_back(setb[i]);
            }
        }

        cout << "Case #" << kase << ": ";
        if (setc.size()!=setb.size())
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            for (int i = 0; i < (int)mark.size(); ++i)
                cout << (mark[i] ? "C" : "J");
        }
        cout << endl;
    }

    return 0;
}