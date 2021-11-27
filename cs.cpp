#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int findMax(vector<int> &m)
{
    int max = m[0];
    for (int i = 0; i < m.size(); i++)
    {
        if (max < m[i])
        {
            max = m[i];
        }
    }
    return max;
}

void countingSort(vector<int> &m, int max_value)
{
    // Создаем массив счетчиков
    vector<int> counts;
    counts.resize(max_value + 1);

    // Считаем количество элементов для каждого значения
    for (int i = 0; i < m.size(); i++)
    {
        counts[m[i]]++;
    }

    int index = 0;

    for (int i = 0; i <= max_value; i++)
    {
        for (int j = 1; j <= counts[i]; j++)
        {
            m[index] = i;
            index++;
        }
    }
};

int main()
{
    cout << "Print size of vector: ";
    int n;
    cin >> n;
    
    vector<int> m;
    m.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[i] = x;
    }
    
    countingSort(m, findMax(m));

    for (int i = 0; i < n; i++)
    {
        cout << m[i] << ' ';
    }
}