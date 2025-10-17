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
    int radix = 1; // 최대 자릿수까지 계산을 하기 위한 변수
    while (1)      // 최대 자릿수가 몇 자리인지 알아내기 위한 반복문
    {
        if (radix >= max_val) // max_val는 입력과 동시에 구해놓은 배열에서의 최댓값
            break;
        radix *= 10;
    }
    for (int i = 1; i < radix; i *= 10) // 1의 자리 부터 10씩 곱하면서 최대자릿수까지 반복
    {
        for (int j = 0; j < MAX; j++) // 모든 배열을 다 탐색하면서 큐에 삽입
        {
            int k;
            if (arr[j] < i) // 만약 현재 배열의 값이 현재 찾는 자릿수보다 작으면 0
                k = 0;
            else
                k = (arr[j] / i) % 10; // 그게 아니라면 공식에 따라 자릿수 구하기
            q[k].push(arr[j]);         // queue배열에 해당 값을 순차적으로 저장
        }
        int idx = 0;
        for (int j = 0; j < 10; j++) // 0~9까지 queue에 저장된 값들을 순차적으로 빼내기 위한 반복문
        {
            while (!q[j].empty()) // 해당 index번호의 queeue가 비어있을때까지 반복
            {
                arr[idx++] = q[j].front(); // 하나씩 빼면서 배열에 다시 저장
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