# Flood Fill
#### CPSC 221 Assignment  
Uploaded with permission.  
Please do not submit this as your solution, as it would be considered cheating.  
  
## Objective:  
- Execute a multipoint flood fill on a given image using BFS & DFS fill algorithms and three different fill patterns in C++  

To flood fill a region of an image, I specified a point on the image and a fill color (or pattern) and all points similar in color and adjacent to the
chosen point are changed to the fill color (or pattern).

### The 3 patterns:  
- solidColorPicker: The first pattern will be a solid color the same as the point’s center.  
- fadeColorPicker: The second fill pattern will fade to black as the points get farther from the center.
- borderColorPicker: The third fill pattern will leave most of the region unchanged, but it will draw a border around the edge of the region.  
  
  
The solid pattern (using dfs this time)  
![fill body of image using dfs](dfs_solid.gif)  
  
The fade pattern (using bfs this time)  
![fill body of image using dbs](bfs_fade.gif)  
  
The border pattern (using bfs this time)  
![fill border of image using bfs](bfs_border.gif) 




