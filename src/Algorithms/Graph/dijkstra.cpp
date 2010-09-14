
#include <boost/config.hpp>
#include <iostream>
#include <limits.h>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost;
using namespace std;


typedef float weight_type;

typedef adjacency_list <  listS, 
                          vecS, 
                          undirectedS, // undirected
                          no_property, 
                          property < edge_weight_t, weight_type > 
                      > graph_t;
typedef shared_ptr<graph_t> graph_ptr;

typedef graph_traits < graph_t >::vertex_descriptor vertex_descriptor;
typedef graph_traits < graph_t >::edge_descriptor edge_descriptor;

typedef vector<weight_type>   weight_vec;
typedef pair<int,int> Edge; 
typedef vector<Edge>  Edge_vec;


class PathInfo {
public:
  vector<vertex_descriptor> previous;
  vector<weight_type>       distance;
};


//----------------------------------------------------------------
graph_ptr CreateUndirectedGraph(
//        ---------------------
                      int         num_nodes, 
                      const Edge_vec&    edges,
                      const weight_vec&  weights
                     )
{
  if (weights.size()!=edges.size()) {
    std::cerr << "ShortestPath() \t edges and weights have different sizes, aborting ..." << std::endl;
    return graph_ptr();
  }

  int num_arcs = edges.size();

  graph_ptr g = graph_ptr(new graph_t(num_nodes));

  property_map<graph_t, edge_weight_t>::type weightmap = get(edge_weight, *g);
  for (std::size_t j = 0; j < num_arcs; ++j) {
    edge_descriptor e; 
    bool inserted;
    tie(e, inserted) = add_edge(edges[j].first, edges[j].second, *g);
    weightmap[e] = weights[j];
  }
  return g;
}


//----------------------------------------------------------------
void ShortestPath(
//   ------------
                    const graph_t& g,
                    int         starting_vertex_number,
                    PathInfo&   result 
                  )
{

  result.previous.resize(num_vertices(g));
  result.distance.resize(num_vertices(g));

  // starting for vertex 0
  vertex_descriptor s = vertex(starting_vertex_number, g);

  // VC++ has trouble with the named parameters mechanism
  property_map<graph_t, vertex_index_t>::type indexmap = get(vertex_index, g);
  dijkstra_shortest_paths(g, s, 
      predecessor_map(
        make_iterator_property_map( result.previous.begin(), 
                                    get(vertex_index, g))).
      distance_map(
        make_iterator_property_map( result.distance.begin(), 
                                    get(vertex_index, g))));

/* print result
  char name[] = "ABCDE";
  std::cout << "distances and parents:" << std::endl;
  graph_traits < graph_t >::vertex_iterator vi, vend;
  for (tie(vi, vend) = vertices(g); vi != vend; ++vi) {
    std::cout << "distance(" << name[*vi] << ") = " << result.distance[*vi] << ", ";
    std::cout << "parent(" << name[*vi] << ") = " << name[result.previous[*vi]] << std::
      std::endl;
  }
  std::cout << std::endl;
*/
}

/*
int
main(int, char *[])
{

  const int num_nodes = 5;
  enum nodes { A, B, C, D, E };
  char name[] = "ABCDE";
  Edge edge_array[] = { Edge(A, C), Edge(B, B), Edge(B, D), Edge(B, E),
    Edge(C, B), Edge(C, D), Edge(D, E), Edge(E, A), Edge(E, B)
  };
  weight_type weight_array[] = { 1.2, 2, 1, 2.3, 7, 3, 1, 1, 1 };

  int num_arcs = sizeof(edge_array) / sizeof(Edge);
  Edge_vec edges = Edge_vec(&edge_array[0], &edge_array[0]+num_arcs);
  weight_vec weights = weight_vec(&weight_array[0], &weight_array[0]+num_arcs);


  PathInfo res;
  
  graph_ptr g = CreateGraph(num_nodes, edges,weights);
  if (g.use_count()) ShortestPath(*g,0,res);

  return EXIT_SUCCESS;
}
*/
