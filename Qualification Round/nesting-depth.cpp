#include <bits/stdc++.h>

using namespace std;

string generateWithParanthese(string num)
{
    string result = "";
    stack<int> st;

    for (auto a : num)
    {
        int digit = a - '0';

        if (st.empty())
        {
            result += string(digit, '(') + a;
            for (int i = 1; i <= digit; ++i)
                st.push(')');
            continue;
        }

        int size = st.size();

        if (size == digit)
        {
            result += a;
            continue;
        }

        if (size > digit)
        {
            int pop_count = size - digit;

            result += string(pop_count, ')') + a;

            while (pop_count--)
                st.pop();

            continue;
        }

        if (size < digit)
        {
            int push_count = digit - size;

            result += string(push_count, '(') + a;

            while (push_count--)
                st.push(')');
            continue;
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int test;
    string num;

    cin >> test;

    for (int kase = 1; kase <= test; ++kase)
    {
        cin >> num;

        cout << "Case #" << kase << ": " << generateWithParanthese(num) << endl;
    }
    return 0;
}
