<h2><a href="https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>3020. Find the Maximum Number of Elements in Subset</a></h2><h3>Medium</h3><hr><div><p>You are given an array of <strong>positive</strong> integers <code>nums</code>.</p>

<p>You need to select a <span data-keyword="subset">subset</span> of <code>nums</code> which satisfies the following condition:</p>

<ul>
	<li>You can place the selected elements in a <strong>0-indexed</strong> array such that it follows the pattern: <code>[x, x<sup>2</sup>, x<sup>4</sup>, ..., x<sup>k/2</sup>, x<sup>k</sup>, x<sup>k/2</sup>, ..., x<sup>4</sup>, x<sup>2</sup>, x]</code> (<strong>Note</strong> that <code>k</code> can be be any <strong>non-negative</strong> power of <code>2</code>). For example, <code>[2, 4, 16, 4, 2]</code> and <code>[3, 9, 3]</code> follow the pattern while <code>[2, 4, 8, 4, 2]</code> does not.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> number of elements in a subset that satisfies these conditions.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [5,4,1,2,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can select the subset {4,2,2}, which can be placed in the array as [2,4,2] which follows the pattern and 2<sup>2</sup> == 4. Hence the answer is 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,2,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can select the subset {1}, which can be placed in the array as [1] which follows the pattern. Hence the answer is 1. Note that we could have also selected the subsets {2}, {4}, or {3}, there may be multiple subsets which provide the same answer. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>