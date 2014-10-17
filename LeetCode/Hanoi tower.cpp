#include <cstdio>
void hanoi(int n, char from, char to, char via){
    if (n == 1){
        printf("Move %d to %c\n", n, to);
    }else{
        hanoi(n-1, from, via, to);
        printf("Move %d to %c\n", n, to);
        hanoi(n-1, via, to, from);
    }
}
int main(int argc, char const *argv[])
{
    hanoi(3, 'A', 'C', 'B');
    return 0;
}