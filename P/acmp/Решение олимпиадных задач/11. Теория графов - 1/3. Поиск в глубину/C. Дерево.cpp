/*
* ------------ ДЕРЕВО ------------
& поиск в глубину
~ dfs_проверка_на_принадлежность_к_классу_деревьев
? Просто проверка на принадлежность к классу деревьев
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <map>
#include <set>
 
#define all(a) a.begin(), a.end()
 
using namespace std;
 
using line = vector <int>;
using matrix = vector <line>;
 
int n;
line used;
matrix d;
 
void dfs(int curr) {
    used[curr] = true;
 
    for (auto next : d[curr]) {
        if (!used[next]) {
            dfs(next);
        }
    }
}
 
bool isTree(const matrix& d) {
    int amount(0);
 
    for (const auto& i : d) 
        amount += i.size();
     
    amount /= 2; // для неориентированного графа
 
    dfs(0);
 
    return count(used.begin(), used.end(), 0) == 0 && amount == n - 1;
}
 
int main() {
    // ...
    ios::sync_with_stdio(false);
    cin >> n;
 
    d.resize(n);
    used.resize(n);
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            int v;
            cin >> v;
 
            if (v)
                d[i].push_back(j);
 
        }
    }
 
    cout << (isTree(d) ? "YES" : "NO");
 
    return 0;
}