#!/bin/python3

import sys
import bisect

# Input the number of scores
n = int(input().strip())

# Input the scores as a list
scores = [int(scores_temp) for scores_temp in input().strip().split(' ')]

# Input the number of Alice's scores
m = int(input().strip())

# Input Alice's scores as a list
alice = [int(alice_temp) for alice_temp in input().strip().split(' ')]

# Remove duplicate scores and sort the list in ascending order
scores = list(sorted(set(scores)))

# Initialize an empty list to store the ranks of Alice's scores
aa = [bisect.bisect_right(scores, a) for a in alice]

# Calculate and print the ranks for each of Alice's scores
for a in aa:
    # The rank is the total number of unique scores + 1 minus the position where Alice's score would be inserted
    v = len(scores) + 1 - a
    print(v)
