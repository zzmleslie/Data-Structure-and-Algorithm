#include<iostream>
using namespace std;
#define N 105
int a[N][N];
int main(void){
    int n;
    cin >> n;
    for(int u = 1 ; u <= n ; u++){
        for(int v = 1 ; v <= n; v++){
            scanf("%d" , &a[u][v]);
        }
    }
    for (int k = 1 ; k <= n ; k++){
        for(int u = 1; u<= n ; u++){
            for(int v = 1 ; v <= n ; v++){
                a[u][v] = (a[u][v] + a[u][k] * a[k][v]) > 0 ? 1 : 0;
            }
        }
    }
    for(int u = 1; u <= n ; u++){
        for(int v = 1 ; v<= n ; v++){
            printf("%d " , a[u][v]);
        }
        printf("\n");
    }
    return 0;
}