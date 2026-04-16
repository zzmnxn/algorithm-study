# [Silver I] Observing Objects - 33065 

[문제 링크](https://www.acmicpc.net/problem/33065) 

### 성능 요약

메모리: 14040 KB, 시간: 340 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 격자 그래프, 플러드 필

### 제출 일자

2026년 04월 16일 09:38:56

### 문제 설명

<p>In image processing fundamentals, determining the region where an object is located is crucial.</p>

<p>You are given a screen of size $N\times M$, consisting of $NM$ pixels. Each pixel at position $(i,j)$ has a specific RGB value represented by three integers: $R_{ij}$​ (Red), $G_{ij}$​ (Green), and $B_{ij}$​ (Blue). Each color component is an integer in the $[0,255]$ range.</p>

<p>The task is to identify the number of distinct objects on the screen. Two pixels are considered part of the same object if their RGB values are identical and connected in one of the $8$ possible directions: up, down, left, right, and the $4$ diagonals.</p>

<p>An object is defined as a group of connected pixels that meet the above criteria. Write a program to determine the number of distinct objects on the screen.</p>

### 입력 

 <p>The first line contains two space-separated integers, $N$ and $M$, denoting the size of the image. ($1 \le N,M \le 1\,000$)</p>

<p>The following $N$ lines contain $3NM$ integers, where each line has $3M$ space-separated integers, denoting the RGB value of each pixel. Here, the $3j$-th, the $(3j+1)$-th, and the $(3j+2)$-th integer of the $i$-th row denotes $R_{ij}$​, $G_{ij}$​, and $B_{ij}$​, respectively. ($0 \le R_{ij},G_{ij},B_{ij} \le 255$)</p>

### 출력 

 <p>Output the total number of distinct objects in the screen.</p>

