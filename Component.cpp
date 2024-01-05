#include "Component.h"

Component::~Component(){}

bool Component::operator==(const Component& other) const {
	return id == other.id;
}

std::string Component::getId() const {
	return id;
}

void Component::Update(float deltaTime){}
void Component::DelayedUpdate(float deltaTime){}
