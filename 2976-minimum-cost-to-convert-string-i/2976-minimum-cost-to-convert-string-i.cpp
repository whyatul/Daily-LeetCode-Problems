class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
  const int INF = 1e9;
        const int CHARS = 26;
        
        // Initialize distance matrix with infinity
        vector<vector<int>> dist(CHARS, vector<int>(CHARS, INF));
        
        // Distance from a character to itself is 0
        for (int i = 0; i < CHARS; i++) {
            dist[i][i] = 0;
        }
        
        // Build the graph with given transformations
        for (int i = 0; i < original.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            // Keep minimum cost if there are multiple edges between same pair
            dist[from][to] = min(dist[from][to], cost[i]);
        }
        
        // Floyd-Warshall algorithm to find shortest paths between all pairs
        for (int k = 0; k < CHARS; k++) {
            for (int i = 0; i < CHARS; i++) {
                for (int j = 0; j < CHARS; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Calculate total cost to transform source to target
        long long totalCost = 0;
        
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) {
                continue; // No transformation needed
            }
            
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            
            if (dist[from][to] == INF) {
                return -1; // Impossible to transform
            }
            
            totalCost += dist[from][to];
        }
        
        return totalCost;
    }
};