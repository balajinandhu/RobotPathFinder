#ifndef PQ_H
#define PQ_H
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using std::priority_queue;
using std::pair;
using std::tuple;
using std::tie;
using std::vector;

template<typename T, typename Number=int>
class PriorityQueue {
private:
  typedef pair<Number, T> PQElement;
  priority_queue<PQElement, vector<PQElement>,
                 std::greater<PQElement>> elements;
public:
  inline bool empty() const { return elements.empty(); }

  inline void put(T item, Number priority) {
    elements.emplace(priority, item);
  }

  inline T get() {
    T best_item = elements.top().second;
    elements.pop();
    return best_item;
  }
};


#endif // PQ_H
