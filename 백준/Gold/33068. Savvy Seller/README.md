# [Gold III] Savvy Seller - 33068 

[문제 링크](https://www.acmicpc.net/problem/33068) 

### 성능 요약

메모리: 5936 KB, 시간: 56 ms

### 분류

다이나믹 프로그래밍, 값 / 좌표 압축

### 제출 일자

2026년 04월 16일 09:38:56

### 문제 설명

<p>Hanbyeol is a seasoned sales representative. She has $N$ meeting opportunities with various companies and wants to select some of these meetings to attend. In her early career as a junior saleswoman, she aimed to attend as many meetings as possible. However, now, as a veteran, she knows which meetings are more important and which are less critical.</p>

<p><span style="box-sizing: border-box; margin: 0px; padding: 0px;">Hanbyeol knows the <strong>start and</strong> <strong>end times</strong> for each meeting and the <strong>expected profit</strong> she can earn by attending. If two meetings overlap in time, she cannot attend both. It is implied that meetings are considered overlapping only if one meeting's end time exceeds the next meeting's start time; meetings, where the end time of one equals the start time of the next, are allowed.</span></p>

<p>Write a program to help Hanbyeol create a meeting schedule that maximizes her total expected profit.</p>

### 입력 

 <p>The first line contains a single integer, $N$, denoting the meeting opportunities that Hanbyeol has. ($1 \le N \le 100\,000$)</p>

<p>The $i$-th of the next $N$ lines contain three space-separated integers: $s_i$ and $e_i$, denoting the starting and ending time of the $i$-th meeting, respectively, and $p_i$, denoting the expected profit Hanbyeol can earn by attending the $i$-th meeting. ($0 \le s < e \le 10^9;$ $1 \le p \le 10^9$)</p>

### 출력 

 <p>Output the total profit when Hanbyeol schedules her meetings optimally.</p>

