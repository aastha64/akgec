#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to rearrange the array
vector<int> rearrangeArray(vector<int>& arr) {
    vector<int> primes, nonPrimes;

    // Separate primes and non-primes
    for (int num : arr) {
        if (isPrime(num)) {
            primes.push_back(num);
        } else {
            nonPrimes.push_back(num);
        }
    }

    // Sort primes in ascending order and non-primes in descending order
    sort(primes.begin(), primes.end());
    sort(nonPrimes.rbegin(), nonPrimes.rend());

    // Start with the largest prime, then add non-primes, then the smallest prime
    vector<int> result;
    if (!primes.empty()) {
        result.push_back(primes.back()); // Largest prime at the start
    }
    result.insert(result.end(), nonPrimes.begin(), nonPrimes.end());
    if (!primes.empty()) {
        result.push_back(primes.front()); // Smallest prime at the end
    }

    return result;
}

int main() {
    vector<int> arr = {5, 1, 8, 11, 2}; // Example input

    vector<int> result = rearrangeArray(arr);

    // Output the result
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
