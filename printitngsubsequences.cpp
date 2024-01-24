#include <bits/stdc++.h>
using namespace std;
void printsub(int ind, vector<int> &v, int arr[], int n)
{
    if (ind == n)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        if (v.size() == 0)
        {
            cout << " {}";
        }
        cout << endl;
        return;
    }
    v.push_back(arr[ind]);
    printsub(ind + 1, v, arr, n); // case of taking the element
    v.pop_back();
    printsub(ind + 1, v, arr, n); // case of not taking the element
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> s;
    printsub(0, s, arr, n);

    return 0;
}