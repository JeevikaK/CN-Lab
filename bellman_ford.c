#include <stdio.h>
#include <stdlib.h>

int bellman(int g[20][20], int V, int E, int edge[20][2]){

    int i, u, v, k, distance[20], parent[20], s;
    int flag = 1;
    for(i=0; i<V; i++){
        distance[i] = 1000;
        parent[i] = -1;
    }
    printf("Enter the source \n");
    scanf("%d", &s);
    distance[s-1] = 0;
    
    for(i=0; i<V-1; i++){
        for(k=0; k<E; k++){
            u = edge[k][0];
            v = edge[k][1];
            if(distance[u] + g[u][v] < distance[v]){
                distance[v] = distance[u] + g[u][v];
                parent[v] = u; 
            }      
        }
    }
    for(k=0; k<E; k++){
        u = edge[k][0];
        v = edge[k][1];
        if(distance[u] + g[u][v] < distance[v])
            flag = 0;
    }
    if(flag){
        for(i=0; i<V; i++){
            printf("Vertex %d -> cost = %d parent = %d \n", i+1, distance[i], parent[i]+1);
        }
    }
    return flag;
}

int main(){
    int V, edge[20][2], g[20][20], i, j, k=0;
    printf("Enter num of vertices \n");
    scanf("%d", &V);
    printf("Enter graph \n");
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            scanf("%d", &g[i][j]);
            if(g[i][j]!=0){
                edge[k][0]=i;
                edge[k++][1] = j;
            }
        }
    }

    if(bellman(g, V, k, edge))
        printf("no negative weight cycle \n");
    else
        printf("negative weight cycle exists \n");
    return 0;
}