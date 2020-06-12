#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


struct Data
{
    string No;
    int num;
    int rank;
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<Data>nums[4];//A C M E
    unordered_map <string, int>name;//用于学号查找
    for (int i = 0; i < N; ++i)
    {
        string No;
        int c, m, e;
        cin >> No >> c >> m >> e;
        name[No]++;
        nums[0].push_back({ No,(c + m + e) / 3,1 });
        nums[1].push_back({ No,c,1 });
        nums[2].push_back({ No,m,1 });
        nums[3].push_back({ No,e,1 });
    }
    for (int i = 0; i < 4; ++i)
    {
        sort(nums[i].begin(), nums[i].end(), [](Data d1, Data d2) {return d1.num > d2.num; });
        for (int j = 1; j < nums[i].size(); ++j)
        {
            if (nums[i][j].num == nums[i][j - 1].num)//处理相同分数
                nums[i][j].rank = nums[i][j - 1].rank;
            else
                nums[i][j].rank = j + 1;//要跳过相同排名
        }
    }

    for (int j = 0; j < M; ++j)
    {
        string No;
        cin >> No;
        int a, c, m, e;
        if (name[No] == 0)
            cout << "N/A" << endl;
        else
        {
            for (int i = 0; i < name.size(); ++i)
            {
                if (nums[0][i].No == No)    a = nums[0][i].rank;
                if (nums[1][i].No == No)    c = nums[1][i].rank;
                if (nums[2][i].No == No)    m = nums[2][i].rank;
                if (nums[3][i].No == No)    e = nums[3][i].rank;
            }
            if (a <= c && a <= m && a <= e)                cout << a << " " << "A" << endl;
            else if (c <= a && c <= m && c <= e)        cout << c << " " << "C" << endl;
            else if (m <= a && m <= c && m <= e)        cout << m << " " << "M" << endl;
            else    cout << e << " " << "E" << endl;
        }
    }
    return 0;
}