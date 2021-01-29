#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[10][10];
int island[10][10];
int p[7];
vector<pair<int, pair<int, int>>> vt;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int getParent(int a) {
	if (p[a] == a) return a;
	return p[a] = getParent(p[a]);
}


void unionSet(int a, int b) {
	int rootA = getParent(a);
	int rootB = getParent(b);
	p[rootA] = rootB;
}


//u�� ������ v�� ������ ���� ���� �ִ� �Ÿ��� ���Ѵ�.
void makebridge(int u, int v) {
	queue < pair<int, int>> q;

	//u�� ���� �ִ� ĭ���� ��� ť�� �ִ´�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (island[i][j] == u) {
				q.push(make_pair(i, j));
			}
		}
	}

	int mindist = 10;
	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int dist = 0;

			//�ѹ������� ��� �̵�
			while (true) {
				//������ �Ѿ ���
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
				//���� ���ΰ�� �� Ž������ �ʴ´�.
				if (island[nx][ny] == u) break;

				if (island[nx][ny] == v) {
					//v������ ��� �ּҰŸ��� ���� �� Ž������ �ʴ´�.
					if (dist > 1 && mindist > dist) mindist = dist;
					break;
				}
				else if (island[nx][ny] == 0) {
					//�ٴ��� ��� �Ÿ������ϰ� �̵�
					dist++;
					nx += dx[k];
					ny += dy[k];
				}
				else {
					//�ٸ� ���� ��� �� Ž������ �ʴ´�.
					break;
				}

			}
		}
	}

	//�ּҰŸ��� �ʱⰪ�� �ƴ϶�� ���Ϳ� �ּҰŸ��� ���� ��ȣ�� �ִ´�.
	if (mindist != 10) vt.push_back(make_pair(mindist, make_pair(u, v)));
}


void bfs(int x, int y, int num) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	island[x][y] = num;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 0) continue;
			if (island[nx][ny] != 0) continue;

			q.push(make_pair(nx, ny));
			island[nx][ny] = num;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
		

	//���� ��ȣ�� ���δ�.
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			if (arr[i][j] == 0) continue;
			if (island[i][j] != 0) continue;
			bfs(i, j, ++num);
		}
	}


	//������ ��ȣ�� ���� num�� ���� ����
	//�� ���鰣�� ����� �ִ� �ٸ��� ��� �����.
	for (int i = 1; i <= num - 1; i++) {
		for (int j = i + 1; j <= num; j++) {
			makebridge(i, j);
		}
	}


	int size = vt.size();
	//�Ÿ��� �������� �������� ����
	sort(vt.begin(), vt.end());
	//�θ� �迭 �ʱ�ȭ(ó�� �θ�� �ڱ� �ڽ�)
	for (int i = 1; i <= num; i++) p[i] = i;

	int sum = 0;
	int cnt = 0;
	int index = 0;

	int u, v, dist;
	//������ ������ ������ ���ǰ��� -1�� �ɶ����� ������ �����Ѵ�.
	while (cnt < num - 1) {
		if (index == size) {
			//��� ���� �����ϴ� ���� �Ұ����ϴ�
			cout << -1 << "\n";
			return 0;
		}

		dist = vt[index].first;
		u = vt[index].second.first;
		v = vt[index].second.second;

		index++;
		if (getParent(u) == getParent(v)) {
			//�̹� ����Ǿ� �ִ�.
			continue;
		}
		else {
			//����Ǿ� ���� �ʴٸ� ��ģ��.
			unionSet(u, v);

			//����� ������ �� ����
			cnt++;

			//�ٸ� ���̿� �����ش�.
			sum += dist;
		}
	}

	cout << sum << '\n';

	return 0;
}
