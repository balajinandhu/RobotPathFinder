#ifndef PUZZLE_H
#define PUZZLE_H


#include <queue>
#include <vector>
#include <unordered_map>
#include <tuple>
#include "pq.h"
using std::unordered_map;
using std::vector;
using std::tie;
typedef std::tuple<int,int> Location;

void reconstruct_path(Location start,Location goal,unordered_map<Location, Location>& came_from);
int heuristic(Location a, Location b);
void a_star_search(Location start,Location goal,unordered_map<Location, Location>& came_from,unordered_map<Location, int>& cost_so_far);

#endif // PUZZLE_H
