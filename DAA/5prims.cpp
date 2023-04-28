#include <iostream>
#include <cstring>
#define INF 9999999
#define V 5

using namespace std;

int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 5, 66},
    {0, 19, 5, 0, 41},
    {0, 42, 66, 41, 0}
};

int main() {
    int no_edge;
    bool selected[V];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    int x, y;
    int edges[V], ei = 0, wi = 0;
    int weigth[V]; 
    cout << "Edge : Weight \n";
    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " =" << y << " : " << G[x][y] << "\n";
        edges[ei] = x;
        weigth[wi] = G[x][y];
        ei++;
        wi++;
        selected[y] = true;
        no_edge++;
    }
    int sum=0;
    for (int i = 0; i < V-1; i++) {
        cout << edges[i] << " = " << weigth[i] << "\n";
        if (edges[i] == edges[i + 1]) {
            if (weigth[i] > weigth[i + 1]) {
                sum = weigth[i + 1] + sum;
            } else {
                sum = weigth[i] + sum;
            }
            i++;
        } else {
            sum = weigth[i] + sum;
        }
    }
    cout << "The minimum spanning tree cost is = " << sum << "\n";
    return 0;
}
