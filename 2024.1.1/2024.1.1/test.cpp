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
    // ���ɴ洢���������ɵ�ͼ�ṹ
    unordered_map<string, unordered_map<string, double>> graph;
    int n = equations.size();
    for (int i = 0; i < n; i++) {
        string s = equations[i][0], e = equations[i][1];
        double v = values[i];
        graph[s][e] = v;     // ����һ��sָ��e��Ȩ��Ϊv��·������ʾ s / e = v
        graph[e][s] = 1 / v; // ����һ������·����Ȩ��Ϊ1 / v����ʾ e / s = 1 /v
        graph[s][s] = 1.0;   // ����һ��ָ���Լ���Ȩ��Ϊ1��·������ʾ�Լ����Լ�����1
        graph[e][e] = 1.0;
    }

    queue<pair<string, double>> q;          // ���ڹ�����������Ķ���
    int m = queries.size();
    vector<double> ans(m, -1.0);    // ���б���ʼ��Ϊ-1��ʾδ����

    // ����ÿ��query��Ѱ�Ҵ����qx���յ�qy�����·����������Ȩ�ػ�
    for (int i = 0; i < m; i++) {
        string qx = queries[i][0], qy = queries[i][1];
        if (graph.find(qx) == graph.end() || graph.find(qy) == graph.end())continue;  // δ���ֵı�������������
        q.emplace(qx, 1.0);     // ��ʼ�����ڵ����
        unordered_set<string> visited{ qx };     // �洢�Ѵ���Ľڵ㣻��qx�����б��ʾ�洢�����ַ���������Ὣ�ַ�������һ�����д洢ÿ����ĸ
        while (!q.empty()) {
            string node = q.front().first;    // ��ȡ��ǰ����Ľڵ�node�Լ����ýڵ����õ���Ȩ�ػ�mul
            double mul = q.front().second;
            q.pop();
            for (pair<string, double> neighbor : graph[node]) {
                string ngh = neighbor.first;
                double weight = neighbor.second;
                // ö�ٸýڵ�������ڽڵ�
                if (ngh == qy) {
                    ans[i] = mul * weight;   // �ҵ��յ㣬����Ȩ�ػ���洢���𰸲��˳�����
                    break;
                }
                if (visited.find(ngh) == visited.end()) { // �ҵ�һ��δ������ڽڵ�������
                    visited.emplace(ngh);
                    q.emplace(ngh, mul * weight);  // ��δ������ڽڵ㼰����ýڵ�ʱ��Ȩ�ػ��������
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