#include <cstdio>
#include <memory>

using namespace std;

int land[50][50];
int w = -1, h = -1, cnt;
int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void DFS(int x, int y)
{
	land[x][y] = 0;
	for(int i = 0; i < 8; i++)
		if(land[x+dx[i]][y+dy[i]] == 1 && x+dx[i] >= 0 && y+dy[i] >= 0 && x+dx[i] < h && y+dy[i] < w)
			DFS(x+dx[i], y+dy[i]);
}

int main()
{
	while(1)
	{
		scanf("%d %d", &w, &h);
		if(w == 0 && h == 0) break;
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				scanf("%d", &land[i][j]);

		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				if(land[i][j] == 1)
				{
					DFS(i, j);
					cnt++;
				}

		printf("%d\n", cnt);
		cnt = 0;
	}
}