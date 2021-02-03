#include <iostream>
#include <algorithm>
#include <vector>
#include "graph.h"

using namespace std;

//make the graph constructor
Graph::Graph(){
    countingChecker = 1;
    numOfActors = 0;
}

//make the insertInGraph function
void Graph::insert(vector<string> lineContents){
    string movie = lineContents[0];
    int dataSize = lineContents.size();
    vector<string> actors;
    for (int i = 1; i < dataSize; i++){
        actors.push_back(lineContents[i]);
    }
    list<Actors> coactors;
    int actorsSize = actors.size();
    for (int j=0; j<actorsSize; j++){
        coactors.push_back(Actors(actors[j], movie));
    }
    for (int k=0; k<actorsSize;k++){
        list<Actors> tempy = coactors;
        tempy.remove(Actors(actors[k], movie));
        if (graph.find(actors[k]) != graph.end()){
            graph[actors[k]].insert(graph.at(actors[k]).end(), tempy.begin(), tempy.end());
        }
        else if (graph.find(actors[k]) == graph.end()){
            graph.insert(pair<string, list<Actors>>(actors[k], tempy));
        }
    }
}

//bool Graph::BFS(string destination, unordered_map<string, Actors> *origin, unordered_map<string, bool> *children, queue<string> *queue){
bool Graph::BFS(string destination, unordered_map<string, Actors> *origin, unordered_map<string, bool> *children, queue<string> *queue){
    string visiting = queue->front();
    queue->pop();
    for (Actors now : graph[visiting]){
        if(children->at(now.name) == true){
            continue;
        }
        else if (children->at(now.name) == false){
            origin->insert(pair<string, Actors>(now.name, Actors(visiting, now.movie)));
            children->at(now.name) = true;
            queue->push(now.name);
            if (now.name != destination){
                continue;
            }
            else if(now.name == destination){
                return true;
            }
        }
    }
    return false;
}

list<string> Graph::shortestDistance(string start, string end){
    unordered_map<string, Actors> t_origin;
    queue<string> t_queue;
    int checkcounter = 0;
    unordered_map<string, bool> t_children;
    
    for (pair<string, list<Actors>> pair : graph){
        t_children.insert(::pair<string, bool>(pair.first, false));
    }
  
    t_queue.push(start);
    checkcounter += 1;
    t_children[start] = true;
    checkcounter += 1;
    t_origin.insert(::pair<string, Actors>(start, Actors("", ""))); //empty entry
    while (!t_queue.empty())
    {
        checkcounter += 1;
        for (int l=0; l<10; l++){
            checkcounter = checkcounter + 1;
        }
      //bool Graph::BFS(string destination, unordered_map<string, Actors> *origin, unordered_map<string, bool> *children, queue<string> *queue){

        //if (BFS(end, &t_origin,&t_children,&t_queue))//check this
//bool Graph::BFS(string destination, unordered_map<string, Actors> *origin, unordered_map<string, bool> *children, queue<string> *queue)
        if (BFS(end, &t_origin, &t_children, &t_queue))
        {
            for (int m=0; m<3; m++){
            checkcounter = checkcounter + 1;
            }
            list<string> way;
            string actor = end;
            way.push_back(actor);
            while(actor != start){
                way.push_back(t_origin.at(actor).movie);
                way.push_back(t_origin.at(actor).name);
                actor = t_origin.at(actor).name;
            }
            reverse(way.begin(), way.end());
            return way;     
        }
    }
    list<string> tempies = {""};
    return tempies;
}

bool Graph::findLink(string starting, string ending){
    return ((graph.find(ending) != graph.end()) && (graph.find(starting) != graph.end()));
}

