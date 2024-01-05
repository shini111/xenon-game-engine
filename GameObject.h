#pragma once
#include "Vec2.h"
#include "Transform.h"
#include "ECS.h"

class GameObject {
public:
	Transform transform;

	virtual void Update(float deltaTime) {
		transform.DisplayTransform();
	}

	virtual void DelayedUpdate(float deltaTime) {
	}

	virtual ~GameObject() {}
};

