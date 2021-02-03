#ifndef GRAPH_H
#define GRAPH_H

#include <iterator>
#include <unordered_map>
#include <list>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Actors{
public:
    string movie;
    string name;
    int counter;

    Actors(){ //default
        movie = "";
        name = "";
        counter = 0;
    }

    Actors(string Name, string Movie){//if name and movie provided, counter used for testing
        movie = Movie;
        name = Name;
        counter = 0;
    }
    
    bool operator!=(const Actors &ca) const { return (!operator==(ca)); }
    bool operator==(const Actors &ca) const { return (name == ca.name && movie == ca.movie); }

};

class Graph{
    private:
        int numOfActors;
        int countingChecker;
        unordered_map<string, list<Actors>> graph;
    public:
        Graph();
        void insert(vector<string>);
        bool BFS(string, unordered_map<string, Actors> *, unordered_map<string, bool> *, queue<string> *);
        bool findLink(string, string);
        list<string> shortestDistance(string, string);

};



#endif