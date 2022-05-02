#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <limits>

class Graph
{
public:
    Graph(int size);
    Graph(QVector<QVector<int>> data);

    void add(int from, int to, int value);

    void floydWarshall() const;

    int minDistance(QVector<int> dist, QVector<bool> sptSet) const;
    void dijkstra(int source, int destination = -1) const;
    void dijkstraWrapper() const;
    void clear();
private:
    int m_size;
    QVector<QVector<int>> m_data;
    int m_inf = std::numeric_limits<int>::max();
};

#endif // GRAPH_H
