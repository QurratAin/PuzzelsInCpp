#include "SemiPrime.h"

vector<int> SemiPrime::solution(int N, vector<int>& P, vector<int>& Q)
{
    vector<int> count(P.size(), 0);
    if (N < 4) return count;

    vector<unsigned long int> smallest_factor(N + 1, 0);
    vector<unsigned long int> prefix_sum(N + 1, 0);
    // calculate the smallest factors for every number till N
    // lets N = 25
    //                 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
    // smallest_fact = 0 0 0 0 2 0 2 0 2 3 2  0  2  0  2  3  2  0  2  0  2  3  2  0   2  5
    for (int num = 2; num < N; ++num) {
        unsigned long long int product = num * num;
        while (product <= N) {
            smallest_factor[product] = num;
            product += num;
        }
    }

    vector<unsigned long long int> semiprime;
    for (int first_prime = 2; first_prime < N; ++first_prime) {
        unsigned long long int semi_p = first_prime * first_prime;
        if (smallest_factor[first_prime] == 0 && semi_p <= N) {
            semiprime.push_back(semi_p);    // adding product with self
            for (int sec_prime = first_prime + 1; sec_prime < N; ++sec_prime) {
                semi_p = first_prime * sec_prime;
                if (smallest_factor[sec_prime] == 0 && semi_p <= N) {
                    semiprime.push_back(semi_p);    // adding product with other primes
                }
            }
        }
    }
    
    std::sort(semiprime.begin(), semiprime.end());
    auto it = semiprime.begin();
    int sum = 0;
    for (int index = 4; index <= N; ++index) {
        if (*it == index) {
            ++sum;
            ++it;
        }
        prefix_sum[index] = sum;
    }
    

    for (int query = 0; query < static_cast<int>(P.size()); ++query) {
        count[query] = prefix_sum[Q[query]] - prefix_sum[P[query] - 1];
    }
    return count;
}
