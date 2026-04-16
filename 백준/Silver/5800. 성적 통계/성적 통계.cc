#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int k;
	cin >> k;

	vector<vector<int>> outputs;

	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		vector<int> grades(n);

		for (int j = 0; j < n; j++) {
			cin >> grades[j];
		}
		sort(grades.begin(), grades.end()); //sort는 값 전달 x iterator!
		vector<int> gaps(n - 1);
		for (int l = 0; l < n - 1; l++) {
			gaps[l]=(grades[l + 1] - grades[l]);
		}
		sort(gaps.begin(), gaps.end());
		vector<int> temp = { grades[n - 1],grades[0],gaps[n-2]};
		
		outputs.push_back(temp);
	}

	for (int i = 0; i < k; i++) {
		cout << "Class " << i + 1 << "\n";
		cout <<"Max " << outputs[i][0] << ", ";
		cout << "Min " << outputs[i][1] << ", ";
		cout <<  "Largest gap " << outputs[i][2] << "\n";
	}
}