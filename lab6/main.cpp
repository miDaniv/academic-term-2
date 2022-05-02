#include <QCoreApplication>

#include "graph.h"

#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Input size or 0(zero) to use predefined graph";
    int key;
    cin >> key;
    Graph *graph;
    if (key > 0) {
        graph = new Graph(key);
        while (true) {
            qDebug() << "Input the edges of the graph or -1 to stop";
            int from;
            cin >> from;
            if (from == -1) break;
            int to;
            cin >> to;
            graph->addVertex(from, to);
        }
    } else {
        graph = new Graph(8);
        graph->addVertex(0, 1);
        graph->addVertex(0, 2);
        graph->addVertex(0, 3);
        graph->addVertex(0, 6);
        graph->addVertex(0, 7);
        graph->addVertex(1, 6);
        graph->addVertex(1, 7);
        graph->addVertex(3, 4);
        graph->addVertex(3, 5);
        graph->addVertex(4, 5);
        graph->addVertex(6, 7);
    }

    while (true) {
        qDebug() << "Input the algorihtm key(d - dfs, b - bfs, dr - dfs recursive) or q for exit";
        string key;
        cin >> key;
        if (key == "q")
            break;
        qDebug() << "Input start point";
        int start_point;
        cin >> start_point;

        if (key == "d")
            graph->dfs(start_point);
        else if (key == "b")
            graph->bfs(start_point);
        else if ("key == dr")
            graph->dfs_recursive(start_point);
    }

    return a.exec();
}
