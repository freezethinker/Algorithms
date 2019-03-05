import java.io.*;
import java.util.*;

import com.sun.org.apache.xpath.internal.SourceTree;

class Graph {

    private int V;
    private LinkedList[] adjacencyList;

    Graph(int v) {
        V = v;
        adjacencyList = new LinkedList[v];
        for(int i = 0; i < v; i++) {
            adjacencyList[i] = new LinkedList();
        }
    }

    void addEdge(int x, int y) {
        adjacencyList[x].add(y);
    }

    void BFS(int s) {

        LinkedList<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[V];

        visited[s] = true;
        q.add(s);

        while (q.size() > 0) {
            s = q.poll();
            System.out.print(s + " ");
            LinkedList<Integer> thisAdj = adjacencyList[s];
            for(Iterator<Integer> i = thisAdj.listIterator(); i.hasNext(); ) {
                int num = i.next();
                if(!visited[num]) {
                    visited[num] = true;
                    q.add(num);
                }
            }
        }

    }

    public static void main(String args[]) {

        Graph g = new Graph(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("BFS of Graph is: ");
        g.BFS(2);

    }
}