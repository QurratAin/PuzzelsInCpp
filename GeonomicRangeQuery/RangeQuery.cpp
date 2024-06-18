#include "RangeQuery.h"

/*Every search query runs on the fly*/
vector<int> RangeQuery::solution_one(string& S, vector<int>& P, vector<int>& Q) {

    vector<int> minimal_factor(P.size(), 0);
    
    for (int query = 0; query < (int)P.size(); query++) {   
        char min_letter;
        if (P[query] - Q[query] == 0) { min_letter = S[P[query]]; }
        for (auto letter = S.begin() + P[query]; letter < S.begin() + Q[query]; ++letter) {
            min_letter = (*(letter + 1) < *(letter)) ? (*(letter + 1)) : *(letter);
            if (min_letter == 'A') { break; }
        }
        minimal_factor[query] = min_letter == 'A' ? 1 : min_letter == 'C' ? 2 : min_letter == 'G' ? 3 : 4;
    }
    return minimal_factor;
}

vector<int> RangeQuery::solution_two(string& S, vector<int>& P, vector<int>& Q) {

    vector<int> minimal_factor(P.size(), 0);

    for (int query = 0; query < (int)P.size(); query++) {
        char min_letter = *std::min_element(S.begin() + P[query], S.begin() + Q[query]+1);
        minimal_factor[query] = min_letter == 'A' ? 1 : min_letter == 'C' ? 2 : min_letter == 'G' ? 3 : 4;
    }
    return minimal_factor;
}

/*pre calculate the number of occurances of characters*/
vector<int> RangeQuery::solution_three(string& S, vector<int>& P, vector<int>& Q) {
    vector<int> minimal_factor(P.size(), 0);
    vector<int> A(S.size() + 1, 0);
    vector<int> C(S.size() + 1, 0);
    vector<int> G(S.size() + 1, 0);
    vector<int> T(S.size() + 1, 0);
    int A_count = 0, C_count = 0, G_count = 0, T_count = 0;
    for (int index = 0; index < static_cast<int>(S.size()); ++index) {
        switch (S[index]) {
        case 'A':
            ++A_count;
            break;
        case 'C':
            ++C_count;
            break;
        case 'G':
            ++G_count;
            break;
        case 'T':
            ++T_count;
            break;
        default:
            break;
        }
        A[index + 1] = A_count;
        C[index + 1] = C_count;
        G[index + 1] = G_count;
        T[index + 1] = T_count;
    }

    for (int query = 0; query < (int)P.size(); query++) {
        minimal_factor[query] = (A[Q[query] + 1] - A[P[query]]) > 0 ? 1 : (C[Q[query] +1] - C[P[query]]) > 0 ? 2 : (G[Q[query] + 1] - G[P[query]]) > 0 ? 3 : 4;
    }

    return minimal_factor;
}