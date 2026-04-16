# [Platinum V] Double Derangement - 33067 

[문제 링크](https://www.acmicpc.net/problem/33067) 

### 성능 요약

메모리: 10724 KB, 시간: 324 ms

### 분류

다이나믹 프로그래밍, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2026년 04월 16일 09:38:56

### 문제 설명

<p>You are given two permutations $a$ and $b$, each of length $N$ containing every integer in the range $[1,N]$. Your task is to construct a new permutation $c$ of length $N$ that contains every integer in the range $[1,N]$, such that for every index $i$ ($1$-indexed), the following condition is satisfied:</p>

<p>\[c_i \neq a_i \quad \text{and} \quad c_i \neq b_i.\]</p>

<p>In other words, for no index $i$ can $c_i$ be equal to $a_i$ or $b_i$​.</p>

<p>Given the permutations $a$ and $b$, determine how many such permutations $c$ exist.</p>

### 입력 

 <p>The first line of input contains a single integer $T$, denoting the number of test cases.</p>

<p>For each test case, the input is as follows:</p>

<ul>
	<li>The first line of each test case contains a single integer, $N$, denoting the length of the permutations. ($1 \le N \le 16$)</li>
	<li>The next line contains $N$ space-separated integers, denoting the permutation $a$. Here, the $i$-th integer denotes $a_i$​. ($1 \le a_i \le N;$ $i \ne j \rightarrow a_i \ne a_j$​)</li>
	<li>The next line contains $N$ space-separated integers, denoting the permutation $b$. Here, the $i$-th integer denotes $b_i$​. ($1 \le b_i \le N;$ $i \ne j \rightarrow b_i \ne b_j$)</li>
</ul>

<p>Sum of $N$ over all cases $\le 2\,000$.</p>

### 출력 

 <p>Output how many such permutations $c$ described in the problem exist.</p>

