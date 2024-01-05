#include "ECS.h"
#include "GameObject.h"

ECS::~ECS(){}

void ECS::addElements(std::shared_ptr<Component> component, const std::string& element) {
	elements[component] = element;
}

void ECS::removeElement(std::shared_ptr<Component> component) {
	auto it = elements.find(component);
	if (it != elements.end())
	{
		elements.erase(it);
	}
	else
	{
		std::cout << "Element with component not found." << std::endl;
	}
}

void ECS::displayElements() {
	std::cout << "EQS elements:" << std::endl;
	for (const auto& entry : elements) {
		std::cout << "Component ID: " << entry.first->getId() << " , Value: " << entry.second << std::endl;
	}
}

void ECS::clear() {
	elements.clear();
}

void ECS::UpdateAll(float deltaTime) {
	for (auto& entry : elements) {
		if (entry.first)
		{
			entry.first->Update(deltaTime);
		}
	}
}

void ECS::DelayedUpdateAll(float deltaTime) {
	for (auto& entry : elements) {
		if (entry.first)
		{
			entry.first->DelayedUpdate(deltaTime);
		}	
	}
}