#include <iostream>
#include <cstring>

using namespace std;

string s;
int total_r_cnt;
int total_k_cnt;


int p_20442()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (const char& c : s)
    {
        if (c == 'R')
            total_r_cnt++;
        else
            total_k_cnt++;
    }

    if (total_r_cnt == 0)
    {
        cout << 0;
        return 0;
    }

    if (s == "R")
    {
        cout << 1;
        return 0;
    }


    int ret = 0;

    int left_k = 0;
    int right_k = 0;
    int left_r = 0;
    int right_r = 0;


    int left = 0;
    int right = s.size() - 1;
    while (true)
    {
        if (left >= right)
        {
            break;
        }
        if (left_k == right_k)
        {
            while (left < right && s[left] != 'R')
            {
                left++;
                left_k++;
            }
            while (left < right && s[right] != 'R')
            {
                right--;
                right_k++;
            }
        }
        else if (left_k < right_k)
        {
            while (left < right && s[left] != 'R')
            {
                left++;
                left_k++;
            }
        }
        else
        {
            while (left < right && s[right] != 'R')
            {
                right--;
                right_k++;
            }
        }

        ret = max(ret, total_r_cnt - left_r - right_r + min(left_k, right_k) * 2);

        if (left_k == right_k)
        {
            left++;
            right--;
            left_r++;
            right_r++;
        }
        else if (left_k < right_k)
        {
            left++;
            left_r++;
        }
        else
        {
            right--;
            right_r++;
        }

        if (left >= right)
        {
            break;
        }
    }

    cout << ret;

    return 0;
}
