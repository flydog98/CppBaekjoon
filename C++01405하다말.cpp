// 1405번 미친 로봇

#include <iostream>
#include <string.h>

using namespace std;

int amount = 0;
double simple = 0;// 단순한 경우를 저장
double pp[4]; // pp에는 차례로 동, 서, 남, 북으로 이동할 확률이 저장됩니다.
int map[29][29]; // 이곳에는 현재 dfs가 방문한 장소가 저장됩니다.
int ewnsx[4] = { 1, -1, 0, 0 };
int ewnsy[4] = { 0, 0, -1, 1 };

void dfs(double now, int x, int y) { // now에는 현재 칸까지 이동했을 확률, x, y는 현재의 좌표를 나타냅니다.
	int gox = 0, goy = 0;

	if (map[x][y] == amount) { // amount만큼 움직였다면
		simple += now; // simple한 경우이므로 현재 확률을 simple에 더한다
		map[x][y] = 0;
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		gox = x + ewnsx[i], goy = y + ewnsy[i]; // 방문하고자 하는 곳의 x, y좌표
		if (!map[gox][goy]) { // map[gox][goy]를 방문하지 않았다면
			map[gox][goy] = map[x][y] + 1;
			dfs(now*pp[i], gox, goy);
			// map[gox][goy]를 방문한 경우는 아무 행동을 취할 필요가 없다
		}
	}

	map[x][y] = 0; // 이번 칸에서 출발하는 dfs가 끝남
}

int main(void) {
	memset(map, 0, sizeof(map));

	cin >> amount >> pp[0] >> pp[1] >> pp[2] >> pp[3];

	for (int i = 0; i < 4; i++) pp[i] *= 0.01;

	dfs(1, 14, 14);

	printf("%.10lf\n", simple);

	return 0;
}