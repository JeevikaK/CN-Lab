#include<stdio.h>
#include<math.h>

int gcd(int a, int b){
    while(1){
        int temp = a%b;
        if(temp==0)
            return b;
        a = b;
        b = temp;
    }
}

int main(){
    int p, q, msg,n, n_phi, e=2, d=e;
    printf("Enter two prime numbers \n");
    scanf("%d%d", &p, &q);
    printf("Enter message \n");
    scanf("%d", &msg);
    n = p * q;
    n_phi = (p-1) * (q-1);
    while(e<n_phi){
        if(gcd(e,n_phi)==1)
            break;
        else
            e++;
    }
    while(1){
        if(fmod(d*e, n_phi)==1)
            break;
        else
            d++;
    }
    long long encrypted = fmod(pow(msg,e),n);
    long long decrypted = fmod(pow(encrypted,d),n);
    printf("Message data =%d ",msg);
    printf("\np = %d",p);
    printf("\nq = %d",q);
    printf("\nn = pq = %d",n);
    printf("\nphi(n) = %d",n_phi);
    printf("\ne = %d",e);
    printf("\nd = %d ",d);
    printf("\nEncrypted data = %d",encrypted);
    printf("\nDecrypted data (from encrypted)=%d\n",decrypted);
}