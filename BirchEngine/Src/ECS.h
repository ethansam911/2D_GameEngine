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

template <typename T> inline ComponentID getComponentTypeID() noexcept
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
		//Quick verson of a for loop
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}
	void draw() {}
	//const because this will never change
	bool isActive() const {return active;}
	void destroy() {active = false;}

	template <typename T> bool hasComponenet() const
	{
		return componentBitSet[getComponentID<T>];
	}
	
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&& ... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...))
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()]= c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	template<typename T> T& getComponent() const
	{
		auto ptr(ComponentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:

	void update()
	{
		for (auto& e : entities) e->update();
	}
	void draw()
	{
		for (auto& e : entities) e->draw();
	}
	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->isActive();
			}},
				std::end(entities));	
	}
	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };


	}
