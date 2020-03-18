read N
read K
read X
read Y
((N > K)) && echo $((K * X + (N - K) * Y)) || echo $((N * X))
