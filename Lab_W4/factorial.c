#include <stdio.h>

int factorial(int N)
{
    if (N==0){
        return 1;
    }
    if (N==1){
        return 1;
    }
    else{
        return N*factorial(N-1);
    }
}

int factorial_ascendent(int N)
{
    int ans=1;
    if (N==0){
        ans = 1;
    }
    else{
        for(int i = 1; i <= N; i++){
            ans = ans*i;
        }
    }
    return ans;
}

int factorial_decendent(int N)
{
    int answer = 1;
    if (N==0){
        answer = 1;
    }
    else{
        for(int i = N; i >= 1; i--){
            answer = answer*i;
        }
    }
    return answer;
}

int main(){
    int N = 1;
    int result1 = factorial(N);
    int result2 = factorial_ascendent(N);
    int result3 = factorial_decendent(N);
    printf("The factorial of %d is %d, %d, %d", N, result1, result2, result3);
    return 0;
}