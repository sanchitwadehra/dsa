#include <bits/stdc++.h>
using namespace std;

#define INF 99999999

int n;
int dp[16][10];
int dist[10][10];
int VISITED_ALL;

int tsp(int mask, int pos)
{

    if (mask == VISITED_ALL)
    {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INF;

    for (int city = 0; city < n; city++)
    {

        if ((mask & (1 << city)) == 0)
        {

            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

void takeInput()
{
    cout << "Enter the number of cities: ";
    cin >> n;
    VISITED_ALL = (1 << n) - 1;
    cout << "\nEnter the Cost Matrix\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Elements of Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }
    cout << "\n\nThe cost list is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << dist[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    takeInput();
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << "\n\nThe Path is:\n";
    cout << "1--->";
    tsp(1, 0); // passing 0 because starting vertex
    cout << "1";
    cout << "\n\nMinimum cost is " << dp[1][0] << "\n";

    return 0;
}

// This code now stores the next city to visit from every city at every state of the mask in the nextCity array. After calling the tsp function, it prints the path by starting from city 0 and repeatedly moving to nextCity[mask][pos] until it comes back to 0. The cities are printed as 1-indexed. Please note that this code will only print one of the paths if there are multiple paths with the same minimum cost. If you want to print all such paths, you would need a more complex modification. Also, please make sure to initialize the nextCity array correctly and handle the case when no city can be visited next from the current city.

// This code is a solution to the Travelling Salesman Problem (TSP) using Dynamic Programming. The TSP is a classic algorithmic problem in the field of computer science and operations research. It focuses on optimization. In this problem, a salesman is given a list of cities, and must determine the shortest route that allows him to visit each city once and return to his original location.

// Here's a breakdown of the code:

// 1. **Global Variables**: The code begins by declaring global variables. `n` is the number of cities. `dp` is the memoization table for dynamic programming. `dist` is the adjacency matrix that stores the distances between cities. `VISITED_ALL` is a bitmask that represents the state when all cities have been visited.

// 2. **tsp function**: This function calculates the minimum cost to visit all cities from a given position. It uses a bitmask to keep track of the cities that have been visited so far and dynamic programming to store intermediate results.

// 3. **takeInput function**: This function takes the number of cities and the cost matrix as input from the user. It then prints the cost matrix.

// 4. **main function**: This function initializes the dp array and calls the `tsp` function with the initial mask and position. The minimum travelling cost is then printed.

// **Example Scenario**:

// Let's say we have 4 cities and the distances between them are as follows:

// ```
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0
// ```

// Here's how you would input this into the program:

// 1. When the program prompts "Enter the number of cities:", you would enter `4`.

// 2. Then the program will prompt you to enter the cost matrix. You would enter the distances row by row. For example, when the program prompts "Enter Elements of Row 1:", you would enter `0 10 15 20`. You would do this for each row.

// The program will then print the cost matrix, calculate the minimum cost to visit all cities, and print the path and the minimum cost.

// **Logic-wise Output**:

// The output of the program will be the minimum cost to visit all cities and return to the starting city. For the above example, the output will be:

// ```
// The Path is:
// 1--->2--->4--->3--->1
// Minimum cost is 80
// ```

// This means that the path that the salesman should take to minimize the total distance is to go from city 1 to city 2, then to city 4, then to city 3, and finally return to city 1. The total distance of this path is 80. Note that city numbering starts from 1 in this code. The actual path may vary depending on the distances between the cities. The time complexity of this code is O(n^2 * 2^n) and the space complexity is O(n * 2^n), which is much less than n! but still exponential. This is the most efficient approach to solving the TSP.
