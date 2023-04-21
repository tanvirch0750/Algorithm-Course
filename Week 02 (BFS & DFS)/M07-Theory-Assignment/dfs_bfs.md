GRAPH:
1
/ \
2 3
\ /
4

Step 1: 1
|
Queue: [1]

Step 2: 1
/ \
Queue: [2, 3]
Visited: [1]

Step 3: 1
/ \
Visited: [2, 3]
Queue: [3, 4]

Step 4: 1
/ \
Visited: [2, 3, 4]
Queue: [3]

Step 5: 1
/ \
Visited: [2, 3, 4]
Queue: []

Step 6: 1
Visited: [2, 3, 4]
Queue: [4]

Step 7: 1
Visited: [2, 3, 4]
Queue: []

Step 8: 1
Visited: [2, 3, 4]
Queue: []

Step 9: 1
Visited: [2, 3, 4]
Queue: []

DFS:
1
/ \
2 3
\ /
4

Step 1: 1
|
Visited: [1]

Step 2: 1
/ \
Visited: [1, 2]
|
[2]

Step 3: 1
/ \
Visited: [1, 2, 4]
|
[4]
|
[2]

Step 4: 1
/ \
Visited: [1, 2, 4, 3]
|
[4]
|
[2, 3]

Step 5: 1
/ \
Visited: [1, 2, 4, 3]
|
[4, 3]
|
[2]

Step 6: 1
Visited: [1, 2, 4, 3]
|
[4, 3, 2]

Step 7: 1
Visited: [1, 2, 4, 3]
|
[4, 3]

Step 8: 1
Visited: [1, 2, 4, 3]

Step 9: 1
Visited: [1, 2, 4, 3]
