#define _CRT_SECURE_NO_WARNINGS 1 

#include<iostream>
#include<vector>

using namespace std;

int dfs(int x, int parent, vector<vector<pair<int, int>>>& e) {
    int res = 0;
    for (auto& edge : e[x]) {
        if (edge.first == parent) {
            continue;
        }
        res += edge.second + dfs(edge.first, x, e);
    }
    return res;
}

int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, int>>> e(n);
    for (auto edge : connections) {
        e[edge[0]].push_back(make_pair(edge[1], 1));
        e[edge[1]].push_back(make_pair(edge[0], 0));
    }
    return dfs(0, -1, e);
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    // 生成存储变量所构成的图结构
    unordered_map<string, unordered_map<string, double>> graph;
    int n = equations.size();
    for (int i = 0; i < n; i++) {
        string s = equations[i][0], e = equations[i][1];
        double v = values[i];
        graph[s][e] = v;     // 生成一条s指向e，权重为v的路径，表示 s / e = v
        graph[e][s] = 1 / v; // 生成一条反向路径，权重为1 / v，表示 e / s = 1 /v
        graph[s][s] = 1.0;   // 生成一个指向自己、权重为1的路径，表示自己除自己等于1
        graph[e][e] = 1.0;
    }

    queue<pair<string, double>> q;          // 用于广度优先搜索的队列
    int m = queries.size();
    vector<double> ans(m, -1.0);    // 答案列表，初始都为-1表示未定义

    // 对于每个query，寻找从起点qx到终点qy的最短路径，并计算权重积
    for (int i = 0; i < m; i++) {
        string qx = queries[i][0], qy = queries[i][1];
        if (graph.find(qx) == graph.end() || graph.find(qy) == graph.end())continue;  // 未出现的变量，跳过处理
        q.emplace(qx, 1.0);     // 初始将起点节点入队
        unordered_set<string> visited{ qx };     // 存储已处理的节点；将qx放入列表表示存储整个字符串，否则会将字符串看成一个序列存储每个字母
        while (!q.empty()) {
            string node = q.front().first;    // 获取当前处理的节点node以及到该节点所得到的权重积mul
            double mul = q.front().second;
            q.pop();
            for (pair<string, double> neighbor : graph[node]) {
                string ngh = neighbor.first;
                double weight = neighbor.second;
                // 枚举该节点的所有邻节点
                if (ngh == qy) {
                    ans[i] = mul * weight;   // 找到终点，更新权重积后存储到答案并退出查找
                    break;
                }
                if (visited.find(ngh) == visited.end()) { // 找到一个未处理的邻节点加入队列
                    visited.emplace(ngh);
                    q.emplace(ngh, mul * weight);  // 将未处理的邻节点及到达该节点时的权重积加入队列
                }
            }
        }
    }
    return ans;
}

int main()
{

	return 0;
}