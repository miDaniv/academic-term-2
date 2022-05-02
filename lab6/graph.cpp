#include "graph.h"

#include <QStack>
#include <QQueue>
#include <QDebug>

Graph::Graph(int size) : m_size(size)
{}

void Graph::addVertex(int from, int to)
{
    m_data.insert(from, to);
    m_data.insert(to, from);
}

void Graph::dfs(int start_point)
{
    QVector <bool> visited(m_size, false);
    QVector <int> dfsNumbers(m_size, 0);
    QStack<int> dfs_stack;
    QVector<QPair<int, int>> cascade;

    int dfsStep = 1;
    visited[start_point] = true;
    dfsNumbers[start_point] = dfsStep;
    dfs_stack.push(start_point);

    while (!dfs_stack.isEmpty()) {
        qDebug() << dfs_stack;
        QList<int> neighboring_points = m_data.values(dfs_stack.top());
        std::sort(neighboring_points.begin(), neighboring_points.end());
        bool visitedCondition = false;
        for (int point : neighboring_points) {
            if (!visited.at(point)) {
                cascade.push_back({dfs_stack.top(), point});
                visited[point] = true;
                dfsNumbers[point] = ++dfsStep;
                dfs_stack.push(point);
                visitedCondition = true;
                break;
            }
        }
        if (!visitedCondition) dfs_stack.pop();
    }

    for (int i = 0; i < dfsNumbers.size(); ++i) {
        qDebug() << "Vertex (" << i << "), number - " << dfsNumbers.at(i);
    }

    for (auto a : cascade)
        qDebug() <<"Cascade (key - value)" << a.first << " - " << a.second;
}

void Graph::bfs(int start_point)
{
    QVector<bool> visited(m_size, false);
    QVector<int> bfsNumbers(m_size, 0);
    QQueue<int> bfsQueue;
    QVector<QPair<int, int>> cascade;

    int bfsStep = 1;
    visited[start_point] = true;
    bfsNumbers[start_point] = bfsStep;
    bfsQueue.enqueue(start_point);

    while (!bfsQueue.isEmpty()) {
        qDebug() << bfsQueue;
        QList<int> neighboring_points = m_data.values(bfsQueue.front());
        std::sort(neighboring_points.begin(), neighboring_points.end());
        bool visitedCondition = false;
        for (int point : neighboring_points) {
            if (!visited.at(point)) {
                cascade.push_back({bfsQueue.front(), point});
                visited[point] = true;
                bfsNumbers[point] = ++bfsStep;
                bfsQueue.enqueue(point);
                visitedCondition = true;
                break;
            }
        }
        if (!visitedCondition) bfsQueue.dequeue();
    }

    for (int i = 0; i < bfsNumbers.size(); ++i) {
        qDebug() << "Vertex (" << i << "), number - " << bfsNumbers.at(i);
    }

    for (auto a : cascade)
        qDebug() <<"Cascade (key - value)" << a.first << " - " << a.second;
}

void Graph::dfs_recursive(int start_point, bool printResult)
{
    static QVector <bool> visited(m_size, false);
    static QVector <int> dfsNumbers(m_size, 0);
    static QVector <QPair<int, int>> cascade;
    static int dfsStep = 0;

    visited[start_point] = true;
    dfsNumbers[start_point] = ++dfsStep;

    QList<int> neighboring_points = m_data.values(start_point);
    std::sort(neighboring_points.begin(), neighboring_points.end());
    for (int point : neighboring_points) {
        if (!visited.at(point)) {
            cascade.push_back({start_point, point});
            dfs_recursive(point, false);
        }
    }

    if (visited.indexOf(false) == -1 && printResult) {
        for (int i = 0; i < dfsNumbers.size(); ++i) {
            qDebug() << "Vertex (" << i << "), number - " << dfsNumbers.at(i);
        }

        for (auto a : cascade)
            qDebug() <<"Cascade (key - value)" << a.first << " - " << a.second;
        visited.clear();
        visited.resize(m_size, false);
        dfsNumbers.clear();
        dfsNumbers.resize(m_size, 0);
        cascade.clear();
        dfsStep = 0;
    }
}
