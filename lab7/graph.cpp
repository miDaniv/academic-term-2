#include "graph.h"

#include <QDebug>
#include <iostream>

Graph::Graph(int size)
{
    m_size = size;
    m_data.resize(size);
    for (auto &v : m_data) {
        v.resize(size);
        v.fill(m_inf);
    }
    for (int i = 0; i < size; ++i)
        m_data[i][i] = 0;
}

Graph::Graph(QVector<QVector<int> > data)
{
    m_data = data;
    m_size = data.size();
}

void Graph::add(int from, int to, int value)
{
    m_data[from][to] = value;
}

void Graph::floydWarshall() const
{
    auto dist = m_data;
    QVector<QVector<int>> p_matrix(m_size);

    for (int i = 0; i < m_size; ++i) {
        p_matrix[i].resize(m_size, i);
        p_matrix[i][i] = 0;
    }

    for (int k = 0; k < m_size; k++) {
        for (int i = 0; i < m_size; i++) {
            for (int j = 0; j < m_size; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != m_inf && dist[i][k] != m_inf)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    p_matrix[i][j] = p_matrix[k][j];
                }
            }
        }
    }
    std::cout << "P matrix (+1 for output)" << std::endl;
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            std::cout << p_matrix[i][j] + (i == j ? 0 : 1) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "D matrix " << std::endl;
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (dist[i][j] == m_inf)
                std::cout << "INF ";
            else
                std::cout << dist[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

int Graph::minDistance(QVector<int> dist, QVector<bool> sptSet) const
{
    int min = m_inf;
    int min_index = 0;

    for (int vertex = 0; vertex < dist.size(); vertex++)
        if (!sptSet[vertex] && dist[vertex] <= min) {
            min = dist[vertex];
            min_index = vertex;
        }

    return min_index;
}

void Graph::dijkstra(int source, int destination) const
{
    QVector<int> distances(m_size, m_inf);
    QVector<bool> shortestPathSet(m_size, false);

    distances[source] = 0;
    for (int count = 0; count < m_size - 1; count++) {
        int u = minDistance(distances, shortestPathSet);
        shortestPathSet[u] = true;
        for (int v = 0; v < m_size; v++)
            if (!shortestPathSet[v] && m_data[u][v] != m_inf && distances[u] != m_inf
                    && distances[u] + m_data[u][v] < distances[v])
                distances[v] = distances[u] + m_data[u][v];
    }
    if (destination != -1) {
        std::cout << "Distance from "<< source << " to " << destination << " = " << distances[destination];
    } else {
        std::cout << "Distances from " << source << " = ";
        for (int dis : distances) {
            if (dis == m_inf)
                std::cout << "INF ";
            else
                std::cout << dis << " ";
        }
    }
    std::cout << std::endl;
}

void Graph::dijkstraWrapper() const
{
    for (int i = 0; i < m_size; ++i) {
        dijkstra(i);
    }
}

void Graph::clear()
{
    m_data.resize(m_size);
    for (auto &v : m_data) {
        v.resize(m_size);
        v.fill(m_inf);
    }
    for (int i = 0; i < m_size; ++i)
        m_data[i][i] = 0;
}

