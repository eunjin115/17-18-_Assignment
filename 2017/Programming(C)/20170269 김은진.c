/*********************소프트웨어학부 20170269 김은진*****
 *********************볼링 점수 계산 프로그램************/
#include <stdio.h>
#include <stdlib.h>
int num(char);
void cal(char**);
int main() {
	char y, tmp;
	char **player;
	int i = 0, j = 0, k = 0, u = 0;
	player = (char**)calloc(10, sizeof(char*)); //10행을 동적메모리로 할당 받음
	for (i = 0; i < 9;) { //9프레임까지의 메모리를 할당 받아 데이터를 넣음
		y = getchar();
		if (j == 1) { //각 프레임 중 두번째 투구에 데이터를 넣음
			*(*(player + i) + 1) = y;
			j = 0;
			i++;
			continue;
		}
		if ((y >= '0') && (y <= '9')) { //첫 번째 투구의 점수가 숫자일때
			*(player + i) = (char*)calloc(2, sizeof(char));
			*(*(player + i) + 0) = y;
			j++;
		}
		else if (y == 'x') { //첫 번째 투구가 스트라이크 일때 
			*(player + i) = (char*)calloc(2, sizeof(char));
			*(*(player + i) + 0) = y;
			*(*(player + i) + 1) = 0;
			j = 0;
			i++;
			continue;
		}
	}
	i = 9; //10번째 프레임의동적메모리 할당과 데이터를 넣음
	for (j = 0; j < 4; ) {
		y = getchar();
		if (y == '\n') {
			break;
		}
		if (y >= '0'&&y <= '9') { //첫 투구가 숫자였을때
			k = 0;
			*(player + i) = (char*)calloc(3, sizeof(char));
			*(*(player + i) + 0) = y;
			while (1) {
				y = getchar();
				if (k == 0) {
					if (y >= '0'&&y <= '9') { // 두 번째 투구도 숫자일시 세 번째 투구 자리에는 0을 넣음
						*(*(player + i) + 1) = y;
						*(*(player + i) + 2) = 0;
						break;
					}
					else if (y == 'x') { //두 번째 투구에서 스트라이크를 쳤을 경우
						*(*(player + i) + 1) = y;
						k++;
						continue;
					}
					else if (y == '/') { // 두 번째 투구에서 스페어를 쳤을 경우
						*(*(player + i) + 1) = y;
						k++;
						continue;
					}
				}
				else if (k == 1) { // 세 번째 점수를 입력받는 경우 - 스페어, 스트라이크
					if (y >= '0'&&y <= '9') {
						*(*(player + i) + 2) = y;
						k = 0;
						break;
					}
					else if (y == 'x') {
						*(*(player + i) + 2) = y;
						k = 0;
						break;
					}
					else if (y == '/') {
						*(*(player + i) + 2) = y;
						k = 0;
						break;
					}
				}
			}
			break;
		}
		if (y == 'x') { //처음 투구부터 스트라이크를 쳤을 경우 세번째 투구에 점수를 넣는다.
			k = 0;
			*(player + i) = (char*)calloc(3, sizeof(char));
			*(*(player + i) + 0) = y;
			while (1) {
				y = getchar();
				if (k == 0) {
					if (y >= '0'&&y <= '9') {
						*(*(player + i) + 1) = y;
						k++;
						continue;
					}
					else if (y == 'x') {
						*(*(player + i) + 1) = y;
						k++;
						continue;
					}
				}
				else if (k == 1) {
					if (y >= '0'&&y <= '9') {
						*(*(player + i) + 2) = y;
						k = 0;
						break;
					}
					else if (y == 'x') {
						*(*(player + i) + 2) = y;
						k = 0;
						break;
					}
					else if (y == '/') {
						*(*(player + i) + 2) = y;
						k = 0;
						break;
					}
				}
			}
		}
		break;
	}
	cal(player); //점수를 계산하는 함수이며 total을 출력하는 함수이다. 
	return 0;
}

void cal(char** player) {
	int total = 0, i = 0, j = 0, mid = 0, k = 0;
	char a;
	for (; i < 10; i++) { //각 프레임마다 점수를 계산한다.
		k = i;
		if (i != 9) { //9번째 프레임이 아닐경우
			while (1) {
				if (j == 0) {
					a = *(*(player + i) + j); //a에 문자를 넣는다.
					if (a >= '0'&&a <= '9') { //a에 따라 점수를계산한다. 숫자인 경우
						a = num(a);
						total += a;
						j++;
						continue;
					}
					else if (a == 'x') { // 점수가 스트라이크 인 경우
						total += 10;
						while (1) {
							if (*(*(player + (k + 1)) + 0) == 'x') { //다음프레임에도 스트라이크를친 경우
								total += 10;
								if (*(*(player + (k + 2)) + 1) == '/') {//세번째 뒤의  프레임에서 스페어가 존재하는 경우
									total += 10;
								}
								else { //그렇지 않고 숫자만 존재하는 경우
									total += num(*(*(player + (k + 2)) + 0));
									total += num(*(*(player + (k + 2)) + 1));
								}
								break;
							}
							else if (*(*(player + (k + 1)) + 1) == '/') { //다음 프레임에서 스페어가 존재하는 경우
								total += 10;
								break;
							}
							else { //숫자만 존재하는 경우
								total += num(*(*(player + (k + 1)) + 0));
								total += num(*(*(player + (k + 1)) + 1));
								break;
							}
							break;
						}
						break;
					}
				}
				else if (j == 1) { //스트라이크가 아닌 경우
					a = *(*(player + i) + 1);
					if (a == '/') { //스페어인 경우
						a = 10 - num(*(*(player + i) + 0));
						total += a;
						if (*(*(player + k + 1) + 0) == 'x') {
							total += 10;
						} // 다음 프레임에서 스트라이크를 친 경우
						else {
							total += num(*(*(player + k + 1) + 0));
						}
						j = 0;
						break;
					}
					else if (a >= '0'&&a <= '9') { //숫자만 존재하는 경우
						a = num(a);
						total += a;
						j = 0;
						break;
					}
				}
			}
		}
		else if (i == 9) {//10번째 프레임을 계산하는 경우
			for (j = 0; j < 3; j++) {
				a = *(*(player + 9) + j);
				if (a >= '0'&&a <= '9') { //숫자만 존재하는 경우 
					total += num(a);
				}
				else if (a == 'x') { //스트라이크인 경우 
					total += 10;
				}
				else if (a == '/') {//스페어인 경우
					total += 10 - num(*(*(player + 9) + j - 1));
				}
			}
		}
		continue;
	}
	printf("total : %d 점 ", total - 1);
}

int num(char a) { //문자를 숫자로 변환해주는 함수
	switch (a) {
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case '0': return 0;
	}
}
