#include "Scene.h"



Scene::Scene() {
	SetSceneType(SceneType::TitleScene);
	Update();
}

Scene::Scene(SceneType type)
{
	SetSceneType(type);
	Update();
}


Scene::~Scene()
{
}



void Scene::SetSceneType(SceneType type) {
	system("cls");
	switch (type) {
	case SceneType::TitleScene:
		ShowTitle();
		nowY = 20;
		break;
	case SceneType::GamePrepare:
		nowY = 0;
		break;
	case SceneType::GameScene:
		GameSceneSet();
		break;
	case SceneType::GameRule:
		nowY = 10;
		break;
	case SceneType::EndScene:
		nowY = 20;
		EndSceneSet();
		break;
	}
	now = type;
}

void Scene::Update() {
	clock_t start = clock();
	while (true) {
		switch (now) {
		case SceneType::TitleScene:
			TitleScene();
			break;
		case SceneType::GamePrepare:
			GamePrepare();
			break;
		case SceneType::GameScene:
			if ((clock() - start) / CLOCKS_PER_SEC > 3)start = clock();

			if ((clock() - start) / CLOCKS_PER_SEC < 2) {
				GameScene((float)(clock() - start) / CLOCKS_PER_SEC);
			}
			else {
				if (cnt == cntMission[0]) {
					clearPer += 2;
				}
				else {
					capturePer += 5;
				}
				srand(time(NULL));
				cntMission[0] = cntMission[1];
				cntMission[1] = cntMission[2];
				cntMission[2] = 10 + (rand() % 10);
				

				cnt = 0;
				start = clock();
			}
			
			if (clearPer >= 100) {
				isCleared = true;
				SetSceneType(SceneType::EndScene);
			}
				
			if (capturePer >= 100) {
				isCleared = false;
				SetSceneType(SceneType::EndScene);
			}
			break;
		case SceneType::GameRule:
			GameRule();
			Sleep(100);
			break;
		case SceneType::EndScene:
			EndScene();
			break;
		default:
			break;
		}
	}
}

/*
이하 Scene 함수들

TitleScene
GamePrepare
GameScene
GameRule
EndScene
*/

void Scene::EndSceneSet() {
	if (isCleared) {
		gotoxy(50, 10);
		std::cout << "김선린을 구해냈습니다!!" << std::endl;
		gotoxy(40, 20);
		std::cout << "타이틀 화면으로";
		gotoxy(40, 22);
		std::cout << "나가기";

		setCursorType(CursorType::CursorInvisible);
		gotoxy(50, 20);
		std::cout << "<<";
	}
	else {
		gotoxy(40, 10);
		std::cout << "김선린때문에 당신도 수감되었습니다." << std::endl;
		gotoxy(40, 20);
		std::cout << "타이틀 화면으로";
		gotoxy(40, 22);
		std::cout << "나가기";

		setCursorType(CursorType::CursorInvisible);
		gotoxy(60, 20);
		std::cout << "<<";
	}
}

//게임 씬 시작할 때 랜덤 3개 생성 
void Scene::GameSceneSet() {
	nowY = 0;
	capturePer = 0;
	clearPer = 0;
	cnt = 0;

	srand(time(NULL));
	cntMission[0] = 10 + (rand() % 10);
	cntMission[1] = 10 + (rand() % 10);
	cntMission[2] = 10 + (rand() % 10);

	GameSceneClear(1);
}

//게이지, 시간, 미션 출력
void Scene::GameSceneClear(float time) {
	if (nowY < 30) {
		for (int i = 13; i < 25; i++) {
			gotoxy(90, i);
			std::cout << "          ";
		}

		gotoxy(90, 14);
		std::cout << "달성도";
		gotoxy(90, 15);
		std::cout << clearPer << " %";
		gotoxy(90, 16);
		std::cout << "검거도";
		gotoxy(90, 17);
		std::cout << capturePer << " %";


		gotoxy(90, 20);
		std::cout << "                         ";
		gotoxy(90, 21);
		std::cout << "                         ";
		gotoxy(90, 22);
		std::cout << "                         ";
		gotoxy(90, 23);
		std::cout << "                         ";

		gotoxy(90, 20);
		std::cout << "남은 시간";
		gotoxy(90, 21);
		std::cout << 2 - time;
		gotoxy(90, 22);
		std::cout << "미션";
		gotoxy(90, 23);
		std::cout << cntMission[0] << "  " << cntMission[1] << "  " << cntMission[2];
		gotoxy(90, 24);
		std::cout << "클릭 : "<< cnt;
	}
	else {
		for (int i = -1; i < 10; i++) {
			gotoxy(90, i + nowY);
			std::cout << "          ";
		}

		gotoxy(90, 0 + nowY);
		std::cout << "달성도";
		gotoxy(90, 1 + nowY);
		std::cout << clearPer << " %";
		gotoxy(90, 2 + nowY);
		std::cout << "검거도";
		gotoxy(90, 3 + nowY);
		std::cout << capturePer << " %";


		gotoxy(90, 5 + nowY);
		std::cout << "                         ";
		gotoxy(90, 6 + nowY);
		std::cout << "                         ";
		gotoxy(90, 7 + nowY);
		std::cout << "                         ";
		gotoxy(90, 8 + nowY);
		std::cout << "                         ";

		gotoxy(90, 5 + nowY);
		std::cout << "남은 시간";
		gotoxy(90, 6 + nowY);
		std::cout << 2 - time;
		gotoxy(90, 7 + nowY);
		std::cout << "미션";
		gotoxy(90, 8 + nowY);
		std::cout << cntMission[0] << "  " << cntMission[1] << "  " << cntMission[2];\
		gotoxy(90, 9 + nowY);
		std::cout << "클릭 : " << cnt <<"   ";
	}
	

}

void Scene::ShowTitle() {
	gotoxy(50, 10);
	std::cout << "선린인은 해킹을 잘한다" << std::endl;
	gotoxy(40, 20);
	std::cout << "게임 시작";
	gotoxy(40, 22);
	std::cout << "게임 방법";
	gotoxy(40, 24);
	std::cout << "나가기";

	setCursorType(CursorType::CursorInvisible);
	gotoxy(50, 20);
	std::cout << "<<";
}

void Scene::TitleScene() {
	if (_kbhit()) {
		int key1 = _getch();
		if (key1 == 224) {
			int key = _getch();

			if (key == UP) {
				if (nowY == 20)
					return;
				gotoxy(50, nowY);
				printf("  ");
				nowY += -2;
				gotoxy(50, nowY);
				printf("<<");
			}
			else if (key == DOWN) {
				if (nowY == 24) 
					return;
				gotoxy(50, nowY);
				printf("  ");
				nowY += 2;
				gotoxy(50, nowY);
				printf("<<");
			}
		}
		else if (key1 == 13) {
			switch (nowY) {
			case 20:
				SetSceneType(SceneType::GamePrepare);
				break;
			case 22:
				SetSceneType(SceneType::GameRule);
				break;
			case 24:
				exit(1);
				break;
			}
		}
	}
}

void Scene::GamePrepare() {
	if (nowY >= 3) {
		SetSceneType(SceneType::GameScene);
		return;
	}
		

	gotoxy(20, 15);
	std::cout << "                                                                 ";
	gotoxy(20, 15);
	std::cout << gamePrepare[nowY];
	std::cin >> base[nowY];
	nowY++;
}

void Scene::GameScene(float _time = 0) {
	GameSceneClear(_time);
	if (_kbhit()) {
		_getch();
		cnt++;
		
		nowY++;
		gotoxy(0, nowY);
		
		
		for (int i = 0; i < (rand() % 5) + 3; i++) {
			if (rand() % 5 <= 1) {
				std::cout << base[rand() % 2];
			}
			else {
				std::cout << randString[rand() % 10];
			}
		}
		
	}
}

void Scene::GameRule() {
	if (_kbhit()) {
		if (_getch() == 32) {
			SetSceneType(SceneType::TitleScene);
			return;
		}
	}
	if (nowY > 27) //27  
		return;
	gotoxy(10, nowY);
	std::cout << gameRule[nowY - 10];
	nowY++;
}

void Scene::EndScene() {
	if (_kbhit()) {
		int key1 = _getch();
		if (key1 == 224) {
			int key = _getch();

			if (key == UP) {
				if (nowY == 20)
					return;
				gotoxy(60, nowY);
				printf("  ");
				nowY += -2;
				gotoxy(60, nowY);
				printf("<<");
			}
			else if (key == DOWN) {
				if (nowY == 22)
					return;
				gotoxy(60, nowY);
				printf("  ");
				nowY += 2;
				gotoxy(60, nowY);
				printf("<<");
			}
		}
		else if (key1 == 13) {
			switch (nowY) {
			case 20:
				SetSceneType(SceneType::TitleScene);
				break;
			case 22:
				exit(1);
				break;
			}
		}
	}
}

