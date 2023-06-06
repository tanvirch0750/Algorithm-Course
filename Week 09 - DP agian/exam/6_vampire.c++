#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, unordered_set<int>& vampires, unordered_set<int>& lykans) {
    if (vampires.count(node))
        vampires.erase(node);
    else if (lykans.count(node))
        lykans.erase(node);

    for (int neighbor : graph[node]) {
        if (vampires.count(neighbor))
            vampires.erase(neighbor);
        else if (lykans.count(neighbor))
            lykans.erase(neighbor);

        dfs(neighbor, graph, vampires, lykans);
    }
}

int main() {
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n;
        cin >> n;

        vector<vector<int>> graph(20001);
        unordered_set<int> vampires;
        unordered_set<int> lykans;

        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);

            vampires.insert(u);
            lykans.insert(v);
        }

        int maxIndividuals = 0;

        for (int i = 1; i <= 20000; i++) {
            if (vampires.count(i) || lykans.count(i)) {
                maxIndividuals++;
                dfs(i, graph, vampires, lykans);
            }
        }

        cout << "Case " << caseNum << ": " << maxIndividuals << endl;
    }

    return 0;
}
