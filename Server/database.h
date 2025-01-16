#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <sqlite3.h>

#include "user.h"
#include "conf.h"

class database_abstract
{
protected:
	//Protected internal implementations
	virtual std::string GetName(const std::string&) = 0;
	virtual std::string GetVisualizationMode(const std::string&) = 0;
	virtual bool GetChatMode(const std::string&) = 0;
	virtual int GetMessagesTimeout(const std::string&) = 0;
	virtual unsigned long GetSentMessages(const std::string&) = 0;
	virtual unsigned long GetReceivedMessages(const std::string&) = 0;
	virtual std::list<std::string> GetBlockedUsers(const std::string&) = 0;
	virtual void UpdateBlockedUsers(const std::string&, const std::list<std::string>&) = 0;
public:
	//Basic Expensive database calls 
	virtual const unsigned long RegisterHostMachine(const std::string&) = 0;
	virtual const std::string RegisterUser(const user&) = 0;
	virtual user GetUser(const user_lite&) = 0;
	virtual const std::string UpdateUserHostMachine(const user_lite&) = 0;
	virtual const std::string UpdateUserProperties(const user&) = 0;
	//Basic secondary calls
	virtual const std::vector<unsigned char> GetPasswordHash(const std::string&) = 0;
	virtual const void UpdatePasswordHash(const std::string&, const std::vector<unsigned char>&) = 0;
	virtual const bool CheckEmail(const std::string&) = 0;
	virtual const bool CheckUsername(const std::string&) = 0;
	virtual const std::string GetUserStatus(const std::string&) = 0;
	virtual const std::string GetUserIP(const std::string&) = 0;
	virtual const unsigned long GetHostMachineID(const std::string&) = 0;
	virtual int GetLoginAttempts(const std::string&) = 0;
	virtual void UpdateLoginAttempts(const std::string&,const int&) = 0;
	virtual bool CheckUserLock(const std::string&) = 0;
	//timestamp operations calls
	virtual std::string GetLastActivity(const std::string&) = 0;
	virtual void UpdateLastActivity(const std::string&, const std::string&) = 0;
	//block lists calls
	virtual bool BlockUser(const std::string&, const std::string&) = 0;
	virtual bool UnBlockUser(const std::string&, const std::string&) = 0;
	virtual std::list<std::string> GetBlockList(const std::string&) = 0;
};

class DataBaseException : public std::runtime_error
{
public:
	virtual ~DataBaseException(void) = default; //defalut virtual destructor
	DataBaseException(const std::string& err_message) : std::runtime_error(err_message) {}
};

class sqlite_db : public database_abstract
{
private:
	sqlite3* db = nullptr;	//pointer to the database (handler) for database operations
	//Protected internal implementations
	std::string GetName(const std::string&) override; 
	std::string GetVisualizationMode(const std::string&) override;
	bool GetChatMode(const std::string&) override;
	int GetMessagesTimeout(const std::string&) override;
	unsigned long GetSentMessages(const std::string&) override;
	unsigned long GetReceivedMessages(const std::string&) override;
	std::list<std::string> GetBlockedUsers(const std::string&) override;
	void UpdateBlockedUsers(const std::string&, const std::list<std::string>&) override;
public:
	//custom cosntructor and destructor
	sqlite_db(void);
	~sqlite_db(void);
	static void InitializeSQLite(void);
	//Basic Expensive database calls 
	const unsigned long RegisterHostMachine(const std::string&) override;
	const std::string RegisterUser(const user&) override;
	user GetUser(const user_lite&) override;
	const std::string UpdateUserProperties(const user&) override;
	const std::string UpdateUserHostMachine(const user_lite&) override;
	//Basic secondary calls
	const std::vector<unsigned char> GetPasswordHash(const std::string&) override;
	const void UpdatePasswordHash(const std::string&, const std::vector<unsigned char>&) override;
	const bool CheckEmail(const std::string&) override;
	const bool CheckUsername(const std::string&) override;
	const std::string GetUserStatus(const std::string&) override;
	const std::string GetUserIP(const std::string&) override;
	const unsigned long GetHostMachineID(const std::string&) override;
	int GetLoginAttempts(const std::string&) override;
	void UpdateLoginAttempts(const std::string&, const int&) override;
	bool CheckUserLock(const std::string&) override;
	//timestamp operations calls
	std::string GetLastActivity(const std::string&) override;
	void UpdateLastActivity(const std::string&, const std::string&) override;
	//block lists calls
	bool BlockUser(const std::string&, const std::string&) override;
	bool UnBlockUser(const std::string&, const std::string&) override;
	std::list<std::string> GetBlockList(const std::string&) override;
};


class SQLiteException : public DataBaseException
{
public:
	SQLiteException(const std::string& err_message) : DataBaseException(err_message) {}
};

//small class dedicated to next_id file read and write operations
class idinteger_file
{
private:
	const std::string filename;
public:
	idinteger_file(const std::string file) : filename(file) {}
	unsigned long ReadFile(void)
	{
		unsigned long value = 0;
		std::ifstream filestream(filename);   // Create an input file stream
		if (filestream.is_open())
		{
			filestream >> value;
			filestream.close();
		}
		return value;
	}
	bool WriteFile(unsigned long value)
	{
		std::ofstream filestream(filename);   // Create an output file stream
		if (filestream.is_open())
		{
			filestream << value;
			filestream.close();
		}
		else
			return false;
		return true;
	}
};