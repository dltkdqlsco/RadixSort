#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

#define MAX 100
using namespace std;

int max_val;
int arr[MAX];
bool flag[10001];
queue<int> q[10];

void print()
{
    cout << "####################################################################################################################" << endl;

    int cnt = 0;
    for (int i = 0; i < MAX; i++)
    {
        printf("%5d ", arr[i]);
        cnt++;
        if (cnt == 20)
        {
            cnt = 0;
            cout << endl;
        }
    }
    cout << "####################################################################################################################" << endl;
}

void radixSort()
{
    int radix = 1;
    while (1)
    {
        if (radix >= max_val)
            break;
        radix *= 10;
    }
    for (int i = 1; i < radix; i *= 10)
    {
        for (int j = 0; j < MAX; j++)
        {
            int k;
            if (arr[j] < i)
                k = 0;
            else
                k = (arr[j] / i) % 10;
            q[k].push(arr[j]);
        }
        int idx = 0;
        for (int j = 0; j < 10; j++)
        {
            while (!q[j].empty())
            {
                arr[idx++] = q[j].front();
                q[j].pop();
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    max_val = 0;
    for (int i = 0; i < MAX;)
    {
        arr[i] = (rand() % 10000) + 1;
        if (flag[arr[i]] == false)
        {
            flag[arr[i]] = true;
            if (max_val < arr[i])
            {
                max_val = arr[i];
            }
            i++;
        }
    }
    cout << "Before Radix Sort" << endl;
    print();
    radixSort();
    cout << "After Radix Sort" << endl;
    print();
    return 0;
}