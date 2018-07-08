#include <iostream>
using namespace std;

int N,Q;
int T[101];
int engineer[6];

void Input_Data(void){
	cin >> N >> Q;				// �����Ͼ��� ��, ���� ��
	for(int i=1;i<=Q;i++){
		cin >> T[i];				// ���� ����ó�� �ð�
	}
}

int get_empyt_eng(){
	for(int i=0; i<N; ++i){
		if(0 == engineer[i])
			return i;
	}
	return -1;
}

int client_idx = 1;
int get_next_client(){
	if(Q < client_idx )
		return 0;
	return T[client_idx++];
}

int update_engineer(){
	for(int i=0; i<N; ++i)
		if(0 < engineer[i])
			engineer[i]--;
}

int check_done(){
	for(int i=0; i<N; ++i)
		if(0 != engineer[i])
			return false;
	return true;
}

void print_status(){
	for(int i=0; i<N; ++i)
		printf("engineer status: %d\n", engineer[i]);
}

int main(void){
	int sol = 0;

	Input_Data();				// �Է� �Լ�

	for(int i=0; i<N; ++i){
		engineer[i] = 0;
	}
	//	�ڵ带 �ۼ��ϼ���
	while(1){
		int i;
		while(0 <= (i = get_empyt_eng())){
			int j = get_next_client();
			if(0 < j){
				engineer[i] = j;
			}else{
				break;
			}
		}
		update_engineer();
		sol++;

		if(check_done() && Q < client_idx)
			break;
	}

	cout << sol << endl;	// ���� ���
	return 0;
}
