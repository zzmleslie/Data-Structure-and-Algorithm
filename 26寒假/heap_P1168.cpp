#include<iostream>
#include<queue>
using namespace std;
#define N 100005
priority_queue<int> b;
priority_queue<int , vector<int> , greater<int> > s;
int a[N];
int main(void){
    int n , p = 0 , tot = 1;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++ ){
        scanf("%d" , &a[i]);
    }
    for( ; tot <= n ; tot += 2){
        while(p < tot){
            b.push(a[++p]);
            s.push(b.top());
            b.pop();
        }
        printf("%d\n" , s.top());
        b.push(s.top());
        s.pop(); 
    }
    return 0;
}
