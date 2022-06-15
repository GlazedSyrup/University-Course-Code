import java.util.*;

public class AdjacencyListGraph {
    private Map<String, Vertex> verticies;

    // Helper Vertex Class for our adjacency list
    private class Vertex {
        private String label;
        private Collection<Vertex> adjacencies;

        public Vertex(String label) {
            this.label = label;
            this.adjacencies = new ArrayList<>();
        }

        public String getLabel() {return this.label;}

        public void addAdjacency(Vertex other) {this.adjacencies.add(other); }

        public Collection<Vertex> getAdjacencies() {return this.adjacencies; }

        public int getDegree() {
            return this.adjacencies.size();
        }

        public String toString() {return this.label;}
    }
    public AdjacencyListGraph() {
        this.verticies = new HashMap<>();
    }

    public void addVertex(String label){
        this.verticies.put(label, new Vertex(label));
    }

    public void addEdge(String endPoint1, String endPoint2){
        Vertex eP1 = this.verticies.get(endPoint1);
        Vertex eP2 = this.verticies.get(endPoint2);

        eP1.addAdjacency(eP2);
        eP2.addAdjacency(eP1);
    }

    public Vertex getVertex(String label){
        return this.verticies.get(label);
    }

    public static void main(String[] args) {
         AdjacencyListGraph graph = new AdjacencyListGraph();

         graph.addVertex("A");
         graph.addVertex("B");
         graph.addVertex("C");
         graph.addVertex("D");
         graph.addVertex("E");
         graph.addVertex("F");

         graph.addEdge("A", "B");
         graph.addEdge("A", "C");
         graph.addEdge("B", "D");
         graph.addEdge("B", "E");
         graph.addEdge("C", "D");
         graph.addEdge("D", "E");
         graph.addEdge("A", "F");

         Vertex d = graph.getVertex("D");
         System.out.printf("Degree of D: %d\n", d.getDegree());

         Collection<Vertex> adjacencies = d.getAdjacencies();
         for (Vertex v: adjacencies){
             System.out.println(v);
         }
    }
}