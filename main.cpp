/* Nikolay Nikolov
   CS163
Instructor: Karla Fant
Program # 5
Purpose of the program :
The purpose of the program is using Adjacency List to link goals in graph, display the adjacent ,
and display all depth first. And deallocate all.


This is the main :


*/
#include"graph.h"
#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;
const int SIZE =100;

int main (){

    graph myGraph;
  
    char agoal [SIZE];
    char apre_requisite [SIZE] ;
    char connected [100];
    bool done = false;
    int var = 0;
    char response;
    int from;
    int to;


    while (!done){
        cout <<"\t\t\t MENU " <<endl;
        cout<<"\t\t\tHI !!" << endl;
        cout<<"\t\t\tThese are the options : " << endl;
        cout<<"\t\t\tTo insert a goal and a pre-requisite type 1" << endl;
        cout<<"\t\t\tTo create an edge type 2 " << endl;
        cout<<"\t\t\tTo find all the pre- requisites linked to a goal type 3"<< endl;
        cout<<"\t\t\tTo display all type 4 " << endl;
        cout<<"\t\t\tTo quit press 0 ;" << endl;
        cout <<"\t\t\tEnter in your choice: ";
        cin >> var;
        cin.ignore(100, '\n');
        cout << endl;

        switch(var){
            case 1: // insert into the array 
                do{
                    cout << "\t\t\tPlease enter a goal . --->" ;
                    cin.get(agoal, 100); cin.ignore(100,'\n');
                    myGraph.insert_vertex(agoal);
                    cout <<" \t\t\t Would you like to do enter another goal? Type y for yes . -->";
                    cin >> response;
                    cin.ignore(100,'\n');
                    cout<< endl;

                } while (response == 'y');


                break ;

            case 2: // create an edge 
                do{
                cout <<endl;
                cout <<"\t\t\t Enter two goals are related (connected):" << endl;
                cout<<"\t\t\t The first is main goal you want to achieve--> :" ;
                cin.get(agoal,100);cin.ignore(100,'\n');
                from = myGraph.find_location(agoal);
                
                cout << endl;
                cout<<"\t\t\t The second is what you have to do to achieve that ---> : " ;
                cin.get(agoal,100); cin.ignore(100,'\n');
                to = myGraph.find_location(agoal);
                cout << endl;
                myGraph.insert_edge (from ,to);
                cout<<"\t\t\t Would you like link again ? Type y for yes -->: " ;
                cin >> response;
                cin.ignore(100,'\n');
                } while (response =='y');


                break ;

            case 3: // display adjacent 
                cout<< endl;
                cout<<"\t\t\t Enter the goal you want to achieve -->: ";
                cin.get(agoal,100);cin.ignore(100, '\n');
                cout<<"\t\t\t To achieve this ->" << agoal <<" <- you must : " <<endl;

                myGraph.display_adjacent_wrapper(agoal);

                break ;

            case 4: // display all 
                myGraph.dfs();
                break;

            case 0: 
                cout<<"\t\t\t Live Long And Prosper ! " << endl ;
                done = true ;

            default: 

                break ;

        }

    }






















    return 0;

}
