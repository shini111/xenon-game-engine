#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class Component
{
public:
	Component(const std::string& id) : id(id) {}
	
	virtual ~Component();

	bool operator==(const Component& other) const;

	friend std::hash<Component>;

	std::string getId() const;

	virtual void Update(float deltaTime);
	virtual void DelayedUpdate(float deltaTime);

private:
	std::string id;
};

namespace std {
	template <>
	struct hash<Component> {
		size_t operator()(const Component& comp) const {
			return std::hash<std::string>()(comp.id);
		}
	};
}