#include "Scene.h"



Scene::Scene()
{

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

		break;
	case SceneType::GameRule:
		nowY = 10;
		break;
	case SceneType::EndScene:
		break;
	}
	now = type;
}

void Scene::Update() {
	while (true) {
		switch (now) {
		case SceneType::TitleScene:
			TitleScene();
			break;
		case SceneType::GamePrepare:
			GamePrepare();
			break;
		case SceneType::GameScene:
			GameScene();
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
	if (nowY == 3)
		SetSceneType(SceneType::GameScene);

	gotoxy(20, 15);
	std::cout << gamePrepare[3];
	gotoxy(20, 15);
	std::cout << gamePrepare[nowY];
	_getch();
	nowY++;
}

void Scene::GameScene() {

}

void Scene::GameRule() {
	if (_kbhit()) {
		if (_getch() == 32) {
			SetSceneType(SceneType::TitleScene);
			return;
		}
	}
	if (nowY > 27)
		return;
	gotoxy(10, nowY);
	std::cout << gameRule[nowY - 10];
	nowY++;
}

void Scene::EndScene() {

}

