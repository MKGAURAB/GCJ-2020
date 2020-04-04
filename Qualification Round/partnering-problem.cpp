#include <bits/stdc++.h>

using namespace std;

int main(int argv, const char *argc[])
{
    int test, n;
    vector<pair<int, pair<int, int>>> intervals;
    vector<int> mark;

    cin >> test;

    for (int kase = 1; kase <= test; ++kase)
    {
        cin >> n;

        mark = vector<int>(n, 0);
        intervals.clear();

        for (int i = 0; i < n; ++i)
        {
            int s, e;
            cin >> s >> e;
            intervals.push_back({e, {s, i}});
        }

        sort(begin(intervals), end(intervals), greater<pair<int, pair<int, int>>>());
        int in_count = 1;
        for (int i = 0; i < (int)intervals.size(); ++i)
        {
            int j = i + 1;
            while (j<(int)intervals.size() && intervals[j].first > intervals[j-1].second.first)
            {
                mark[intervals[j].second.first] = mark[intervals[j - 1].second.first] - 1;
                j++;
                in_count++;
            }
            cout<<i<<" and "<<j<<endl;
            if (in_count > 2)
                break;

            in_count = 1;
            i = j - 1;

            if(i!=0)
            {
                mark[intervals[i].second.first] = 1 - mark[intervals[i - 1].second.first];
            }
        }
        cout << "Case #" << kase << ": ";
        if (in_count > 2)
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            for (int i = 0; i < (int)mark.size(); ++i)
                cout << (mark[i] ? "C" : "J");
        }
        cout<<endl;
    }

    return 0;
}