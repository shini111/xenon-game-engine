#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class Component
{
public:
	Component(const std::string& id) : id(id) {}
	
	~Component();

	bool operator==(const Component& other) const;

	friend std::hash<Component>;

	std::string getId() const;

private:
	std::string id;
};

namespace std {
	template <>
	struct hash<Component> {
		size_t operator()(const Component& comp) const {
			return hash<string>()(comp.id);
		}
	};
}