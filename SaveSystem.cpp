#include "SaveSystem.h"


SaveSystem::SaveSystem()
{
}


SaveSystem::~SaveSystem()
{
}

void SaveSystem::Write(GameObject* _test1, GameObject* _test2, GameObject* _test3)
{
	std::ofstream myfile;
	myfile.open("test.txt");

	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			myfile << _test1->localTransform.value[i][x] << std::endl;
		}
	}	
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			myfile << _test2->localTransform.value[i][x] << std::endl;
		}
	}	
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			myfile << _test3->localTransform.value[i][x] << std::endl;
		}
	}
	myfile.close();
}

void SaveSystem::Read(GameObject* _test1, GameObject* _test2, GameObject* _test3)
{
	//float fds = atof(nextLine.c_str);
	std::ifstream myfile;
	myfile.open("test.txt");
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			std::string nextLine;
			std::getline(myfile, nextLine);
			_test1->localTransform.value[i][x] = atof(nextLine.c_str());
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			std::string nextLine;
			std::getline(myfile, nextLine);
			_test1->localTransform.value[i][x] = atof(nextLine.c_str());
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			std::string nextLine;
			std::getline(myfile, nextLine);
			_test1->localTransform.value[i][x] = atof(nextLine.c_str());
		}
	}

	myfile.close();
}