#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int start_num;
        int final_num;

        int start_level = 1;
        int final_level = 1;
        int i = 1;
        int increase = 2;

        int result = 0;

        cin >> start_num >> final_num;
        while (true)
        {
            if (start_num <= i)
                break;
            i = i + increase;
            increase++;
            start_level++;
        }
        i = 1;
        increase = 2;
        while (true)
        {
            if (final_num <= i)
                break;
            i = i + increase;
            increase++;
            final_level++;
        }
        int diff_level;
        if (start_level >= final_level)
        {
            int tmp;
            diff_level = start_level - final_level;
            tmp = start_num;
            start_num = final_num;
            final_num = tmp;
            tmp = start_level;
            start_level = final_level;
            final_level = tmp;
        }
        else
            diff_level = final_level - start_level;

        if (diff_level == 0)
        {
            if (start_num >= final_num)
                result = start_num - final_num;
            else
                result = final_num - start_num;
        }
        int first_num = start_num;
        int last_num = start_num;
        int left_increase = start_level;
        int right_increase = start_level + 1;
        for (int j = 0; j < diff_level; j++)
        {
            first_num = first_num + left_increase;
            last_num = last_num + right_increase;
            left_increase++;
            right_increase++;
        }
        if (final_num <= last_num && final_num >= first_num)
            result = diff_level;
        else if (final_num > last_num)
            result = final_num - last_num + diff_level;
        else
            result = first_num - final_num + diff_level;

        cout << '#' << test_case << ' ' << result << "\n";
    }
    return 0;
}