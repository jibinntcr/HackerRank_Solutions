#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Input variables for height (H), width (W), and rotation amount (R)
    int H, W, R;
    cin >> H >> W >> R;

    // Calculate the number of cycles based on the minimum of width and height
    int ncycles = min(W, H) / 2;

    // Array to store the matrix elements
    int m[W * H];

    // 2D array to store cycles for rotation
    int cycles[150][1196];

    // Loop to input matrix elements
    for (int i = 0; i < W * H; i++)
        cin >> m[i];

    // Loop to extract cycles from the matrix
    for (int cycle = 0; cycle < ncycles; cycle++) {
        int i = 0;

        // Extract top side of the cycle
        for (int y = cycle, x = cycle; y < H - cycle - 1; y++)
            cycles[cycle][i++] = m[W * y + x];

        // Extract right side of the cycle
        for (int y = H - cycle - 1, x = cycle; x < W - cycle - 1; x++)
            cycles[cycle][i++] = m[W * y + x];

        // Extract bottom side of the cycle
        for (int y = H - cycle - 1, x = W - cycle - 1; y > cycle; y--)
            cycles[cycle][i++] = m[W * y + x];

        // Extract left side of the cycle
        for (int y = cycle, x = W - cycle - 1; x > cycle; x--)
            cycles[cycle][i++] = m[W * y + x];
    }

    // Loop to rotate the cycles based on the rotation amount
    for (int cycle = 0; cycle < ncycles; cycle++) {
        int cyclelen = 2 * (W - 2 * cycle) + 2 * (H - 2 * cycle) - 4;
        int i = -R % cyclelen + cyclelen;

        // Rotate and update the top side of the cycle
        for (int y = cycle, x = cycle; y < H - cycle - 1; y++)
            m[W * y + x] = cycles[cycle][i++ % cyclelen];

        // Rotate and update the right side of the cycle
        for (int y = H - cycle - 1, x = cycle; x < W - cycle - 1; x++)
            m[W * y + x] = cycles[cycle][i++ % cyclelen];

        // Rotate and update the bottom side of the cycle
        for (int y = H - cycle - 1, x = W - cycle - 1; y > cycle; y--)
            m[W * y + x] = cycles[cycle][i++ % cyclelen];

        // Rotate and update the left side of the cycle
        for (int y = cycle, x = W - cycle - 1; x > cycle; x--)
            m[W * y + x] = cycles[cycle][i++ % cyclelen];
    }

    // Output the rotated matrix
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (x) cout << ' ';
            cout << m[W * y + x];
        }
        cout << endl;
    }

    return 0;
}
