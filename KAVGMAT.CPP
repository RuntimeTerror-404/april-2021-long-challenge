// worthy matrix

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int A[n + 1][m + 1];
        memset(A, 0, sizeof(A));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> A[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                A[i][j] += A[i][j-1];
            }
        }

        for(int j=1; j<=m; j++){
            for(int i=1; i<=n; i++){
                A[i][j] += A[i-1][j];
            }
        }




        int ans = 0;
        for (int side = 1; side <= n; side++)
        {
            for (int i = 1; i <= n - side + 1; i++)
            {
                int low = 1;
                int high = m - side + 1;
                int mid;
                int p;
                int flag = 0;
                while (low <= high)
                {
                    mid = (high + low) / 2;
                    int sum = A[i + side - 1][mid + side - 1] - A[i + side - 1][mid - 1] - A[i - 1][mid + side - 1] + A[i - 1][mid - 1];

                    if (sum >= k * side * side)
                    {
                        high = mid - 1;
                        p = mid;
                        flag = 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                if (flag == 1)
                {
                    ans += (m - side - p + 2);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}