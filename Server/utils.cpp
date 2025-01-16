#include "utils.h"

std::string file::read(void)
{
	std::ifstream filestream(filename, std::ios::in);
	if (!filestream.is_open())
		throw std::runtime_error("failed to open file (" + filename + ") for reading");
	std::string read_data((std::istreambuf_iterator<char>(filestream)), std::istreambuf_iterator<char>());	//reading data
	if (read_data.empty())
		throw std::runtime_error("(" + filename + ") file is empty");
	return read_data;
}

std::vector<unsigned char> file::read_binary(void)
{
	std::ifstream filestream(filename, std::ios::in | std::ios::binary);	//open in "input" and  "binary" mode
	if (!filestream.is_open())
		throw std::runtime_error("failed to open file (" + filename + ") for reading");
	filestream.seekg(0, std::ios::end);	//shifting the position to the end of the filestream
	std::streamsize filesize = filestream.tellg();	//getting filestream size
	if (filesize <= 0)
		throw std::runtime_error("(" + filename + ") file is empty");
	filestream.seekg(0, std::ios::beg);	//shifting back the position to the begining of the filestream
	std::vector<unsigned char> buffer(static_cast<size_t>(filesize));
	if (!filestream.read(reinterpret_cast<char*>(buffer.data()), filesize))	//reading the filestream and casting the buffer vector ptr to char*
		throw std::runtime_error("failed to read from file (" + filename + ")");
	return buffer;
}

void file::write(const std::string& data)
{
	std::ofstream filestream(filename, std::ios::out);
	if (!filestream.is_open())
		throw std::runtime_error("failed to open file (" + filename + ") for writing");
	filestream << data;	//writing the string data
	return;
}

void file::write_binary(const std::vector<unsigned char>& data_vect)
{
	std::ofstream filestream(filename, std::ios::out);
	if (!filestream.is_open())
		throw std::runtime_error("failed to open file (" + filename + ") for writing");
	if (!filestream.write(reinterpret_cast<const char*>(data_vect.data()), data_vect.size()))	//writing the string data
		throw std::runtime_error("failed to write to file (" + filename + ")");
	return;
}
