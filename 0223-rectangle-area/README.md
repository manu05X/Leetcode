<h2><a href="https://leetcode.com/problems/rectangle-area">223. Rectangle Area</a></h2><h3>Medium</h3><hr><p>Given the coordinates of two <strong>rectilinear</strong> rectangles in a 2D plane, return <em>the total area covered by the two rectangles</em>.</p>

<p>The first rectangle is defined by its <strong>bottom-left</strong> corner <code>(ax1, ay1)</code> and its <strong>top-right</strong> corner <code>(ax2, ay2)</code>.</p>

<p>The second rectangle is defined by its <strong>bottom-left</strong> corner <code>(bx1, by1)</code> and its <strong>top-right</strong> corner <code>(bx2, by2)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="Rectangle Area" src="https://assets.leetcode.com/uploads/2021/05/08/rectangle-plane.png" style="width: 700px; height: 365px;" />
<pre>
<strong>Input:</strong> ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
<strong>Output:</strong> 45
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>4</sup> &lt;= ax1 &lt;= ax2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= ay1 &lt;= ay2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= bx1 &lt;= bx2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= by1 &lt;= by2 &lt;= 10<sup>4</sup></code></li>
</ul>

---
### Approach: Math and Geometry 
#### Intuition
As explained in the overview section above, calculating the individual areas of both rectangles is easy enough. We have the coordinates of top right and bottom left corners - *(x1,y1)* and *(x2,y2)*. In this case, the area of the rectangle would be _height * width_ or in other words, _(y2−y1)*(x2−x1)_. We can calculate the area of both rectangles and sum it together.

But, the rectangles could potentially have an overlap between them. This means we might be counting the overlapping area twice, which should have been added only once. So, to get the final answer, we need to subtract the overlapping area from the total area.

![image](https://github.com/user-attachments/assets/cdee3d29-f7cb-4c91-9c17-12b1717510c6)

Finding the overlap
To find the overlap, we need to find the width and height of the overlapping area (if there is any). We can get the width by finding the overlap in the horizontal or _x_ direction. _height_ can be calculated by finding the overlap in the _y_ direction.

To find the x overlap, let's think about the projection made by the corners of the rectangles on the x-axis. In other words, draw a line perpendicular to the x-axis from both rectangles' bottom left and top right corners. We mark the points at which these lines meet the x-axis. We can see that these points create two line segments - one formed by _(ax1,0)_,_(ax2,0)_, and the other one formed by _(bx1,0),(bx2,0)_.

![image](https://github.com/user-attachments/assets/38f99e6e-346c-4ece-82eb-f127afd8d4e6)

Now, finding x overlap is equivalent to finding the intersection of these two line segments.

![image](https://github.com/user-attachments/assets/93269546-ee47-4b27-a168-0af2149801e7)

![image](https://github.com/user-attachments/assets/528ac897-6fab-4d4c-854c-d8f23e3d90ea)

From the image above, we can see that if there is an overlap, _min(ax2,bx2)−max(ax1,bx1)_ will be a positive quantity equal to the _x_ overlap of the two rectangles. If the amount is negative or _0_, there is no overlap between the two lines (and rectangles).

_xOverlap = min(ax2,bx2) − max(ax1,bx1)_

In a similar way, we can find the y overlap of the two rectangles.

_yOverlap = min(ay2, by2) − max(ay1, by1)_

The area of the overlap _overlap = xOverlap_ ∗ _yOverlap_.

The total area considering the overlap between the two rectangles: _area = areaA + areaB − overlap_

#### Algorithm
1. We are given four points - _ax1, ay1, ax2, ay2_ and _bx1, by1, bx2, by2_.

2. Calculate _areaA_ and _areaB_ by multiplying width and height of the respective rectangles.

3. Calculate the _x_ overlap:

 	- **xOverlap** = _min(ax2, bx2) − max(ax1, bx1)_

4. Calculate the _y_ overlap:

 	- **yOverlap** = _min(ay2, by2) − max(ay1, by1)_

5. If _xOverlap_ and _yOverlap_, both are positive, multiply _x_ and _y_ overlaps to get the area of the overlap. Otherwise, it is **0**.

6. Calculate the total area as - _areaA + areaB − overlap_.

7. Return the **total area**.


