#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size(), num = 0;
    vector<int> vis(n);
    queue<int> que;
    vis[0] = true;
    que.emplace(0);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        num++;
        for (auto& it : rooms[x]) {
            if (!vis[it]) {
                vis[it] = true;
                que.emplace(it);
            }
        }
    }
    return num == n;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int cities = isConnected.size();
    vector<int> visited(cities);
    int provinces = 0;
    queue<int> Q;
    for (int i = 0; i < cities; i++) {
        if (!visited[i]) {
            Q.push(i);
            while (!Q.empty()) {
                int j = Q.front(); Q.pop();
                visited[j] = 1;
                for (int k = 0; k < cities; k++) {
                    if (isConnected[j][k] == 1 && !visited[k]) {
                        Q.push(k);
                    }
                }
            }
            provinces++;
        }
    }
    return provinces;
}

int main()
{

	return 0;
}

