#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class person {
public:
	int height;
	int weight;
	int place = 1;

};



int main() {
	int n;
	cin >> n;
	vector<person> people;
	vector<person> output;
	for (int i = 0; i < n; i++) {
		person temp;
		cin >> temp.weight >> temp.height;
		people.push_back(temp);
	}
	for(int i=0;i<n;i++){
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else {
				if (people[i].height > people[j].height && people[i].weight > people[j].weight){
					people[j].place++;
				}
			}
		}
	}



	for (const auto& person : people) {
		cout << person.place << " ";
	}
	return 0;

}