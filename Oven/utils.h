#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

template <typename T>
inline void print_one(const T& t)
{
	cout << t;
}

inline void print_one(const bool t)
{
	cout << (t ? "True" : "False");
}

template <typename T>
inline void print(const T& t)
{
	print_one(t);
	cout << endl;
}

template<typename T, typename... Args>
inline void print(const T& t, Args... args)
{
	print_one(t);
	cout << " ";
	print(args...);
}

inline vector<string> get_tokens(const string& line)
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

inline char** make_argv(const string& line, int& count)
{
	vector<string> tokens = get_tokens(line);
	count = tokens.size();
	char** argv = new char* [tokens.size()];
	
	for (int i = 0; i < tokens.size(); i++) {
		argv[i] = new char[tokens[i].size() + 1];
		strcpy_s(argv[i], tokens[i].size() + 1, tokens[i].c_str());
	}

	return argv;
}