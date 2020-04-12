#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int test, n, trace_no, row_count, column_count;
    vector<int> num;
    vector<set<int>> columns;
    set<int> row;

    cin >> test;

    for (int i = 0; i < test; i++)
    {
        cin >> n;

        trace_no = row_count = column_count = 0;

        num.resize(n);
        columns = vector<set<int>>(n, set<int>());

        for (int j = 0; j < n; j++)
        {
            row.clear();
            for (int k = 0; k < n; k++)
            {
                cin >> num[k];
                row.insert(num[k]);
                columns[k].insert(num[k]);
                if (j == k)
                    trace_no += num[k];
            }

            row_count += (row.size() != n);
        }
        column_count = count_if(begin(columns), end(columns), [&](set<int> is) { return is.size() != n; });

        cout << "Case #" << (i + 1) << ": " << trace_no << " " << row_count << " " << column_count << endl;
    }

    return 0;
}
