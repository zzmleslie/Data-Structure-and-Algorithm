#include<iostream>
#include<queue>
using namespace std;
#define N 100005

priority_queue<long long,vector<long long>,greater<long long> >s;
long long a[N];
int main(void){
    int n;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++){
        scanf("%lld" , &a[i]);
    }

    for(int i = 1; i <= n ; i++){
        long long cur = a[i];
        int cnt = 0;
        for(int j = 1 ; j <= n ; j++){
            if(j != i) s.push(a[j]);
        }
        int siz = n - 1;
        while(siz){
            if(s.top() <= cur){
                cur += s.top();
                s.pop();
                siz--;
                cnt++;
            }else{
                break;
            }
            //printf("cur = %lld\n" , cur);
        }
        while(siz){
            s.pop(); siz--;
        }
        printf("%d " , cnt);

    }
    return 0;
}