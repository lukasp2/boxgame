#pragma once 
#include <string> 
#include <unordered_map> 
#include <utility> 
#include <stdexcept> 
#include <SFML/Graphics.hpp> 
#include <memory>

using namespace std::literals;

class Resource_Error : public std::logic_error {
	using std::logic_error::logic_error;
};

template <typename T>
class Resources
{
public:
	//Loads file into memory
	static T& load(const std::string& name);

private:
	//Stored resources
	static std::unordered_map < std::string, std::unique_ptr<T>> table;
};

// alias för bättre läsning av kod
using Texture_Manager = Resources<sf::Texture>;
using Font_Manager = Resources<sf::Font>;

template <typename T>
T & Resources<T>::load(const std::string & name)
{
	// Check if already loaded
	auto it = table.find(name);
	if (it == table.end()) { // if not load it

		std::unique_ptr<T> tmp{ std::make_unique<T>() };

		if (!tmp->loadFromFile(name)) {
			throw Resource_Error{ "Unable to load file '"s + name + "'" };
		}
		it = table.insert(std::make_pair(name, std::move(tmp))).first;
	}
	return *(it->second);
}

template <typename T>
std::unordered_map<std::string, std::unique_ptr<T>> Resources<T>::table{ };

