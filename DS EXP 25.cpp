#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int compare(const void* a, const void* b){
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

/* Union-Find functions */
int find(int parent[], int i){
    if(parent[i]==i) return i;
    return parent[i] = find(parent,parent[i]);
}

void unionSet(int parent[], int x, int y){
    int xset = find(parent,x);
    int yset = find(parent,y);
    parent[xset] = yset;
}

int main(){
    int n, e;
    scanf("%d %d",&n,&e); // vertices and edges
    struct Edge edges[e];
    for(int i=0;i<e;i++)
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);

    qsort(edges,e,sizeof(edges[0]),compare);

    int parent[n];
    for(int i=0;i<n;i++) parent[i]=i;

    printf("Edge \tWeight\n");
    for(int i=0,count=0; i<e && count<n-1; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if(find(parent,u) != find(parent,v)){
            printf("%d - %d \t%d\n", u, v, w);
            unionSet(parent,u,v);
            count++;
        }
    }
    return 0;
}

