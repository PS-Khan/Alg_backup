/*

https://www.codingame.com/ide/puzzle/six-degrees-of-kevin-bacon

Six Degrees of Kevin Bacon is a pop-culture game in which an arbitrarily chosen actor is repeatedly connected to another actor via a movie that both actors have appeared in together, repeating this process to try to find the shortest path that ultimately leads to the prolific American actor Kevin Bacon.

Given an actor_name, an integer n and then that many movie_casts determine the Bacon number of actor_name, i.e. the minimum number of movies needed to link actor_name to Kevin Bacon.

Example:
Elvis Presley
3
Change of Habit: Elvis Presley, Mary Tyler Moore, Barbara McNair, Jane Elliot, Ed Asner
JFK: Kevin Costner, Kevin Bacon, Tommy Lee Jones, Laurie Metcalf, Gary Oldman, Ed Asner
Sleepers: Kevin Bacon, Jason Patric, Brad Pitt, Robert De Niro, Dustin Hoffman

The answer is 2 because Elvis Presley → Ed Asner → Kevin Bacon, using Change of Habit to connect Presley and Asner and then JFK to connect Asner to Bacon = 2 degrees of separation.
Input
Line 1 : actor_name, the name of the actor whose Bacon number is being calculated
Line 2 : an integer n
Next n lines : a string movie_cast in the format Movie_name: Actor 1, Actor 2, ...
Output
1 line : an integer representing the Bacon number of actor_name: the minimum number of movies needed to connect actor_name to Kevin Bacon
Constraints
There will always be a path to Kevin Bacon.
0 < n < 50
Movie casts will contain at most 10 actors.
A single colon (followed by a space) is used to separate the movie title from the movie cast. A single comma (followed by a space) is used to separate the cast members.
There will be no colons (:) in movie titles or actor names.
Example
Input
Elvis Presley
3
Change of Habit: Elvis Presley, Mary Tyler Moore, Barbara McNair, Jane Elliot, Ed Asner
JFK: Kevin Costner, Kevin Bacon, Tommy Lee Jones, Laurie Metcalf, Gary Oldman, Ed Asner
Sleepers: Kevin Bacon, Jason Patric, Brad Pitt, Robert De Niro, Dustin Hoffman
Output
2
*/







#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <queue>
using namespace std;

/**
 * 6 Degrees of Kevin Bacon!
 **/

int main()
{
    string actor_name;
    getline(cin, actor_name); 
    int n;
    cin >> n;
    cin.ignore();  

    unordered_map<string, vector<string>> graph; 

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);  

        stringstream ss(line);
        string movie, actor;
        getline(ss, movie, ':'); 

        vector<string> actors;
        while (getline(ss, actor, ',')) {
            actor.erase(0, actor.find_first_not_of(" ")); 
            actors.push_back(actor);
        }

        
        for (const string& a : actors) {
            for (const string& b : actors) {
                if (a != b) {
                    graph[a].push_back(b);
                }
            }
        }
    }

    
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    q.push({actor_name, 0});
    visited.insert(actor_name);

    while (!q.empty()) {
        auto [current, degree] = q.front();
        q.pop();

        if (current == "Kevin Bacon") {
            cout << degree << endl;
            return 0;
        }

        for (const string& neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, degree + 1});
            }
        }
    }

    return 0;
}