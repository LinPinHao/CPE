#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
class DSU {
    vector<int> Group;
public:
    DSU(int n) {
        Group.resize(n);
        for (int i = 0; i < n; i++)
            Group[i] = i;
    }
    int Find(int x) {
        if (Group[x] == x)
            return x;
        Group[x] = Find(Group[x]);
        return Group[x];
    }
    void Union(int x, int y) {
        Group[Find(x)] = Find(y);
    }
};
int main() {
    int n, m, u, v;
    string inp;
    while (cin >> n >> m) {
        int deg[n] = {};
        DSU dsu(n);
        for (int i = 0; i < m; i++) {
            cin >> inp;
            for (auto &c: inp) {
                if (c < '0' || c > '9')
                    c = ' ';
            }
            stringstream ss(inp);
            ss >> u; ss >> v;
            deg[u]++; deg[v]++;
            dsu.Union(u, v);
        }

        if (!n || m == n*(n-1)/2) {
            cout << n << endl;
            continue;
        }

        set<int> S;
        for (int i = 0; i < n; i++)
            S.insert(dsu.Find(i));

        if (S.size() > 1) cout << 0 << endl;
        else cout << *min_element(deg, deg+n) << endl;
    }
}