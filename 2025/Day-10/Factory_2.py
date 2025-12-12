import os
import ast
import numpy as np
from scipy.optimize import linprog
TOL = 1e-5

def read_input():
    with open(os.path.join(os.path.dirname(__file__), "Day10.txt"), "r", encoding = "utf-8") as f:
        return f.read().strip()

def parse_input(data):
    machines = []
    for line in data.splitlines():
        ps = line.split(" ")
        goal_mask = 0
        for i, c in enumerate(ps[0][1 : -1]):
            if c == "#":
                goal_mask |= 1 << i
        goal_counters = list(map(int, ps[-1][1 : -1].split(",")))
        raw = ast.literal_eval("[" + ",".join(ps[1 : -1]) + "]")
        button_masks = []
        for b in raw:
            m = 0
            if isinstance(b, int):
                m |= 1 << b
            else:
                for bit in b:
                    m |= 1 << bit
            button_masks.append(m)
        machines.append((goal_mask, goal_counters, button_masks))
    return machines

def solve_p2(goal_vals, buttons):
    num_rows, num_cols = len(goal_vals), len(buttons)
    shifts = np.arange(num_rows)
    matrix = ((np.array(buttons)[:, None] >> shifts) & 1).T.astype(float)
    target = np.array(goal_vals, dtype=float)
    if num_cols <= num_rows:
        try:
            x, _, rank, _ = np.linalg.lstsq(matrix, target, rcond=None)
            xr = np.round(x).astype(int)
            if (rank == num_cols and np.all(xr >= 0) and np.allclose(x, xr, atol = TOL) 
                and np.allclose(np.dot(matrix, xr), target)):
                return int(np.sum(xr))
        except np.linalg.LinAlgError:
            pass
    res = linprog([1] * num_cols, A_eq = matrix, b_eq = target, bounds = (0, None), method = "highs",
                integrality = True)
    return round(res.fun)

def main():
    data = parse_input(read_input())
    print(f"Result: {sum(solve_p2(d[1], d[2]) for d in data)}")

if __name__ == "__main__":
    main()