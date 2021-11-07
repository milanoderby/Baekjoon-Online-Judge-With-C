/*
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 1001;

class Member{
private:
	int age;
	string name;
public:
	int getAge() {
		return age;
	}
	string getName() {
		return name;
	}
	void setAge(int n) {
		age = n;
	}
	void setName(string str) {
		name = str;
	}
	void setMember(Member m) {
		age = m.getAge();
		name = m.getName();
	}
};

void Merging(Member arr[], int s1, int e1, int s2, int e2) {
	int i, j;
	int inx = s1;
	Member result[SIZE];
	for (i = s1, j = s2; i <= e1 && j <= e2; inx++) {
		int a = arr[i].getAge();
		int b = arr[j].getAge();
		if (a <= b) {
			result[inx].setMember(arr[i]);
			i++;
		}
		else {
			result[inx].setMember(arr[j]);
			j++;
		}
	}

	int s, e;
	if (i>e1) {
		s = j;
		e = e2;
	}
	else {
		s = i;
		e = e1;
	}

	for (; s <= e; s++, inx++) {
		result[inx].setMember(arr[s]);
	}

	for (int k = s1; k <= e2; k++) {
		arr[k].setMember(result[k]);
	}
}

void MergeSort(Member arr[], int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	MergeSort(arr, start, mid);
	MergeSort(arr, mid+1, end);
	Merging(arr, start, mid, mid+1, end);
}

int main(void) {
	int N;
	cin >> N;
	
	Member arr[SIZE];
	for (int i = 0; i < N; i++) {
		int n;
		string str;
		cin >> n >> str;
		arr[i].setAge(n);
		arr[i].setName(str);
	}

	MergeSort(arr,0,N-1);
	
	for (int i = 0; i < N; i++) {
		cout << arr[i].getAge() << ' ' << arr[i].getName() << '\n';
	}
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int dirMAX = 4;
const int heightMAX = -1;
const int distMAX = 101;
int R, C;
struct Position {
	int x = -1;
	int y = -1;

	void moveUp() {
		if (y > 0) {
			y--;
		}
	}
	void moveDown() {
		if (y < R - 1) {
			y++;
		}
	}
	void moveLeft() {
		if (x > 0) {
			x--;
		}
	}
	void moveRight() {
		if (x < C - 1) {
			x++;
		}
	}
};
vector<vector<char>> myMap;
void BFS(int posY, int posX, vector<Position>& cluster, vector<vector<bool>>& visited) {
	visited[posY][posX] = true;
	struct Position pos;
	pos.y = posY;
	pos.x = posX;
	queue<Position> myQ;
	myQ.push(pos);
	cluster.push_back(pos);
	visited[pos.y][pos.x] = true;

	while (!myQ.empty()) {
		struct Position tmp = myQ.front();
		myQ.pop();

		for (int movDir = 0; movDir < dirMAX; movDir++) {
			struct Position next = tmp;
			switch (movDir) {
			case 0:
				next.moveUp();
				break;
			case 1:
				next.moveDown();
				break;
			case 2:
				next.moveLeft();
				break;
			case 3:
				next.moveRight();
				break;
			}

			if (!visited[next.y][next.x] && myMap[next.y][next.x] == 'x') {
				visited[next.y][next.x] = true;
				myQ.push(next);
				cluster.push_back(next);
			}
		}
	}
}

int getMinDist(vector<Position>& cluster, vector<vector<bool>>& visited) {
	int minDist = distMAX;
	for (int i = 0; i < cluster.size(); i++) {
		struct Position pos = cluster[i];

		if (pos.y == R - 1) {
			return 0;
		}

		int dist;
		bool found = false;
		for (int j = pos.y + 1; j < R; j++) {
			if (myMap[j][pos.x] == 'x' && !visited[j][pos.x]) {
				dist = j - (pos.y + 1);
				found = true;
				break;
			}
		}

		if (found == false) {
			dist = R - (pos.y + 1);
		}

		if (minDist > dist) {
			minDist = dist;
		}
	}

	return minDist;
}

void fallMineral(vector<Position>& cluster, int minDist) {
	for (int i = 0; i < cluster.size(); i++) {
		struct Position fell = cluster[i];
		myMap[fell.y][fell.x] = '.';
	}

	for (int i = 0; i < cluster.size(); i++) {
		struct Position fell = cluster[i];
		myMap[fell.y + minDist][fell.x] = 'x';
	}
}

void printMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << myMap[i][j];
		}
		cout << '\n';
	}
}

int main(void) {
	cin >> R >> C;
	myMap.assign(R, vector<char>(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> myMap[i][j];
		}
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		int movDir;
		struct Position destroy;
		if (i % 2 == 0) {
			movDir = 1;
			for (int j = 0; j < C; j++) {
				if (myMap[R - h][j] == 'x') {
					destroy.y = R - h;
					destroy.x = j;
					break;
				}
			}
		}
		else {
			movDir = -1;
			for (int j = C - 1; j >= 0; j--) {
				if (myMap[R - h][j] == 'x') {
					destroy.y = R - h;
					destroy.x = j;
					break;
				}
			}
		}
		if (destroy.y == -1 && destroy.x == -1) {
			continue;
		}
		myMap[destroy.y][destroy.x] = '.';

		//printMap();
		//cout<<endl;

		if (0 <= destroy.x + movDir && destroy.x + movDir < C) {
			if (myMap[destroy.y][destroy.x + movDir] == 'x') {
				vector<Position> cluster;
				vector<vector<bool>> visited(R, vector<bool>(C, false));
				BFS(destroy.y, destroy.x + movDir, cluster, visited);
				int minDist = getMinDist(cluster, visited);
				fallMineral(cluster, minDist);
			}
		}
		
		if (0 <= destroy.y - 1) {
			if (myMap[destroy.y - 1][destroy.x] == 'x') {
				vector<Position> cluster;
				vector<vector<bool>> visited(R, vector<bool>(C, false));
				BFS(destroy.y - 1, destroy.x, cluster, visited);
				int minDist = getMinDist(cluster, visited);
				fallMineral(cluster, minDist);
			}
		}

		if (destroy.y + 1 < R) {
			if (myMap[destroy.y + 1][destroy.x] == 'x') {
				vector<Position> cluster;
				vector<vector<bool>> visited(R, vector<bool>(C, false));
				BFS(destroy.y + 1, destroy.x, cluster, visited);
				int minDist = getMinDist(cluster, visited);
				fallMineral(cluster, minDist);
			}
		}
	}
	printMap();

	return 0;
}