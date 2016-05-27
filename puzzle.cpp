#ifndef PUZZLE_CPP
#define PUZZLE_CPP
#include "puzzle.h"
#include<QThread>
#include "board.h"
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#include <windows.h>
#endif

namespace std {
  template <>
  struct hash<tuple<int,int> > {
    inline size_t operator()(const tuple<int,int>& location) const {
      int x, y;
      tie (x, y) = location;
      return x * 1812433253 + y;
    }
  };
}


void reconstruct_path(Location start,Location goal,unordered_map<Location, Location>& came_from) {

  vector<Location> path;
  Location current = goal;
  path.push_back(current);
  int x,y;
  while (current != start) {
    current = came_from[current];
    //tie(x,y) = current;
    path.push_back(current);
  }
  std::reverse(path.begin(), path.end());

  Square** mb = Button::board->getGrid();
  for(Location p : path){
      tie (x, y) = p;
      mb[x][y].getButton()->setIcon(Button::icon_check);
    }
}


int heuristic(Location a, Location b) {
  int x1, y1, x2, y2;
  tie (x1, y1) = a;
  tie (x2, y2) = b;
  return abs(x1 - x2) + abs(y1 - y2);
}



void a_star_search(Location start,
   Location goal,
   unordered_map<Location, Location>& came_from,
   unordered_map<Location, int>& cost_so_far)
{

  PriorityQueue<Location> frontier;
  frontier.put(start, 0);
  int x,y;
  came_from[start] = start;
  cost_so_far[start] = 0;
  int count =0;
  while (!frontier.empty()) {
    auto current = frontier.get();
   // tie(x,y) = current;
    if (count>=100||current == goal) {
      break;
    }
    count++;
    for (auto next : Button::board->neighbors(current)) {
      int new_cost = cost_so_far[current] + Button::board->cost(current, next);
      if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
        cost_so_far[next] = new_cost;
        int priority = new_cost + heuristic(next, goal);
        frontier.put(next, priority);
        came_from[next] = current;
     //   tie(x,y) = current;
     //   tie(x,y) = next;
      }
    }
  }
  if(count>=100){
      QMessageBox::about (NULL, "Not Reachable", "Press Reset Again!!");

    }
  reconstruct_path(start, goal, came_from);
}
#endif // PUZZLE_CPP

