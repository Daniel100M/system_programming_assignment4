#include <stdio.h>
#include <stdlib.h>
#include "graph_methods.h"

int main(){

    char* user_input = read_user_input();

    Graph* p_graph = NULL; // This will be our graph.

    char operation; // Determines which action to perform.
    operation = user_input[0];

    while (operation != '\n'){

        switch (operation){

            case 'A':
                operation = create_graph(p_graph);
            break;

            case 'B':
                operation = add_node(p_graph);
            break;

            case 'D':
                operation = remove_node(p_graph);
            break;

            case 'S':

            break;

            case 'T':

            break;
        }

    }

    return 0;
}