#include <iostream>
#include <list>
#include <vector>
#include <string.h>
using namespace std;

const int MAXL=100011;

// Suffix Array data structure
struct SuffixArray {
    struct RadixElement {
        int id, k[2];
    } RE[MAXL], RT[MAXL];

    int N, A[MAXL], SA[MAXL], Rank[MAXL], Height[MAXL],
        C[MAXL], Contribute[MAXL];

    // Radix Sort helper function
    void RadixSort() {
        int i, y;
        for (y = 1; y >= 0; y--) {
            memset(C, 0, sizeof(C));
            for (i = 1; i <= N; i++) C[RE[i].k[y]]++;
            for (i = 1; i < MAXL; i++) C[i] += C[i - 1];
            for (i = N; i >= 1; i--) RT[C[RE[i].k[y]]--] = RE[i];
            for (i = 1; i <= N; i++) RE[i] = RT[i];
        }
        for (i = 1; i <= N; i++) {
            Rank[RE[i].id] = Rank[RE[i - 1].id];
            if (RE[i].k[0] != RE[i - 1].k[0] || RE[i].k[1] != RE[i - 1].k[1])
                Rank[RE[i].id]++;
        }
    }

    // Calculate Suffix Array
    void CalcSA() {
        int i, k;
        RE[0].k[0] = -1;
        for (i = 1; i <= N; i++)
            RE[i].id = i, RE[i].k[0] = A[i], RE[i].k[1] = 0;
        RadixSort();
        for (k = 1; k + 1 <= N; k *= 2) {
            for (i = 1; i <= N; i++)
                RE[i].id = i, RE[i].k[0] = Rank[i], RE[i].k[1] = i + k <= N ? Rank[i + k] : 0;
            RadixSort();
        }
        for (i = 1; i <= N; i++)
            SA[Rank[i]] = i;
    }

    // Calculate the height of suffixes
    void CalcHeight() {
        int i, k, h = 0;
        for (i = 1; i <= N; i++) {
            if (Rank[i] == 1)
                h = 0;
            else {
                k = SA[Rank[i] - 1];
                if (--h < 0) h = 0;
                for (; A[i + h] == A[k + h]; h++);
            }
            Height[Rank[i]] = h;
        }
    }

    // Calculate the contribution of each suffix
    void CalContribute() {
        int i, j = 0;
        for (i = 1; i <= N; i++) {
            int pos = SA[i];
            int maxrange = 0;
            j = pos;
            while (A[j] <= 26 && j <= N) {
                ++j;
            }
            Contribute[i] = j - pos - Height[i];
        }
    }
} SA;

// Function to check and return the result for a given query
string check(int query) {
    char result[2000];
    int sum = 0, i, pos = 0;
    for (i = 1; i <= SA.N; i++) {
        sum += SA.Contribute[i];
        if (query <= sum) {
            pos = i;
            break;
        }
    }
    if (pos) {
        int index = query - sum;
        int size = index + SA.Height[pos] + SA.Contribute[pos];
        for (int i = 0; i < size; ++i) {
            result[i] = SA.A[SA.SA[pos] + i] + 'a' - 1;
        }
        result[size] = '\0';
        return result;
    }
    return "INVALID";
}

int main() {
    int cas;
    bool running = true;
    while (running) {
        int i;
        cin >> cas;
        list<string> inlist;
        vector<int> querylist;
        for (i = 0; i < cas; ++i) {
            string v;
            cin >> v;
            inlist.push_back(v);
        }
        list<string>::iterator it;
        SA.N = 0;
        for (it = inlist.begin(), i = 1; it != inlist.end(); it++, ++i) {
            for (const char *p = (*it).c_str(); *p; p++) {
                SA.A[++SA.N] = *p - 'a' + 1;
            }
            if (i < cas)
                SA.A[++SA.N] = 30 + i;
        }

        int queryNumber;
        cin >> queryNumber;
        for (i = 0; i < queryNumber; ++i) {
            int query;
            cin >> query;
            querylist.push_back(query);
        }
        SA.CalcSA();
        SA.CalcHeight();
        SA.CalContribute();
        vector<int>::iterator qit;
        for (qit = querylist.begin(); qit != querylist.end(); qit++) {
            cout << check(*qit) << endl;
        }
        running = false;
    }
}
