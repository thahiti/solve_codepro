#include <iostream>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

map<int, int> cnt;

int N;//제품 수
struct st{
	int X, ID;//위치, 아이디
};
st A[50010];

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> A[i].X >> A[i].ID;
		int id = A[i].ID;
		if(cnt.count(id) == 0)
			cnt[id] = 0;
	}
}

bool cmp(const st & a, const st & b){
	return a.X < b.X;
}

void print_item(){
	for(int i=0; i<N; ++i){
		cout<<"x: "<<A[i].X<<" id: "<<A[i].ID<<endl;
	}
}

bool is_satisfied(){
	map<int, int>::iterator itr;
	for(itr = cnt.begin(); itr != cnt.end(); ++itr){
		if(0 == itr->second){
			//cout<<"not satisfied for ID"<< itr->first<<" is 0"<<endl;
			return false;
		}
	}
	return true;
}

//처음의 아이템
int start_idx = 0;
//마지막 다음의 아이템
int end_idx = 0;

bool remove_item(){
	if(end_idx == start_idx)
		return false;
	int id = A[start_idx++].ID;
	cnt[id]--;
	return true;
}

bool add_item(){
	if(end_idx == N)
		return false;
	int id = A[end_idx++].ID;
	cnt[id]++;
	return true;
}

int Solve(){
	sort(A, A+N, cmp);
	int min_width = numeric_limits<int>::max();
	for(int i=0; i<N*10; ++i){
		if(is_satisfied()){
			//cout<<"satisfied "<< A[start_idx].X <<" to "<<A[end_idx-1].X<<endl;
			int now_width = A[end_idx-1].X - A[start_idx].X;
			min_width = min(min_width, now_width);
			remove_item();
		}else{
			if(!add_item())
				break;
		}
	}

	return min_width;
}

int main(){
	int ans = -1;
	InputData();			//	입력 함수
	cout << Solve() << endl;	//	정답 출력
	return 0;
}

