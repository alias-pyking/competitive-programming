#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int k;
    cin >> n;
    cin >> k;
    int *arr = new int[n]();
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int unfairness = 0;
    int * dp = new int[k]();
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    int sumsof_array_elems = arr[0] + arr[1];
    for(int i = 2; i< k; i++)
    {
        dp[i] = dp[i - 1] + i * arr[i] - sumsof_array_elems;
        sumsof_array_elems += arr[i];
    }
    unfairness = dp[k-1];
    int temp = arr[0];
    int min_cost = INT_MAX;
    int temp_cost = 0;
    for(int i = 1; i < n - k; i++)
    {
        int sum = 0;
        sum = sumsof_array_elems - temp;
        temp_cost = unfairness - (2 * sum) + (k -1)*temp + (k- 1)*arr[i + k];
        min_cost = min(unfairness,min(min_cost,temp_cost));
        temp = arr[i];
    }
    // for(int i = 0; i < k; i++)
    // {
    //     cout << arr[i] <<" ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] <<" ";
    // }
    // cout << endl;
    cout  << unfairness << endl;
}

