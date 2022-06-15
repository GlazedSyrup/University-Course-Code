import java.util.*;

public class GraphDFS {
    private class Vertex {
        private String label;
        private List<Vertex> adjacencies;

        public Vertex(String label) {
            this.label = label;
            adjacencies = new ArrayList<>();
        }

        public String getLabel() { return this.label; }

        public void addAdjacency(Vertex other) {
            adjacencies.add(other);
        }

        public List<Vertex> getAdjacencies() { return adjacencies; }

        public int getDegree() {
            return adjacencies.size();
        }

        public String toString() { return label; }
    }

    private class Edge {
        private Vertex v1;
        private Vertex v2;

        public Edge(Vertex v1, Vertex v2) {
            this.v1 = v1;
            this.v2 = v2;
        }

        public Vertex getVertex1() { return v1; }
        public Vertex getVertex2() { return v2; }
    }

    private HashMap<String, Vertex> vertices;

    public GraphDFS(){
        vertices = new HashMap<>();
    }

    public void addVertex(String label){
        vertices.put(label, new Vertex(label));
    }

    public void addEdge(String v1Label, String v2Label){
        Vertex v1 = vertices.get(v1Label);
        Vertex v2 = vertices.get(v2Label);

        v1.addAdjacency(v2);
        v2.addAdjacency(v1);
    }

    public Vertex getVertex(String label){
        return vertices.get(label);
    }

    /*
    Below is where DFS code will be, above is ADT Graph code.
     */
    public Set<Vertex> visited;
    public Map<Vertex, Edge> discoveredEdges;

    public void dfs(String startLabel){
        //Label all vertices as unvisited
        visited = new HashSet<>();
        discoveredEdges = new HashMap<>();

        Vertex startVertex = vertices.get(startLabel);

        dfs(startVertex);
    }

    public void dfs(Vertex v){
        visited.add(v);

        List<Vertex> adjacencies = v.getAdjacencies();
        for (Vertex nextVertex : adjacencies){
            if (!visited.contains(nextVertex)){
                discoveredEdges.put(v, new Edge(v, nextVertex));
                //Now that we've discovered nextVertex, we can recursively move and explore from there..
                dfs(nextVertex);
            }
        }
    }

    public static void main(String[] args) {
        GraphDFS graph = new GraphDFS();

        graph.addVertex("A");
        graph.addVertex("B");
        graph.addVertex("C");
        graph.addVertex("D");
        graph.addVertex("E");
        graph.addVertex("F");

        graph.addEdge("A","B");
        graph.addEdge("C","D");
        graph.addEdge("F","E");
        graph.addEdge("B","F");
        graph.addEdge("A","C");
        graph.addEdge("D","B");
        graph.addEdge("C","F");

        Vertex d = graph.getVertex("D");
        System.out.printf("Degree of D: %d\n", d.getDegree());
        List<Vertex> adjacencies = d.getAdjacencies();
        System.out.println("Adjacencies of D:");
        for (Vertex adja : adjacencies){
            System.out.printf("\t%s, adjacencies:\n", adja.getLabel());

            for (Vertex subadj: adja.getAdjacencies()){
                System.out.printf("\t\t%s, adjacencies:\n", subadj.getLabel());
            }
            System.out.println("");
        }

        graph.dfs("D");
        System.out.println("Visited verticies:");
        for (Vertex visit : graph.visited){
            System.out.printf("\t%s\n", visit.getLabel());
        }

        System.out.println("Discovered Edges: ");
        for (Vertex v : graph.discoveredEdges.keySet()){
            Edge edge = graph.discoveredEdges.get(v);
            System.out.printf("\t Vertex %s, discovered by edge (%s, %s)\n", v.toString(),
                    edge.getVertex1().toString(), edge.getVertex2().toString());
        }
    }

}