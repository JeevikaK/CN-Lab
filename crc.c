#include<stdio.h>
#include<string.h>

void main(){
    int i,j, keylen,datalen;
    char data[100], key[100], key1[100], temp[100], quo[100], rem[100];

    printf("Enter the data \n");
    scanf("%s", data);
    printf("Enter key \n");
    scanf("%s", key);

    keylen=strlen(key);
    datalen=strlen(data);
    strcpy(key1, key);

    for(i=0; i<keylen-1; i++){
        data[datalen + i] = '0';
    }
    for(i=0; i<keylen; i++){
        temp[i] = data[i];
    }
    for(i=0; i<datalen;i++){
        quo[i] = temp[0];   
        if(quo[i] == '0'){
            for(j=0; j<keylen; j++)
                key[j] = '0';
        }
        else{
            for(j=0; j<keylen; j++)
                key[j] = key1[j];
        }
        for(j=keylen-1; j>0; j--){
            if(temp[j] == key[j])
                rem[j-1] = '0';
            else
                rem[j-1] = '1';
        }    
        rem[keylen-1] = data[keylen+i];
        strcpy(temp,rem);
    }
    strcpy(rem, temp);
    printf("\nQuotient is ");
    for (i=0;i<datalen;i++)
        printf("%c",quo[i]);
    printf("\nRemainder is ");
    for (i=0;i<keylen-1;i++)
        printf("%c",rem[i]);
    printf("\nFinal data is: ");
    for (i=0;i<datalen;i++)
        printf("%c",data[i]);
    for (i=0;i<keylen-1;i++)
        printf("%c",rem[i]);
    
}