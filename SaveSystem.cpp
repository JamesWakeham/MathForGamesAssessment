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

	myfile << _test1->GetPos().x << std::endl;
	myfile << _test1->GetPos().y << std::endl;
	myfile << _test1->GetRot() << std::endl;
	myfile << _test1->GetScale().x << std::endl;
	myfile << _test1->GetScale().y << std::endl;

	myfile << _test2->GetPos().x << std::endl;
	myfile << _test2->GetPos().y << std::endl;
	myfile << _test2->GetRot() << std::endl;
	myfile << _test2->GetScale().x << std::endl;
	myfile << _test2->GetScale().y << std::endl;

	myfile << _test3->GetPos().x << std::endl;
	myfile << _test3->GetPos().y << std::endl;
	myfile << _test3->GetRot() << std::endl;
	myfile << _test3->GetScale().x << std::endl;
	myfile << _test3->GetScale().y << std::endl;

	myfile.close();
}

bool SaveSystem::Read(GameObject* _test1, GameObject* _test2, GameObject* _test3)
{
	//float fds = atof(nextLine.c_str);
	std::ifstream myfile;
	myfile.open("test.txt");

	if (myfile.is_open()) {
		std::string sx, sy;
		float x, y;

		std::getline(myfile, sx);
		std::getline(myfile, sy);
		x = atof(sx.c_str());
		y = atof(sy.c_str());
		_test1->Translate(MathFuncs::Vector2(x, y));

		std::getline(myfile, sx);
		x = atof(sx.c_str());
		_test1->Rotate(x);

		std::getline(myfile, sx);
		std::getline(myfile, sy);
		x = atof(sx.c_str());
		y = atof(sy.c_str());
		_test1->Scale(MathFuncs::Vector2(x, y));


		std::getline(myfile, sx);
		std::getline(myfile, sy);
		x = atof(sx.c_str());
		y = atof(sy.c_str());
		_test2->Translate(MathFuncs::Vector2(x, y));

		std::getline(myfile, sx);
		x = atof(sx.c_str());
		_test2->Rotate(x);

		std::getline(myfile, sx);
		std::getline(myfile, sy);
		x = atof(sx.c_str());
		y = atof(sy.c_str());
		_test2->Scale(MathFuncs::Vector2(x, y));


		std::getline(myfile, sx);
		std::getline(myfile, sy);
		x = atof(sx.c_str());
		y = atof(sy.c_str());
		_test3->Translate(MathFuncs::Vector2(x, y));

		std::getline(myfile, sx);
		x = atof(sx.c_str());
		_test3->Rotate(x);

		std::getline(myfile, sx);
		std::getline(myfile, sy);
		x = atof(sx.c_str());
		y = atof(sy.c_str());
		_test3->Scale(MathFuncs::Vector2(x, y));
		myfile.close();
		return true;
	}
	else
		return false;
}