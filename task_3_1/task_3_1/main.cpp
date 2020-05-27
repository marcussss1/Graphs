//
//  main.cpp
//  task_3_1
//
//  Created by Mac-HOME on 26.05.2020.
//  Copyright © 2020 Mac-HOME. All rights reserved.
//

/*
 Необходимо написать несколько реализаций интерфейса:
 ListGraph, хранящий граф в виде массива списков смежности,
 MatrixGraph, хранящий граф в виде матрицы смежности,
 SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев поиска,
 ArcGraph, хранящий граф в виде одного массива пар {from, to}.
 Также необходимо реализовать конструктор, принимающий const IGraph&.
 Такой конструктор должен скопировать переданный граф в создаваемый объект.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
using std::vector;
using std::queue;

#include "list_graph.hpp"
#include "matrix_graph.hpp"
#include "set_graph.hpp"
#include "arc_graph.hpp"

void BFS( const IGraph& graph, int vertex, void (*visit)(int) ) {
    vector<bool> visited( graph.VerticesCount(), false );
    queue<int> qu;
    qu.push( vertex );
    visited[vertex] = true;
    while( qu.size() > 0 ) {
        int current = qu.front();
        qu.pop();
        visit( current );
        vector<int> adjacentVertices = graph.GetNextVertices( current );
        for( int i = 0; i < adjacentVertices.size(); i++ ) {
            if( !visited[adjacentVertices[i]] ) {
                qu.push( adjacentVertices[i] );
                visited[adjacentVertices[i]] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ListGraph listg( 5 );
    listg.AddEdge( 0, 1 );
    listg.AddEdge( 1, 3 );
    listg.AddEdge( 2, 3 );
    listg.AddEdge( 3, 4 );
    listg.AddEdge( 3, 0 );
    listg.AddEdge( 4, 2 );

    BFS( listg, 0, []( int v ) { std::cout << v << " "; } );
    std::cout << "\n";
    
    MatrixGraph matrixg( 5 );
    matrixg.AddEdge( 0, 1 );
    matrixg.AddEdge( 1, 3 );
    matrixg.AddEdge( 2, 3 );
    matrixg.AddEdge( 3, 4 );
    matrixg.AddEdge( 3, 0 );
    matrixg.AddEdge( 4, 2 );

    BFS( matrixg, 0, []( int v ) { std::cout << v << " "; } );
    std::cout << "\n";
    
    SetGraph setg( 5 );
    setg.AddEdge( 0, 1 );
    setg.AddEdge( 1, 3 );
    setg.AddEdge( 2, 3 );
    setg.AddEdge( 3, 4 );
    setg.AddEdge( 3, 0 );
    setg.AddEdge( 4, 2 );

    BFS( setg, 0, []( int v ) { std::cout << v << " "; } );
    std::cout << "\n";
    
    ArcGraph arcg( 5 );
    arcg.AddEdge( 0, 1 );
    arcg.AddEdge( 1, 3 );
    arcg.AddEdge( 2, 3 );
    arcg.AddEdge( 3, 4 );
    arcg.AddEdge( 3, 0 );
    arcg.AddEdge( 4, 2 );

    BFS( arcg, 0, []( int v ) { std::cout << v << " "; } );
    
    return 0;
}
