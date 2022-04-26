#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

template <typename T>
inline void print_one(const T& t)
{
	std::cout << t;
}

inline void print_one(const bool t)
{
	std::cout << (t ? "True" : "False");
}

template <typename T>
inline void print(const T& t)
{
	print_one(t);
	std::cout << std::endl;
}

template<typename T, typename... Args>
inline void print(const T& t, Args... args)
{
	print_one(t);
	std::cout << " ";
	print(args...);
}

inline std::vector<std::string> get_tokens(const std::string& line)
{
	std::vector<std::string> vec;
	std::string delimiter = " ";

	size_t pos = 0;
	std::string token;

	size_t pointer = 0;
	size_t stop;
	while ((stop = line.find(' ', pointer)) != std::string::npos) {
		std::string tmp = line.substr(pointer, stop - pointer);
		vec.push_back(tmp);
		pointer = stop + 1;
	}
	vec.push_back(line.substr(pointer, stop - pointer));

	return vec;
}

inline char** make_argv(const std::string& line, int& count)
{
	std::vector<std::string> tokens = get_tokens(line);
	count = tokens.size();
	char** argv = new char* [tokens.size()];
	
	for (int i = 0; i < tokens.size(); i++) {
		argv[i] = new char[tokens[i].size() + 1];
		strcpy_s(argv[i], tokens[i].size() + 1, tokens[i].c_str());
	}

	return argv;
}

inline std::string environment(const std::string& variable_name)
{
	char* buffer = nullptr;
	size_t size;
	_dupenv_s(&buffer, &size, variable_name.c_str());
	if (size == 0) {
		delete[] buffer;
		return std::string("");
	}
	else {
		std::string ret(buffer);
		delete[] buffer;
		return ret;
	}
}