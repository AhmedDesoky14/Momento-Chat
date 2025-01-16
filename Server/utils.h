#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <any>
class file
{
private:
	const std::string filename;
public:
	explicit file(const std::string& filename) : filename(filename) {}	//explicit to avoid implicit conversions
	std::string read(void);
	std::vector<unsigned char> read_binary(void);
	void write(const std::string&);
	void write_binary(const std::vector<unsigned char>&);
};

