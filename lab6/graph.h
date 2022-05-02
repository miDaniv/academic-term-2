#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QMultiMap>

class Graph
{
public:
    Graph(int size);
    void addVertex(int from, int to);

    void dfs(int start_point);
    void bfs(int start_point);
    void dfs_recursive(int start_point, bool printResult = true);

private:
    QMultiMap <int, int> m_data;
    int m_size;
};

#endif // GRAPH_H
