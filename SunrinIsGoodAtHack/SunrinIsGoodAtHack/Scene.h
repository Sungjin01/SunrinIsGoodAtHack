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
	const char gameRule[18][80] = { "��ŷ�� �õ��ϴ� ������ ���� ���⿡ ���� �輱���� �����ּ���!", "��ҿ� ���������� ������ �輱���� ��ŷ�� �õ��ϴ�", "������ �˰ŵ� ���⿡ ó�߽��ϴ�.", "", "���� ��Ÿ��� �輱���� ���� �λ����� ���س� �� �ֽ��ϴ�.", "������ �����ϸ� ��� ������ �־����ϴ�.",
	"������ ����ϸ� ������ ���۵˴ϴ�.", " ", "������ �����ϸ�, ���� ���� �˰ŵ��� ��ŷ �޼����� ��Ÿ����  ", "�� �Ʒ����� �̼��� �������ϴ�." , "�̼��� �ذ��ϱ� ���ؼ� �����", "2�ʵ��� �̼Ƕ��� �־��� ���� ��ŭ�� �ƹ� Ű�� �Է��ϸ� �˴ϴ�." ,
		"�־��� ���ں��� �� ���ų� ���� �Է��ϰ� �Ǹ� �˰ŵ��� �ö󰡸�," , "�˰ŵ��� 100�� �Ǹ� ����� ģ�� �輱���� �˰ŵ˴ϴ�.", "�ݴ��, �̼��� ���� Ƚ�� �̻� Ŭ�����Ͽ� ��ŷ�޼����� 100�� �Ǹ�",
	"����� ģ�� �輱���� �����ް� �˴ϴ�.", "", "�����̽��ٸ� ������ ����ȭ������ ���ư��ϴ�..."};
	char gamePrepare[4][80] = { "�輱���� ���� ��ŷ�ϰ� �־���? : ", "�װͿ� ���� Ű���� �Ѱ����� �˷��ֽ� �� �ֳ���?(�����) : ", "����� ���� �������� �˷��ּ��� :", "����������, �װ��� ������ ������� �ΰ���?(1, 2, 3���� ����) :" };
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

