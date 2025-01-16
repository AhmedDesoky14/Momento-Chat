#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <any>
#include "conf.h"
class hostmachine
{
private:
	const std::string current_ip;
	const std::string hostmachine_os;
	const unsigned long hostmachine_id;
public:
	hostmachine(const std::string& ip, const std::string& os, const unsigned long& id) :
		current_ip(ip), hostmachine_os(os), hostmachine_id(id) {}
	inline std::string getCurrentIP(void) const
	{
		return current_ip;
	}
	inline std::string getHostMachineOS(void) const
	{
		return hostmachine_os;
	}
	inline unsigned long getHostMachineID(void) const
	{
		return hostmachine_id;
	}
	static const std::string getTimestamp(void)
	{
		std::string time;
		std::string time_command = "date > " + static_cast<std::string>(TIME_FILE);
		std::system(time_command.c_str());
		std::ifstream file_data_stream(TIME_FILE, std::ios::in);//open TIME_FILE for input operations
		if (!file_data_stream.is_open()) //if file is not open
			return "ERROR";
		file_data_stream >> time;
		file_data_stream.close();
		return time;
	}
};

class user_base
{
protected:
	const hostmachine host;
	const std::string username;
public:
	user_base(const std::string& usrname, const std::string& ip, const std::string& os, const unsigned long& hm_id) :
		username(usrname),host(ip,os,hm_id){}
	inline std::string getUsername(void) const
	{
		return username;
	}
	inline std::string getCurrentIP(void) const
	{
		return host.getCurrentIP();
	}
	inline std::string getHostMachineOS(void) const
	{
		return host.getHostMachineOS();
	}
	inline unsigned long getHostMachineID(void) const
	{
		return host.getHostMachineID();
	}
};
class user : public user_base
{
private:
	const std::string name;
	const std::string email;
	std::vector<unsigned char> password_hash;
	const std::string gender;
	const std::string birthdate;
	std::string status;
	std::string visualization_mode;
	bool ephemeral_chat;
	int messages_timeout;
	unsigned long sent_messages;
	unsigned long received_messages;
	//private constrcutor
	user(const std::string& usrnm, const std::string& nm, const std::string& eml,
		const std::vector<unsigned char>& pwd_hash, const std::string& ip, const std::string& os,
		const std::string& gndr, const std::string& date, const std::string& st, const std::string& vs,
		const bool& eph, const unsigned int& timeout, const unsigned long& num1, const unsigned long& num2, const unsigned long hm_id) :
		user_base(usrnm, ip, os, hm_id), name(nm), email(eml), password_hash(pwd_hash), gender(gndr), birthdate(date), status(st),
		visualization_mode(vs), ephemeral_chat(eph), messages_timeout(timeout), sent_messages(num1), received_messages(num2) {}
public:
	//Copy or move constrcutor, if neccessary
	inline std::string getName(void) const
	{
		return name;
	}
	inline std::string getEmail(void) const
	{
		return email;
	}
	inline std::vector<unsigned char> getPasswordHash(void) const
	{
		return password_hash;
	}
	inline std::string getGender(void) const
	{
		return gender;
	}
	inline std::string getBirthdate(void) const
	{
		return birthdate;
	}
	inline std::string getStatus(void) const
	{
		return status;
	}
	inline std::string getVisualization(void) const
	{
		return visualization_mode;
	}
	inline bool getEphemeral(void) const
	{
		return ephemeral_chat;
	}
	inline int getMessagesTimeout(void) const
	{
		return messages_timeout;
	}
	inline unsigned long getSentMessages(void) const
	{
		return sent_messages;
	}
	inline unsigned long getReceivedMessages(void) const
	{
		return received_messages;
	}
	// builder design pattern
	class Builder
	{
	private:
		std::string username = "nemo";
		std::string current_ip = "0.0.0.0";
		std::string hostmachine_os = "NO OS";
		unsigned long hostmachine_id = 0;
		std::string name = "nemo";
		std::string email = "@";
		std::vector<unsigned char> password_hash;
		std::string gender = "Not selected";
		std::string birthdate = "1/1/2025";
		std::string status = "offline";
		std::string visualization_mode = "Bright Mode";
		bool ephemeral_chat = true;
		int messages_timeout = 0;
		unsigned long sent_messages = 0;
		unsigned long received_messages = 0;
	public:
		user build(void)
		{
			//build and construct a user and return it
			return user(username, name, email, password_hash,
				current_ip, hostmachine_os, gender, birthdate, status, visualization_mode, ephemeral_chat,
				messages_timeout, sent_messages, received_messages, hostmachine_id);
		}
		inline Builder& setUsername(const std::string& usrnm)
		{
			this->username = usrnm;
			return *this;
		}
		inline Builder& setCurrentIP(const std::string& ip)
		{
			this->current_ip = ip;
			return *this;
		}
		inline Builder& setHostMachineOS(const std::string& os)
		{
			this->hostmachine_os = os;
			return *this;
		}
		inline Builder& setHostMachineID(const unsigned long& id)
		{
			this->hostmachine_id = id;
			return *this;
		}
		inline Builder& setName(const std::string& nm)
		{
			this->name = nm;
			return *this;
		}
		inline Builder& setEmail(const std::string& eml)
		{
			this->email = eml;
			return *this;
		}
		inline Builder& setPasswordHash(const std::vector<unsigned char>& pwd)
		{
			this->password_hash = pwd;
			return *this;
		}
		inline Builder& setGender(const std::string& gndr)
		{
			this->gender = gndr;
			return *this;
		}
		inline Builder& setBirthdate(const std::string& date)
		{
			this->birthdate = date;
			return *this;
		}
		inline Builder& setStatus(const std::string& st)
		{
			this->status = st;
			return *this;
		}
		inline Builder& setVisualization(const std::string& vs)
		{
			this->visualization_mode = vs;
			return *this;
		}
		inline Builder& setEphemeralChat(const bool& eph)
		{
			this->ephemeral_chat = eph;
			return *this;
		}
		inline Builder& setMessagesTimeout(const int& timeout)
		{
			this->messages_timeout = timeout;
			return *this;
		}
		inline Builder& setSentMessages(const unsigned long& num)
		{
			this->sent_messages = num;
			return *this;
		}
		inline Builder& setReceivedMessages(const unsigned long& num)
		{
			this->received_messages = num;
			return *this;
		}
	};
};

class user_lite : public user_base
{
private:
	std::any data;
public:
	user_lite(const std::string& usrnm, const std::string& ip, const std::string& os,const unsigned long& id, const std::any& dt) :
		user_base(usrnm,ip,os,id), data(dt){}
	inline std::any getData(void) const
	{
		return data;
	}
};
