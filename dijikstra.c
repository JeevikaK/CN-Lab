#include<stdio.h>

int n, source, cost[100][100], d[100], visited[100], i, j, min, u, v;
void dijikstra(int, int, int[100], int[100], int[100][100]);
void main(){

    printf("Enter number of vertices \n");
    scanf("%d", &n);
    printf("Enter the cost matrix \n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter the source \n");
    scanf("%d", &source);
    dijikstra(n, source, visited, d, cost);
    for(i=1; i<=n; i++){
        if(i!=source)
    printf("shorted distance from %d -> %d = %d \n", source, i, d[i]);
    }
}

void dijikstra(int n, int source, int visited[100], int d[100], int cost[100][100]){
    for(i=1; i<=n; i++){
        visited[i] = 0;
        d[i] = cost[source][i];
    }
    visited[source] = 1;
    d[source] = 0;
    
    for(j=2; j<=n; j++){
        min=999;
        for(i=1; i<=n; i++){
            if(!visited[i]){
                if(d[i] < min)
                    min = d[i];
                u = i;
            }
        }
        visited[u] = 1;
        for(v=1; v<=n; v++){
            if(cost[u][v]!=999 && visited[v]==0){
                if(d[v] > d[u] + cost[u][v])
                    d[v] = d[u] + cost[u][v];
            }
        }
    }
}