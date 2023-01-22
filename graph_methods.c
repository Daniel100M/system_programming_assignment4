#include <stdio.h>
#include <stdlib.h>
#include "graph_methods.h" // Allows usage of declared structures.

char* read_user_input(){

    int size = 1000;
    char* user_input = (char*) malloc(size);
    user_input[size-1] = '\0';

    for (size_t i = 0; i < size; i++)
    {   
        if (user_input[i] == '\0'){
            // Reached end of string.
            // Increasing size.
            size *= 10;
            user_input = (char*) realloc(user_input, size);
            user_input[size-1] = '\0';
        }
        scanf("%c", &user_input[i]);
    }
    
    return user_input;
}

Edge* construct_edge(int weight, Node* target){

    Edge* p_edge = (Edge*) malloc(sizeof(Edge));

    p_edge->weight = weight;
    p_edge->target = target;
    p_edge->next_edge = NULL;

    return p_edge;
}

Node* construct_node(int number){

    Node* p_node = (Node*) malloc(sizeof(Node));

    p_node->number = number;
    p_node->head = NULL;
    p_node->next_node = NULL;

    return p_node;
}

Graph* construct_graph(int size){

    Graph* p_graph = (Graph*) malloc(sizeof(Graph));

    p_graph->size = size;
    p_graph->head = NULL;

    return p_graph;
}

void build_edges(Graph* p_graph, Node* p_node){

    int amount = p_graph->size; // Amount of edges to build.

    Edge* temp;
    Node* iterator = p_node;

    for (size_t i = 0; i < amount; i++)
    {
        temp = construct_edge(-1, iterator);
        temp->next_edge = p_node->head;
        p_node->head = temp;

        iterator = iterator->next_node;
    }
    
}

void build_nodes(Graph* p_graph){

    // Adding nodes to graph based on size.

    Node* temp;
    for (size_t i = p_graph->size -1; i >= 0; i--)
    {
        temp = construct_node(i); // Constructing a new node.
        temp->next_node = p_graph->head;
        p_graph->head = temp;

        build_edges(p_graph, p_graph->head);
    }
    
}


char create_graph(Graph* p_graph){

    // Used to read user input.
    char char_input;
    int num_input;

    scanf("%c", &char_input); // Read space ' '.
    scanf("%d", &num_input); // Read amount of nodes in graph.

    p_graph = construct_graph(num_input);

    scanf("%c", &char_input); // Read space ' '.
    scanf("%c", &char_input); // Read next operation.

    build_nodes(p_graph);

    if (char_input == 'n') return 'B';
    return char_input;
}

Node* find_node(Graph* p_graph, int number){

    Node* iterator = p_graph->head; // To iterate over graph nodes.
    while (iterator != NULL)
    {
        if (iterator->number == number) return iterator;
        iterator = iterator->next_node;
    }
    return NULL;
}

char add_node(Graph* p_graph){
    
    // Used to read user input.
    char char_input;
    int num_input;

    scanf("%c", &char_input); // Read space ' '.
    scanf("%d", &num_input); // Read source node.

    while (char_input == ' '){

        scanf("%c", &char_input); // Read space ' '.
        scanf("%d", &num_input); // Read source node.
    }

    if (char_input == 'n') return 'B';
    return char_input;
}

