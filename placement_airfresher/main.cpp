#include <iostream>
using namespace std;
//#define LOG printf
#define LOG
int H;		// ���� ũ��
int W;		// ���� ũ��
int map[50][50];	//����

struct ANS{
	int count;	// room ����
	int area;		// ���� ���� room ����
};

void InputData(){
	int i, j;
	cin >> H;
	cin >> W;
	for(i=0 ; i<H ; i++){
		for(j=0 ; j<W ; j++){
			cin >> map[i][j];
		}
	}
}

int visit[50][50]={0, };
int mask[] = {1, 2, 4, 8};
int xd[] = {-1, 0, 1, 0};
int yd[] = {0, -1, 0, 1};
int traverse(int x, int y, int id){
	int visit_count = 0;
	if(0 != visit[y][x])
		return visit_count;
	visit[y][x]=id;
	visit_count++;
	LOG("%d,%d = %d\n", x, y, id);
	for(int i=0; i < 4; ++i){
		LOG("mask: %d map: %d result: %d\n", mask[i], map[y][x], mask[i] & map[y][x]);
		if(0 == (mask[i] & map[y][x])){
			visit_count += traverse(x+xd[i], y+yd[i], id);
		}
	}
	return visit_count;
}

int main(){
	ANS ans = {0, 0};

	InputData();			//	�Է� �Լ�

	int id = 1;
	int max_visit_count = 0;
	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){
			if(0 == visit[i][j]){
				LOG("start visit at %d,%d id: %d\n", j, i, id);
				int visit_count = traverse(j, i, id);
				if(visit_count > max_visit_count)
					max_visit_count = visit_count;
				LOG("visit count for id: %d is : %d\n", id, visit_count);
				id++;
			}
		}
	}
	//	�ڵ带 �ۼ��ϼ���

	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){
			LOG("%d ", visit[i][j]);
		}
		LOG("\n");
	}

	ans.count = id-1;
	ans.area = max_visit_count;
	cout << ans.count << endl;	//	���� ���
	cout << ans.area << endl;		//	���� ���
	return 0;
}

