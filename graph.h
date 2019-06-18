/* Nikolay Nikolov
   CS163 
Instructor : Karla Fant
Program # 5

Purpose of the program :
The purpose of the program is using Adjacency List to link goals in graph, display the adjacent , and display all depth first. And deallocate all.

This is the header file  where the ADT is :

*/
#include<iostream>
#include<cctype>

using namespace std;

struct entry // where data is stored
{
    entry ();
    ~entry ();
    char * goal;
    char * pre_requisite ;
    int copy( char * agoal);
    int display ();
};

struct vertex
{
    vertex ();
    ~vertex () ;
    entry * data ;
    struct node * head; 
};

struct node
{
    node();
    ~node();
    vertex * adjacent ;
    node * next ;

};

class graph 
{
    public:
        graph ( int size = 7);
        ~graph ();
        int insert_vertex (char * agoal);
        int copy (char *  agoal);
        int find_location(char * agoal);
        int insert_edge (int from, int to);
        int display_adjacent_wrapper(char * agoal);
        int display_adjacent(node * temp,int index);
        int dfs();
        int display_dfs( int index, bool * visited);


    private :
        int delete_all();
        vertex * adjacency_list;
        int list_size ;

};

