#pragma once
#include <string>

using namespace std;

class Scene
{
private:
	string name;

public:

	Scene(string name);
	~Scene();

	virtual void Load();
	void Run();
	void Unload();

	string GetName();
};

