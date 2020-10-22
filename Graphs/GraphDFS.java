import java.io.*;
import java.util.*;

public class GraphDFS {

    private int V;
    private LinkedList[] adjacencyList;
    private boolean[] visited;

    GraphDFS(int v) {
        V = v;
        adjacencyList = new LinkedList[v];
        visited = new boolean[V]; 
        for(int i = 0; i < v; i++) {
            adjacencyList[i] = new LinkedList();
            visited[i] = false;
        }
    }

    void addEdge(int x, int y) {
        adjacencyList[x].add(y);
    }

    void DFS(int s) {
        System.out.print(s + " ");
        visited[s] = true;
        LinkedList<Integer> thisAdj = adjacencyList[s];
        for(Iterator<Integer> i = thisAdj.listIterator(); i.hasNext(); ) {
            int num = i.next();
            if(!visited[num]) {
                DFS(num);
            }
        }
    }

    public static void main(String args[]) {

        GraphDFS g = new GraphDFS(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("DFS of Graph is: ");
        g.DFS(2);

    }
}
