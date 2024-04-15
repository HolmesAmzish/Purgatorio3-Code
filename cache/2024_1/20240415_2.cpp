#include <cstdio>
using namespace std;

const int Maxn = 1000;
int cnt = 0;
struct treeNode
{
    char c;
    int left, right;
} btTree[Maxn];

void addNode(char c, int left, int right)
{
    btTree[++cnt] = {c, left, right};
}

void query(int x, int pa, char c)
{
    if (x == 0)
        return;
    treeNode tmp = btTree[x];

    if (tmp.c != c)
    {
        query(tmp.left, x, c);
        query(tmp.right, x, c);
    }
    else
    {
        if (pa == 0)
            printf("NO PARENT\n");
        else
            printf("%c\n", btTree[pa].c);
        if (tmp.left == 0)
            printf("no lchild\n");
        else
            printf("%c\n", btTree[tmp.left].c);
        if (tmp.right == 0)
            printf("no rchild\n");
        else
            printf("%c\n", btTree[tmp.right].c);
    }
}

void deleteTree(int i)
{
    if (i == 0)
        return;
    deleteTree(btTree[i].left);
    deleteTree(btTree[i].right);
    btTree[i].c = 0;
}

void outputTree()
{
    if (cnt == 0)
    {
        printf("ERROR\n");
        return;
    }
    for (int i = 1; i <= cnt; ++i)
    {
        printf("%c %d %d\n", btTree[i].c, btTree[i].left, btTree[i].right);
    }
}

int main()
{
    char c;
    while ((c = getchar()) != '#')
    {
        int x, y;
        scanf("%d%d", &x, &y);
        getchar();
        addNode(c, x, y);
    }

    scanf("%c", &c);
    while (c < 'A' || c > 'Z')
    {
        scanf("%c", &c);
    }
    query(1, 0, c);

    scanf("%c", &c);
    while (c < 'A' || c > 'Z')
    {
        scanf("%c", &c);
    }
    int flag = 0;
    for (int i = 1; i <= cnt; ++i)
    {
        if (btTree[i].c == c)
        {
            deleteTree(i);
            flag = 1;
        }
    }
    if (flag == 1)
    {

        int k = 0;
        int newcnt = 0;
        for (int i = 1; i <= cnt; ++i)
        {
            if (btTree[i].c != 0)
            {
                btTree[++k] = btTree[i];
                newcnt++;
                for (int j = 1; j <= cnt; ++j)
                {
                    btTree[j].left = btTree[j].left == i ? k : btTree[j].left;
                    btTree[j].right = btTree[j].right == i ? k : btTree[j].right;
                }
            }
            else
            {
                for (int j = 1; j <= cnt; ++j)
                {
                    btTree[j].left = btTree[j].left == i ? 0 : btTree[j].left;
                    btTree[j].right = btTree[j].right == i ? 0 : btTree[j].right;
                }
            }
        }
        cnt = newcnt;

        outputTree();
    }
    else
        printf("ERROR\n");
    return 0;
}
