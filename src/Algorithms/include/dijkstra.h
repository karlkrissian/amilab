
#ifndef _dijkstra_h_
#define _dijkstra_h_

#include <boost/config.hpp>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <limits.h>

#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost;
//using -- namespace std;


typedef float weight_type;

typedef adjacency_list <  listS, 
                          vecS, 
                          undirectedS,
                          no_property, 
                          property < edge_weight_t, weight_type > 
                      > graph_t;
typedef shared_ptr<graph_t> graph_ptr;

typedef graph_traits < graph_t >::vertex_descriptor vertex_descriptor;
typedef graph_traits < graph_t >::edge_descriptor edge_descriptor;

typedef std::vector<weight_type>   weight_vec;
typedef std::pair<int,int> Edge; 
typedef std::vector<Edge>  Edge_vec;


class PathInfo {
public:
  std::vector<vertex_descriptor> previous;
  std::vector<weight_type>       distance;
};


//----------------------------------------------------------------
graph_ptr CreateUndirectedGraph(
//        ---------------------
                      int         num_nodes, 
                      const Edge_vec  &  edges,
                      const weight_vec&  weights
                     );


//----------------------------------------------------------------
void ShortestPath(
//   ------------
                    const graph_t& g,
                    int         starting_vertex_number,
                    PathInfo&   result 
                  );


#endif // _dijkstra_h_
