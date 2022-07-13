class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
       unordered_map<int, unordered_set<int>> station;
       for (int i = 0; i < routes.size (); ++i) 
          for (int j : routes[i]) station[j].insert (i);

       queue<pair<int, int>> to_visit; 
       to_visit.push ({ source, 0 });
       unordered_set<int> visited = { source };

       while (!to_visit.empty ()) 
       {
          int stop  = to_visit.front ().first;
          int bus_n = to_visit.front ().second;

          if (stop == target) return bus_n;
          to_visit.pop ();
          for (auto route : station[stop]) {
             for (auto next_stop : routes[route]) {
                auto it = visited.insert (next_stop);
                if (it.second) to_visit.push ({ next_stop, bus_n + 1 });              
             }

             routes[route].clear ();
          }
       }

       return -1;
    }
};