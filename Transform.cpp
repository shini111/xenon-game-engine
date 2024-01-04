#include "Transform.h"

Transform::Transform() : position(0.f,0.f), rotation(0.0f), scale(1.0f, 1.0f) {}

Transform::~Transform() {}

void Transform::Translate(const Vec2& translation) {
	position = position + translation;
}
void Transform::Rotate(float angle) {
	rotation += angle;
}

void Transform::Scale(const Vec2& scaling) {
	scale = scale * scaling;
}

void Transform::DisplayTransform() const {
	position.Log("Position: ");
	std::cout << "Rotation: " << rotation << std::endl;
	scale.Log("Scale: ");
}