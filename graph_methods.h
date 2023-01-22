typedef struct _edge
{
    Node* target; // Destination node of this edge.
    int weight; // Cost of moving towards target.
    Edge* next_edge;

} Edge;

typedef struct _node
{
    int number; // Numeric value for identification.
    Node* next_node;
    Edge* head; // First edge in a list of edges that belong to this node.

} Node;

typedef struct _graph
{
    Node* head; // First node in a list of nodes which this graph consists of.
    int size; // Amount of nodes in graph.

} Graph;

char* read_user_input();

/**
 * Params:
 * - Values for setting member variables.
 * 
 * Functionality:
 * - Constructs a new edge by setting member variables
 *   to parameter values.
 * 
 * Return:
 * - Pointer to the newly constructed Edge variable.
*/
Edge* construct_edge(int weight, Node* target);

/**
 * Params:
 * - Values for setting member variables.
 * 
 * Functionality:
 * - Constructs a node by setting member variables.
 * 
 * Return:
 * - Void, since structure object will be updated automatically
 *   via reference to memory.
*/
Node* construct_node(int number);

/**
 * Params:
 * - Values for setting member variables.
 * 
 * Functionality:
 * - Constructs a graph by setting member variables.
 * 
 * Return:
 * - Void, since structure object will be updated automatically
 *   via reference to memory.
*/
Graph* construct_graph(int size);

/**
 * Paramaters:
 * - Pointer to a Graph variable which represents our graph.
 * 
 * Functionality:
 * - Recieves user input for total nodes and different weights.
 * - Creates a graph based on that information.
 * 
 * Return:
 * - Next operation to be performed.
*/
char create_graph(Graph* p_graph);

/**
 * Params:
 * - Pointer to a Graph variable which represents our graph.
 * 
 * Functionality:
 * - Builds default nodes for a new graph.
 * 
 * Return:
 * - Void. No need a return type since graph is updated 
 *   directly and automatically.
*/
void build_nodes(Graph* p_graph);

/**
 * Params:
 * - Pointer to a Graph variable which represents our graph.
 * - Pointer to a node in the graph.
 * 
 * Functionality:
 * - Builds default edges for a node in the graph.
 *   Each edge will have a weight of -1 as default.
 *   This indicates that the edge is yet to exist.
 * 
 * Return:
 * - Void. No need a return type since node is updated 
 *   directly and automatically.
*/
void build_edges(Graph* p_graph, Node* p_node);

/**
 * Params:
 * - Node to which the edge shall be added.
 * - New edge to add.
 * 
 * Functionality:
 * - Adds a new edge to a node in the graph.
 * 
 * Return:
 * - Void. No need a return type since node is updated 
 *   directly and automatically.
*/
void add_edge(Node* this_node, Edge* new_edge);

/**
 * Parameters:
 * - Pointer to a Graph variable which represents our graph.
 * 
 * Functionality:
 * - Recieves user input for node number and different weights.
 * - Modifies the graph based on that information.
 * 
 * Return:
 * - Next operation to be performed.
*/
char add_node(Graph* this);

/**
 * Parameters:
 * - Pointer to a Graph variable which represents our graph.
 * 
 * Functionality:
 * - Recieves user input for node number and deletes that node completly.
 * - Every edge related to this node is also erased from graph.
 * 
 * Return:
 * - Void. No need a return type since graph is updated 
 *   directly and automatically.
*/
char remove_node(Graph* this);

/**
 * Params:
 * - Pointer to a Graph variable which represents our graph.
 * - Number of node to be found.
 * 
 * Functionality:
 * - Searches graph nodes for a specific node.
 * 
 * Return:
 * - Pointer to the node with given number.
 *      If such node doesn't exist, return NULL.
*/
Node* find_node(Graph* this, int number);

/**
 * Prints graph nodes and edges of each node.
*/
void print_graph(Graph*);

/**
 * Parameters:
 * - Pointer to a Graph variable which represents our graph.
 * 
 * Functionality:
 * - Recieves user input for two nodes.
 * - Calculates shortest path from first node to second.
 * 
 * Return:
 * - Integer representing shortest path.
 * - If no path exists, return -1.
*/
int get_shortest_path(Graph* this);

/**
 * Parameters:
 * - Pointer to a Graph variable which represents our graph.
 * 
 * Functionality:
 * - Recieves user input for:
 * - 1. An amount of nodes.
 * - 2. Nodes (numbers) themselves (of specified amount).
 * - Calculates shortest path possible between nodes.
 * 
 * Return:
 * - Integer representing shortest path.
 * - If no such path exists, return -1.
*/
int travelling_agent(Graph* this);
