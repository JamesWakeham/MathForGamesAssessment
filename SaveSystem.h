#pragma once
#include <vector>
#include "GameObject.h"
#include <fstream>
#include <iostream>

struct SaveSystem
{
public:
	SaveSystem();
	~SaveSystem();

	void SaveSystem::Write(const std::string& file_name);
	bool SaveSystem::Read(const std::string& file_name);
	std::vector<GameObject*> objects;
};