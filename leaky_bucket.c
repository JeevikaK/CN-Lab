#include<stdio.h>

int main(){
    int incoming, outgoing, bucket, n, store = 0;
    printf("Enter bucket size, outgoing rate, number if inputs \n");
    scanf("%d%d%d", &bucket, &outgoing, &n);
    while(n!=0){
        printf("Enter the incoming packet size \n");
        scanf("%d", &incoming);
        if(incoming <= (bucket-store)){
            store+=incoming;
            printf("bucket buffer size = %d out of %d \n", store, bucket);
        }
        else{
            printf("Dropped %d no. of packets \n", incoming-(bucket-store));
            printf("bucket buffer size = %d out of %d \n", store, bucket);
            store = bucket;
        }
        store = store - outgoing;
        printf("After outgoing %d packets left out of %d in buffer \n", store, bucket);
        n--;
    }
}