/* Nikolay Nikolov
   CS163
Instructor: Karla Fant
Program # 5
Purpose of the program :




This is the .cpp file for the Graph ADT.


*/

#include"graph.h"
#include<cstring> 


entry :: entry ()// constructor
{
    goal = NULL;
    pre_requisite= NULL ;
}
entry :: ~entry ()
{
    if (goal)
        delete [] goal ;

    if (pre_requisite)
        delete [] pre_requisite ;

    goal = NULL ;
    pre_requisite = NULL ;

}
int entry :: display ()
{
    cout <<"\t\t\t  -> " << goal << " ; " ;
    cout <<endl;
}

//------------entry --------

vertex :: vertex ()
{
    head = NULL ;
    data = NULL;

}
vertex :: ~vertex () // destructor
{
    delete head; 
    head = NULL;
    delete data ;
    data = NULL;

}
//-----------------vertex

node :: node ()
{

    adjacent = NULL ;
    next = NULL ;
}

node :: ~node ()
{
    adjacent = NULL ; // it helps preventing leaks , not nessassary tho
    next = NULL ;
}
//---------------node 

graph :: graph ( int size ) // constructor
{

    list_size = size ;
    adjacency_list = new vertex [size]; // create an array of vertices , dynamically allocated of the size 
    for (int i = 0 ; i < size ; ++i)
    {
        adjacency_list[i].data = NULL ; // entry pointer
        adjacency_list[i].head = NULL ; // a head pointer for the adjacency list 
    }



}

graph :: ~graph()
{

    delete_all();// calling the delete function
    delete []adjacency_list; // delete the array
    adjacency_list = NULL; // set the array to NULL

}
int graph :: insert_vertex(char * agoal)
{

    int i = 0;
    vertex * current= NULL;; // vertex temporary object current  
    bool done = false ;

    while ( i < list_size  && !done) // loop through the array looking for non- null entry pointer
    {
        current  = adjacency_list + i; //count
        if (!current -> data)// if there is an empty slot with nothing inside
        {
            current ->data = new entry ;// create a new entry
            current -> data -> copy(agoal);// deep copy
            done = true; //create a flag that the slot is full

        }
        ++i; // increment 
    }
    if (done) // if there is not an  empty location
    {
        return 1;
    }

    return 0;

}


int entry  :: copy ( char * agoal)
{
    if (goal)
        delete []goal; // clean up memory and leaks

    goal = NULL ; // and avoid segfault

    if (agoal)
    {
        goal = new char [strlen(agoal)+1]; // copy into the entry object
        strcpy(goal,agoal);
    }

    return 0;


}

int graph ::  find_location(char * agoal)// 
{
    int i =0;
    bool done = false;
    //vertex * temp = adjacency_list;
    for (int i = 0; i < list_size; ++i) // for the size of the array
    {  
        if (adjacency_list[i].data && adjacency_list[i].data -> goal) // 

            if (strcmp(adjacency_list[i].data->goal,agoal)==0) // compare key value
            {
                return i;
            }


    }
    return -1 ;
}

int graph ::  insert_edge (int from, int to)
{
    int connection1 = from;  // number in the adjacency list

    int connection2 = to;// number in the adjacency list

    if (connection1 <0 ||connection2 <0) 
        return 0;

    node * temp  = new node; // 
    // where we gonna end 
    temp ->adjacent = & adjacency_list[connection2];
    // where we are coming from
    temp -> next =adjacency_list[connection1].head;
    adjacency_list[connection1].head = temp ;


    return 1;

}

int graph ::  display_adjacent_wrapper (char * agoal) 
{
    int index = find_location( agoal); // find where in the adjacency list is the vertex
    if (index < 0) // if there are no vertices
        return 0;
    node * temp = adjacency_list[index].head ;
    display_adjacent(temp,index);
}

int graph :: display_adjacent(node * temp,int index)
{

    if ( !temp)
        return  0; // if the list is empty

    temp ->adjacent -> data -> display(); // display

    return  display_adjacent(temp -> next, index); // traverse

}



int graph :: dfs() // wrapper for the display fucntion
{
    int index = 0;
    bool* visited = new bool [list_size];// track of the visited vertices

    for ( index  = 0;index <list_size ;++index) // mark all vertices as not visited
        visited[index] =false;

    for (index =0;index < list_size ;++ index)// for each vertex that is not vsisit do a depth first traversal
        if (visited[index] == false)//if it has not  been visited
            display_dfs(index,visited) ;//calling the function

    delete []visited; // clean up memory


}

int graph ::display_dfs (int index ,bool * visited)
{
    visited[index] = true;// mark the flag the vertex as  visited
    cout<<"\t\t\tFor goal  # : " << index << endl;
    node * temp = adjacency_list[index].head ;
    display_adjacent(temp,index);     // call the function to display


}


int graph :: delete_all()
{
    if(!adjacency_list) 
        return 0;

    for (int i = 0;i<list_size ; ++i)
    {
        node * temp = adjacency_list[i].head;// temp = head;  
        node * current = temp; //current = temp;
        while(current)
        {
            temp = current->next; 
            delete current;
            current = temp;

      }
    } 


    return 0;
}












