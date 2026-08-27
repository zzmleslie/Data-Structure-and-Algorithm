#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int> , greater<int> > p;
int main(void){
    int n , x , sum = 0;
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++ ){
        scanf("%d" , &x);
        p.push(x);
    }
    for(int i = 1 ; i < n ; i++){
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();
        p.push(a + b);
        sum += a + b;
    }
    printf("%d" , sum);

    return 0;
}