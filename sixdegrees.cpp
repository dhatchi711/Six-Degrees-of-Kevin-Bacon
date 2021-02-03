#include "graph.h"
#include <iostream>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char const **argv)
{
    if (argc < 3)
    {
        cout << "Wrong input try: ./sixdegress <INPUT FILE> <OUTPUTFILE>";
        exit(EXIT_FAILURE);
    }
    ifstream in;
    ofstream out;
    ifstream movieList;
    movieList.open("cleaned_movielist.txt");
    in.open(argv[1]);
    out.open(argv[2]);

    string store;
    Graph graphOfMovies;
    while (getline(movieList, store))
    {
        if (store.length() == 0)
            continue;

        stringstream inputstream(store);
        string val;
        vector<string> vals;
        while (inputstream >> val)
            vals.push_back(val);

        graphOfMovies.insert(vals);
    }

    string tempy;
    while (getline(in, tempy))
    {
        if (tempy.length() == 0)
            continue;

        stringstream iss(tempy);
        string arg;
        vector<string> args;
        while (iss >> arg)
            args.push_back(arg);
        if (!graphOfMovies.findLink(args[0], args[1]))
            out << "Not present";
        else if (args[0] == args[1])
            out << args[0];
        else
        {
            list<string> path = graphOfMovies.shortestDistance(args[0], args[1]);
            int count = 0;
            int makesureithits = 0;
            if (path.size() != 1){
                int jusWentBy = 0;
                for (string pathElem : path)
                {
                    if (count % 2){
                        out << " -(" << pathElem << ")- ";
                        makesureithits += 1;}
                    else{
                        jusWentBy += 1;
                        out << pathElem;
                        }
                    count++;
                }
            }
            else
                out << "Not present";
        }
        out << endl;
    }
    in.close();
    out.close();
}