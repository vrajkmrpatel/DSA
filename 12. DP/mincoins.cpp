#include <iostream>
#include <vector>
#include <algorithm>

int coinChange(std::vector<int>& coins, int amount) {
    
    std::vector<int> DP(amount + 1, amount + 1);

    // Base case
    DP[0] = 0;

    // Compute minimum coins for each amount from 1 to the target amount
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                DP[i] = std::min(DP[i], DP[i - coin] + 1);
            }
        }
    }
    
    return DP[amount] == amount + 1 ? -1 : DP[amount];
}

int main() {
    std::vector<int> coins = {1, 5, 6, 9};
    int amount = 11;
    int result = coinChange(coins, amount);
    if (result != -1) {
        std::cout << "Minimum coins needed: " << result << std::endl;
    } else {
        std::cout << "Impossible to make the amount with given coins." << std::endl;
    }
    return 0;
}
