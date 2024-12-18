#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// Function to solve the TSP using DP and bitmasking
int tsp(int n, const std::vector<std::vector<int>> &distances, std::vector<int> &path)
{
    int allVisited = (1 << n) - 1; // All cities visited mask
    std::vector<std::vector<int>> DP(1 << n, std::vector<int>(n, INF));
    DP[1][0] = 0; // Starting point: only city 0 is visited

    // Fill DP table
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        for (int i = 0; i < n; ++i)
        {
            if (!(mask & (1 << i)))
                continue; // Skip if city i is not in the current mask

            for (int j = 0; j < n; ++j)
            {
                if (i != j && (mask & (1 << j)))
                { // Check if city j is in mask
                    DP[mask][i] = std::min(DP[mask][i], DP[mask ^ (1 << i)][j] + distances[j][i]);
                }
            }
        }
    }

    // Find minimum distance to return to the start
    int min_distance = INF;
    int last_city = -1;
    for (int i = 1; i < n; ++i)
    {
        if (DP[allVisited][i] + distances[i][0] < min_distance)
        {
            min_distance = DP[allVisited][i] + distances[i][0];
            last_city = i;
        }
    }

    // Backtrack to reconstruct the optimal path
    int mask = allVisited;
    path.push_back(0); // Start from city 0
    while (last_city != -1)
    {
        path.push_back(last_city);
        int next_city = -1;
        for (int j = 0; j < n; ++j)
        {
            if (j != last_city && (mask & (1 << j)) &&
                DP[mask][last_city] == DP[mask ^ (1 << last_city)][j] + distances[j][last_city])
            {
                next_city = j;
                break;
            }
        }
        mask ^= (1 << last_city);
        last_city = next_city;
    }
    path.push_back(0); // Return to start
    std::reverse(path.begin(), path.end());

    return min_distance;
}

int main()
{
    int n = 4;
    std::vector<std::vector<int>> distances = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    std::vector<int> path;
    int minDistance = tsp(n, distances, path);

    std::cout << "Minimum Distance: " << minDistance << std::endl;
    std::cout << "Optimal Path: ";
    for (int city : path)
    {
        std::cout << city << " ";
    }
    std::cout << std::endl;

    return 0;
}
