#pragma once
#include <vector>
#include "GameObject.h"
#include <fstream>
#include <iostream>
#include <string>

struct SaveSystem
{
public:
	SaveSystem();
	~SaveSystem();

	void SaveSystem::Write(GameObject* _test1, GameObject* _test2, GameObject* _test3);
	bool SaveSystem::Read(GameObject* _test1, GameObject* _test2, GameObject* _test3);
	std::vector<GameObject*> objects;
};