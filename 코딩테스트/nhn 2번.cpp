#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

bool descending(pair<int, int> a, pair<int, int> b){
	return a.first > b.first;
}

void solution(int day, int width, int **blocks) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	
	int answer = 0;
	vector<int> tower(width, 0);
	
	for(int i = 0; i < day; i++){
		
		stack<pair<int, int>> s;
		vector<pair<int, int>> temp;
		
		for(int j = 0; j < width; j++){
			tower[j] += blocks[i][j];
			temp.push_back({tower[j], j});
		}
		
		sort(temp.begin(), temp.end(), descending);
		for(int j = 0; j < width; j++){
			s.push({temp[j].first, temp[j].second});
		}
		
		for(int j = 0; j < width; j++){
			cout << s.top().first << " " << s.top().second << '\n';
			s.pop();
		}
		
		// int curr = s.top().first;
		// int currIndex = s.top().second;
		// int next;
		// s.pop();
		
		// while(!s.empty()){
		// 	next = s.top().first;
		// 	answer += (next - curr);
		// 	tower[currIndex] = next;
		// 	currIndex = s.top().second;
		// 	curr = next;
		// 	s.pop();		
		// }
		
		temp.clear();
	
	}
	
	cout << answer;

}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}