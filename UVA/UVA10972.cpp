//�w�ק�
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/* reference:
�Q�k: https://ppt.cc/fXERhx
Code: https://ppt.cc/fNsXNx
*/

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int n, m;      // input
int TIME;
int bcnt;      // bridge connected component ���ƶq
int dfn[1001]; // dfs �ɪ��Ǹ�
int low[1001]; // dfs �ɪ� low ��
vector<int> G[1001];

// ��X bridge connected component
void dfs(int u, int parent)
{
    dfn[u] = low[u] = ++TIME;

    for (auto& v : G[u])
    {
        if (dfn[v])
        {
            if (v != parent) low[u] = min(dfn[v], low[u]);
            continue;
        }

        dfs(v, u);
        low[u] = min(low[v], low[u]);

        // ���@�Ӿ��Abridge connected component ���ƶq�[�@
        if (low[v] > low[u]) ++bcnt;
    }
}

void solve()
{
    // �p�G��i�ϥ����N�O�@�� bridge connected component ( �S���� )�A�h���ݭn�s�W��
    if (bcnt == 1) { cout << 0 << '\n'; return; }

    // �C�@�� bridge connected component �s���쪺 bridge connected component �ƶq -> degree
    map<int, int> m;
    for (int u = 1; u <= n; ++u)
    {
        m[low[u]] += 0; // ��W�@�� bridge connected component -> degree = 0
        for (auto& v : G[u]) if (low[v] != low[u]) ++m[low[u]];
    }

    int alone = 0, leaves = 0;
    for (auto& [__, de] : m)
    {
        if (!de) ++alone;
        else if (de == 1) ++leaves;
    }

    cout << alone + (leaves + 1) / 2 << '\n';
}

int main()
{
    while (cin >> n >> m)
    {
        // init
        TIME = 0;
        bcnt = 0;
        fill(dfn, dfn + 1001, 0);
        fill(low, low + 1001, 0);
        fill(G, G + 1001, vector<int>());

        while (m--)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        // ��X bridge connected component ���ƶq
        for (int i = 1; i <= n; ++i)
        {
            if (!dfn[i])
            {
                dfs(i, -1);

                // ���@�ӳs�q�Ϩӻ��A�Y�S�����h�����O bridge connected component
                // �_�h�Y�Ϥ����@�Ӿ��A�h�Ϸ|�Q������� bridge connected component
                // �ҥH�o��ݭn�[�@
                ++bcnt;
            }
        }

        solve();
    }
}