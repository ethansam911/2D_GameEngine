//Entity component system
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;
using ComponentID = std::size_t;

inline ComponentID getComponentID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept
{
	static ComponentID typeID = getComponentID();
	return typeID();
}
//Mathematical components an npc is able to hold
//Compare the components so that we know its correct
constexpr std::size_t maxComponents = 32;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

//Our first class
class Component
{
public:
	Entity* entity;
	/*
	Virtual functions ensure that the correct function is 
	called for an object, regardless of the type of reference 
	(or pointer) used for function call. Functions are declared 
	with a virtual keyword in base class. The resolving of function
	call is done at Run-time.
	*/
	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}
	virtual	~Component() {}

};

//Our second class
class Entity
{
private:
	//if false remove it from the 
	//Need a list of the components that an entity holds
	bool active;
	// Think of a vector like an array with dynamic size
	/*
	(since C++11) std::unique_ptr is a smart pointer that 
	owns and manages another object through a pointer and 
	disposes of that object when the unique_ptr goes out of scope.
	*/
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	void update()
	{
		//Update the game screen
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}
	void draw() {}
	//const because this will never change
	bool isActive() const {return active;}
	void destroy() {active = false;}

};
