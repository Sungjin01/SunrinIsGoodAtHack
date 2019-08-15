#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "ConsoleFunctions.h"

enum SceneType {
	TitleScene = 0,
	GamePrepare,
	GameScene,
	GameRule,
	EndScene
};

class Scene
{
private:
	SceneType now;
	int nowY;
	int cnt, cntMission[3];
	int clearPer;
	int capturePer;
	char base[3][20];
	bool isCleared;
	const char gameRule[18][80] = { "해킹을 시도하다 감옥에 갇힐 위기에 빠진 김선린을 구해주세요!", "평소에 정보윤리관 부족한 김선린은 해킹을 시도하다", "경찰에 검거될 위기에 처했습니다.", "", "오직 당신만이 김선린을 막장 인생에서 구해낼 수 있습니다.", "게임을 시작하면 몇가지 질문이 주어집니다.",
	"질문에 대답하면 게임이 시작됩니다.", " ", "게임이 시작하면, 우측 에는 검거도와 해킹 달성도가 나타나며  ", "그 아래에는 미션이 보여집니다." , "미션을 해결하기 위해서 당신은", "2초동안 미션란에 주어진 숫자 만큼만 아무 키나 입력하면 됩니다." ,
		"주어진 숫자보다 더 많거나 적게 입력하게 되면 검거도가 올라가며," , "검거도가 100이 되면 당신의 친구 김선린이 검거됩니다.", "반대로, 미션을 일정 횟수 이상 클리어하여 해킹달성도가 100이 되면",
	"당신의 친구 김선린은 구원받게 됩니다.", "", "스페이스바를 누르면 메인화면으로 돌아갑니다..."};
	char gamePrepare[4][80] = { "김선린은 무얼 해킹하고 있었죠? : ", "그것에 대한 키워드 한가지를 알려주실 수 있나요?(영어로) : ", "당신의 현재 소지금을 알려주세요 :", "마지막으로, 그곳의 보안은 어느정도 인가요?(1, 2, 3으로 구별) :" };
	char randString[10][20] = { "C:\> ", "Status..........: ", "Progress........: ", "Rejected........: ", "msconfig ", "192.168.0.1 ", "MS05 - 001 ", "Connection", "SQL Injection ", "Running" };

public:
	Scene();
	Scene(SceneType type);
	~Scene();

	void Update();
	void ShowTitle();
	void SetSceneType(SceneType type);
	void TitleScene();
	void GamePrepare();
	void GameScene(float time);
	void GameSceneSet();
	void GameSceneClear(float time);
	void GameRule();
	void EndScene();
	void EndSceneSet();
};

