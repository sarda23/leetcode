import numpy as np
import matplotlib.pyplot as plt

# Define theta values from 0 to 2π with fine granularity
theta = np.linspace(0, 2 * np.pi, 1000)

# Define x and y based on the given parametric equations
x = np.cos(theta) + 0.5385 * np.cos(41 * theta)
y = np.sin(theta) - 0.5385 * np.sin(41 * theta)

# Plotting the graph
plt.figure(figsize=(6, 6))
plt.plot(x, y, color='blue')
plt.title(r'Graph of $x = \cos(\theta) + 0.5385\cos(41\theta)$ and $y = \sin(\theta) - 0.5385\sin(41\theta)$')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.axis('equal')
plt.show()
