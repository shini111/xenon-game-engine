#pragma once
#include "Component.h"
#include <iostream>
#include <unordered_map>
#include <string>

class ECS
{
private:
	std::unordered_map<class Component, std::string> elements;
	int nextKey;

public:
	ECS() : nextKey(1) {}

	~ECS();

	void addElements(const Component& component, const std::string& element);

	void removeElement(const Component& component);
	
	void displayElements();

	void clear();
};

