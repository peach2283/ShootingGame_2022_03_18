#pragma once

class Scene
{
private:
public:

	Scene();
	~Scene();

	virtual void Load();
	void Run();
	void Unload();
};

