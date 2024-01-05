#pragma once
#include "GameObject.h"
#include "Component.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

class Component;

class ECS
{
private:
	std::unordered_map<std::shared_ptr<Component>, std::string> elements;
	int nextKey;

public:
	ECS() : nextKey(1) {}

	~ECS();

	void addElements(std::shared_ptr<Component> component, const std::string& element);

	void removeElement(std::shared_ptr<Component> component);
	
	void displayElements();

	void clear();

	void UpdateAll(float deltaTime);

	void DelayedUpdateAll(float deltaTime);
};

