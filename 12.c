//tower of hanoi
#include <stdio.h>

void towerofhanoi(int n , char from , char to , char temp){
    if (n == 1)
    { printf("Move Disk 1 From %c to %c\n",from,to);
        return ;
    }

    towerofhanoi(n-1 , from , temp , to);
    printf("Moved Disk %d From %c To %c\n",n,from,to);
    towerofhanoi(n-1 , temp , to , from);
    
}

int main(){
    int n = 3 ;
    towerofhanoi(n , 'A' , 'C' , 'B');
    return 0 ;
}