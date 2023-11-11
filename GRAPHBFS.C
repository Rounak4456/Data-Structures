#include<stdio.h>
#include<stdlib.h>
char *bit;
int *parent;
int *Q;
int **VAL;
int n;
int source;
int f, r;
int visitcount;
int bfs(int );
void Path(int );

int main()
{
    int i,ac,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    VAL=(int **)malloc(n*sizeof(int *));

    bit=(char*)calloc(n,sizeof(char));

    parent=(int *)malloc(n*sizeof(int));

    Q=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        printf("How many vertices adjacent to vertex %d ?", i);
        scanf("%d", &ac);
        VAL[i]=(int*)malloc((ac+1)*sizeof(int));
        if (ac != 0) 
        {
            printf("Enter names of %d adjacent vertices: ", ac);
            for(j=0;j<ac;j++)
            {
                scanf("%d", &VAL[i][j]);
            }
        }
        VAL[i][ac]=-1;
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("BFS sequence is :\n ");
    do
    {
        f=0; 
        r=-1;

        visitcount=visitcount+bfs(source);

        if( visitcount !=n)
        {
            printf("\nBFS initiated with new source because Graph is disconnected \n");

            for(i=0;i<n;i++)
            {
                if(bit[i]==0)
                break;
            }

            source=i;
        }
        else
            break;
    } while(1);

    printf("\nShortest paths to vertices are as below: \n");
    for(i=0; i<n ; i++)
    {
        printf("Destination=%d Path= ",i );
        Path(i);
        printf("\n");
    }
}
int bfs(int source)
{
    int dequeuedvertex;
    int i,adjacentnode;
    int touchcount;
    r++;
    Q[r]=source;
    bit[source]=1; 
    parent[source]=-1;
    touchcount=1;
    do
    {
        dequeuedvertex=Q[f]; f++; i=0;
        printf("%d ", dequeuedvertex);
        adjacentnode= VAL[dequeuedvertex][i];
        while( adjacentnode != -1)
        {   
            if( bit[adjacentnode] == 0)
            {
                r++;
                Q[r]=adjacentnode;
                bit[adjacentnode]=1;
                parent[adjacentnode]=dequeuedvertex;
                touchcount++;
            }
            i++;
            adjacentnode= VAL[dequeuedvertex][i];
        }
    }while(f <= r);
    return touchcount;
}
void Path(int destination)
{
    while(destination != -1)
    {
        printf("%d ", destination);
        destination = parent[destination];
    }
}