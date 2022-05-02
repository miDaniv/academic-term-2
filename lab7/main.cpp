#include <QCoreApplication>

#include "graph.h"

#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Input size or -1 to use graph 1(dijkstra) or -2 for graph 2(floyd)" << std::endl;
    int key;
    cin >> key;
    Graph *graph;
    if (key > 0) {
        graph = new Graph(key);
        while (true) {
            std::cout << "Input the edges of the graph + value or -1 to stop" << endl;
            int from;
            cin >> from;
            if (from == -1) break;
            int to, value;
            cin >> to >> value;
            graph->add(from, to, value);
        }
    } else if (key == -1) {
        graph = new Graph(7);
        graph->add(0, 1, 1);
        graph->add(0, 2, 5);
        graph->add(1, 2, 3);
        graph->add(1, 4, 2);
        graph->add(1, 5, 8);
        graph->add(1, 6, 20);
        graph->add(2, 5, 4);
        graph->add(3, 2, 9);
        graph->add(5, 6, 7);
    } else if (key == -2) {
        graph = new Graph(6);
        graph->add(0, 1, 1);
        graph->add(0, 2, 6);
        graph->add(1, 2, 4);
        graph->add(1, 4, -2);
        graph->add(2, 4, 5);
        graph->add(2, 5, 3);
        graph->add(3, 0, 2);
        graph->add(3, 4, -5);
        graph->add(4, 3, 8);
        graph->add(4, 5, 4);
    }

    while (true) {
        std::cout << "Input the algorihtm key(d - dijkstra, f - floydWarshall, q for exit" << std::endl;
        string key;
        cin >> key;
        if (key == "q")
            break;
        else if (key == "f")
            graph->floydWarshall();
        else if (key == "d") {
            cout << "Input -1 for show path from all points, source and destination(-1 to skip) " << std::endl;
            int source;
            cin >> source;

            if(source == -1)
                graph->dijkstraWrapper();
            else {
                int dest;
                cin >> dest;
                graph->dijkstra(source, dest);
            }
        }
    }
    return a.exec();
}
