#include <stdio.h>
#include <limits.h>

int tsp(int graph[][4], int n, int visited[], int currPos, int count, int cost, int ans) {
    if (count == n && graph[currPos][0] != 0) {
        ans = (cost + graph[currPos][0] < ans) ? cost + graph[currPos][0] : ans;
        return ans;
    }

    for (int city = 0; city < n; city++) {
        if (visited[city] == 0 && graph[currPos][city] != 0) {
            visited[city] = 1;
            ans = tsp(graph, n, visited, city, count + 1, cost + graph[currPos][city], ans);
            visited[city] = 0;
        }
    }
    return ans;
}

int main() {
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int n = 4;
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[0] = 1;  
    
    int ans = INT_MAX;
    ans = tsp(graph, n, visited, 0, 1, 0, ans);
    
    printf("The minimum cost of the TSP tour is: %d\n", ans);

    return 0;
}
