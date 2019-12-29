#pragma once
class Entity;
class FieldObject;

class Cell {
public:
	FieldObject *field_;
	Entity *entity_;

	Cell();
};
