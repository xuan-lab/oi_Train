import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
import time
from collections import deque

# Enlarged maze (10x10)
m, n = 10, 10
maze = [
    [0, 1, 0, 0, 0, 0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0, 0, 0, 0, 1, 0],
    [0, 0, 0, 1, 0, 1, 1, 0, 1, 0],
    [1, 1, 0, 0, 0, 0, 1, 0, 0, 0],
    [0, 0, 0, 1, 1, 0, 1, 1, 1, 0],
    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 1, 0, 1, 0, 1],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
    [0, 1, 1, 0, 1, 1, 0, 1, 1, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
]
vis = [[False] * n for _ in range(m)]

def direction_name(dx, dy):
    if dx == 0 and dy == 1: return "right"
    if dx == 1 and dy == 0: return "down"
    if dx == 0 and dy == -1: return "left"
    if dx == -1 and dy == 0: return "up"
    return ""

# Animation update function
def bfs(start_x, start_y, ax):
    # Initialize the BFS queue
    queue = deque([(start_x, start_y)])
    parent_map = {}
    visited_cells = []
    path = []

    # Mark the start point as visited
    vis[start_x][start_y] = True
    visited_cells.append((start_x, start_y))
    
    # Perform BFS
    while queue:
        x, y = queue.popleft()
        
        # If we reach the goal, reconstruct the path
        if (x, y) == (m - 1, n - 1):
            while (x, y) != (start_x, start_y):
                path.append((x, y))
                x, y = parent_map[(x, y)]
            path.append((start_x, start_y))
            path.reverse()  # Reversed path for correct order
            update_display(x, y, path, visited_cells, ax, status="Found the goal!")
            return True
        
        # Explore four directions
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # right, down, left, up
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            
            # Check boundaries and obstacles
            if 0 <= nx < m and 0 <= ny < n and not vis[nx][ny] and maze[nx][ny] == 0:
                vis[nx][ny] = True
                parent_map[(nx, ny)] = (x, y)  # Store the parent to reconstruct path
                queue.append((nx, ny))
                visited_cells.append((nx, ny))
                update_display(x, y, path, visited_cells, ax, status=f"Visiting ({nx},{ny})")

    # If no path found
    update_display(start_x, start_y, path, visited_cells, ax, status="No viable path found")
    return False

def update_display(x, y, path, visited_cells, ax, status="Exploring", backtracking=False, valid=True):
    ax.clear()
    
    # Draw the maze
    maze_display = np.array(maze, dtype=float)
    # Mark all walls as black
    maze_display = np.where(maze_display == 1, 0.0, 0.9)
    
    # Show all visited cells
    for vx, vy in visited_cells:
        if (vx, vy) not in path:
            maze_display[vx][vy] = 0.7  # Light gray for visited but not in path
    
    # Show current path
    for i, (px, py) in enumerate(path):
        # Path color gradient from start to current position
        maze_display[px][py] = 0.5
    
    ax.imshow(maze_display, cmap='Blues_r')
    
    # Mark start and goal
    ax.add_patch(plt.Rectangle((0, 0), 1, 1, color='green', alpha=0.7))
    ax.add_patch(plt.Rectangle((n-1, m-1), 1, 1, color='red', alpha=0.7))
    
    # Mark current position
    if valid:  # Only mark when position is valid
        if backtracking:
            ax.add_patch(plt.Rectangle((y, x), 1, 1, color='orange', alpha=0.7))
        else:
            ax.add_patch(plt.Rectangle((y, x), 1, 1, color='yellow', alpha=0.7))
    
    # Add grid and coordinates
    for i in range(m):
        for j in range(n):
            ax.text(j + 0.5, i + 0.5, f'({i},{j})', ha='center', va='center', fontsize=7)
    
    ax.set_xticks(np.arange(-0.5, n, 1), minor=True)
    ax.set_yticks(np.arange(-0.5, m, 1), minor=True)
    ax.grid(which='minor', color='black', linestyle='-', linewidth=1)
    
    # Show current status
    title = f"Current position: ({x}, {y}) - {status}"
    ax.set_title(title)
    
    # Show current path information
    path_text = "Current path: " + " → ".join([f"({x},{y})" for x, y in path])
    plt.figtext(0.5, 0.01, path_text, ha="center", fontsize=9, bbox={"facecolor":"white", "alpha":0.5})
    
    plt.draw()
    plt.pause(1.0)  # Longer pause for clearer observation

# Create animation
fig, ax = plt.subplots(figsize=(12, 11))
plt.subplots_adjust(left=0.1, right=0.9, top=0.9, bottom=0.1)

# Start BFS search
path = []
visited_cells = []
result = bfs(0, 0, ax)

# Show search result
if result:
    ax.set_title("Successfully found a path!")
    # Highlight final path
    for px, py in path:
        ax.add_patch(plt.Rectangle((py, px), 1, 1, color='lime', alpha=0.7))
else:
    ax.set_title("No viable path found")

plt.show()
