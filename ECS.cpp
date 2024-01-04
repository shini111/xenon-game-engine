#include "ECS.h"


ECS::~ECS(){}

void ECS::addElements(const Component& component, const std::string& element) {
	elements[component] = element;
}

void ECS::removeElement(const Component& component) {
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
		std::cout << "Component ID: " << entry.first.getId() << " , Value: " << entry.second << std::endl;
	}
}

void ECS::clear() {
	elements.clear();
}