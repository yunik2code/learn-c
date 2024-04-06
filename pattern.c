// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int i,j,k,l=0,m=1,n=0;

    for(i=0;i<5;i++){
        for(j=n;j<5;j++){
            if(j<3){
                for(k=0;k<j;k++){
                    printf("\t");
                }
            }
            else{
                for(k=m;k>l;k--){
                    m--;
                    printf("\t");
                }
            }
                
            
            printf("*\n");
        
        }
        m=1;
        n=1;
        
    }
    

    return 0;
}

