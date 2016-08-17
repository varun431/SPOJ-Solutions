#include <bits/stdc++.h>
using namespace std;

class HashList
{
    final int SIZE = 1000000;
    int[] heads;
    long[] data = new long[SIZE];
    boolean[] used = new boolean[SIZE];
    int[] next = new int[SIZE];
    HashList(int n)
    {
        heads = new int[n];
        Arrays.fill(heads,-1);
    }
    // adds new edge (x, y)
    boolean add(int x, int y)
    {
        long code = code(x, y);
        int hash = hash(x, y);
        while (used[hash])
            if (data[hash] == code)
                return false;
            else
                hash = (hash + 1) % SIZE;
        data[hash] = code;
        used[hash] = true;
        next[hash] = heads[x];
        heads[x] = hash;
        return true;
    }
    // returns true if edge (x, y) is contained in the graph
    boolean contains(int x, int y)
    {
        long code = code(x, y);
        int hash = hash(x, y);
        while (used[hash])
            if (data[hash] == code)
                return true;
            else
                hash = (hash + 1) % SIZE;
        return false;
    }
    // enumerates the vertices adjacent to x
    void enumerate(int x)
    {
        for (int i = heads[x]; i != -1; i = next[i])
        {
            int y = (int) data[i];
            // do something with y
        }
    }
    // returns hash code for edge (x, y)
    int hash(int x, int y)
    {
        return Math.abs((x + 111111) * (y-33333) % SIZE);
    }
    // converts pair (x, y) to single integer value
    long code(int x, int y)
    {
        return ((1L * x) << 32) | y;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
    }
}
