#include <algorithm>
#include <cstring>
#include <fstream>
#include <mutex>
#include <nlohmann/json.hpp>
#include "database.h"

using namespace nlohmann;	// for nlohmann::json scope
//using json = nlohmann::json;


static std::mutex Callback_Mutex;	//Private Global Mutex locked before SQL queries execution and unlcoked after
//to protect the callback function as a shared function/resource

static int SQL_Callback(void* data, int argc, char** argv, char** azColName)
{
	std::any* result = static_cast<std::any*>(data);
	if (argc > 0)
	{
		if (std::string(azColName[0]) == "username" || std::string(azColName[0]) == "name" || std::string(azColName[0]) == "email" || std::string(azColName[0]) == "current_ip_address" || std::string(azColName[0]) == "blocked_contacts" ||
			std::string(azColName[0]) == "current_host_machine_os" || std::string(azColName[0]) == "gender" || std::string(azColName[0]) == "birthdate" || std::string(azColName[0]) == "status" || std::string(azColName[0]) == "visualization_mode"
			|| std::string(azColName[0]) == "certificate_path" || std::string(azColName[0]) == "last_activity")
		{
			if (strcmp(argv[0], "NULL") != 0)
				*result = std::string(argv[0]);
		}
		else if (std::string(azColName[0]) == "password_hash")
		{
			const unsigned char* blob = reinterpret_cast<const unsigned char*>(argv[0]); //---
			int blob_size = std::strlen(argv[0]);
			std::vector<unsigned char> temp_blob_data;
			temp_blob_data.assign(blob, blob + blob_size); // Store BLOB in vector
			*result = temp_blob_data;
		}
		else if (std::string(azColName[0]) == "wrong_password_attempts" || std::string(azColName[0]) == "message_disappearance_timeout")
		{
			*result = argv[0] ? std::stoi(argv[0]) : 0; //INT Data, for int
		}
		else if (std::string(azColName[0]) == "sent_messages" || std::string(azColName[0]) == "received_messages"
			|| std::string(azColName[0]) == "hostmachine_id")
		{
			*result = argv[0] ? std::stoul(argv[0]) : 0; //INT Data, for unsigned long
		}
		else
		{
			*result = (argv[0] && std::string(argv[0]) == "1"); //BOOLEAN Data
		}
	}
	return 0;
}



std::string sqlite_db::GetName(const std::string& usrname)
{
	std::any name_data;
	std::string sql_query = "SELECT name FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &name_data, nullptr) != SQLITE_OK) //extract name
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract name error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<std::string>(name_data);
}

std::string sqlite_db::GetVisualizationMode(const std::string& usrname)
{
	std::any visualizationmode_data;
	std::string sql_query = "SELECT visualization_mode FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &visualizationmode_data, nullptr) != SQLITE_OK) //extract visualization mode
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract visualization mode error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<std::string>(visualizationmode_data);
}

bool sqlite_db::GetChatMode(const std::string& usrname)
{
	std::any chatmode_data;
	std::string sql_query = "SELECT ephemeral_chat FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &chatmode_data, nullptr) != SQLITE_OK) //extract chat mode
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract chat mode error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<bool>(chatmode_data);
}

int sqlite_db::GetMessagesTimeout(const std::string& usrname)
{
	std::any messagestimeout_data;
	std::string sql_query = "SELECT message_disappearance_timeout FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &messagestimeout_data, nullptr) != SQLITE_OK) //extract messages timeout
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract messages timeout error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<int>(messagestimeout_data);
}

unsigned long sqlite_db::GetSentMessages(const std::string& usrname)
{
	std::any sentmessages_data;
	std::string sql_query = "SELECT sent_messages FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &sentmessages_data, nullptr) != SQLITE_OK) //extract sent messages
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract sent messages error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<unsigned long>(sentmessages_data);
}

unsigned long sqlite_db::GetReceivedMessages(const std::string& usrname)
{
	std::any receivedmessages_data;
	std::string sql_query = "SELECT received_messages FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &receivedmessages_data, nullptr) != SQLITE_OK) //extract received messages
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract received messages error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<unsigned long>(receivedmessages_data);
}

std::list<std::string> sqlite_db::GetBlockedUsers(const std::string& usrname)
{
	std::any blocklist_data;
	std::string sql_query = "SELECT blocked_contacts FROM block_lists WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &blocklist_data, nullptr) != SQLITE_OK) //extract block list
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract block lists error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	std::list<std::string> Block_List;
	std::string BlockedContacts_str = std::any_cast<std::string>(blocklist_data);
	if (BlockedContacts_str.size() > 6)	//if only there's stored blocked contacts
	{
		json BlockedContacts_json = json::parse(BlockedContacts_str);	//parse to convert to json object
		// Convert the JSON array back into a std::list<std::string>
		for (const auto& blocked_contact : BlockedContacts_json)
			Block_List.push_back(blocked_contact.get<std::string>());
	}
	return Block_List;
}

void sqlite_db::UpdateBlockedUsers(const std::string& usrname, const std::list<std::string>& list)
{
	json BlockedContacts_json = list;	//copy list to json object
	std::string BlockedContacts_str = BlockedContacts_json.dump();	//convert json format to string
	std::string sql_query = "UPDATE block_lists SET blocked_contacts = '" + BlockedContacts_str + "' WHERE username = '" + usrname + "'; ";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update block lists, status update failed: " + std::string(sqlite3_errmsg(db)));
	return;
}

sqlite_db::sqlite_db(void)
{
	if (sqlite3_open(DATABASE_PATH, &db) != SQLITE_OK)	//open database
	{
		throw SQLiteException("SQLite Connection Error: " + std::string(sqlite3_errmsg(db)));
	}
	if (sqlite3_exec(db, MAIN_TABLE, nullptr, nullptr, nullptr) != SQLITE_OK)	//Create table if doesn't exist
	{
		throw SQLiteException("SQLite Main Table Error: " + std::string(sqlite3_errmsg(db)));
	}
	if (sqlite3_exec(db, CERTIFICATES_TABLE, nullptr, nullptr, nullptr) != SQLITE_OK) //Create table if doesn't exist
	{
		throw SQLiteException("SQLite Certificates Table Error: " + std::string(sqlite3_errmsg(db)));
	}
	if (sqlite3_exec(db, BLOCK_TABLE, nullptr, nullptr, nullptr) != SQLITE_OK) //Create table if doesn't exist
	{
		throw SQLiteException("SQLite Block Table Error: " + std::string(sqlite3_errmsg(db)));
	}
}

sqlite_db::~sqlite_db(void)
{
	sqlite3_close(db);	//close database
}

void sqlite_db::InitializeSQLite(void)
{
	sqlite3_config(SQLITE_CONFIG_SERIALIZED);	//allow multiple connections for the database from different threads
}



const unsigned long sqlite_db::RegisterHostMachine(const std::string& cert_path)
{
	idinteger_file nextid_file(NEXT_ID_FILE);	//automatically closed and destructed
	unsigned long next_id = nextid_file.ReadFile();
	sqlite3_stmt* newmachine_stmt;
	std::string newmachine_sql = "INSERT INTO certificates (\
			hostmachine_id, certificate_path)\
			VALUES (?, ?);";
	if (sqlite3_prepare_v2(db, newmachine_sql.c_str(), -1, &newmachine_stmt, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to add new machine, Pre-add: " + std::string(sqlite3_errmsg(db)));
	// Bind the parameters to the prepared statement
	sqlite3_bind_int(newmachine_stmt, 1, next_id);	//registered id
	sqlite3_bind_text(newmachine_stmt, 2, cert_path.c_str(), -1, SQLITE_TRANSIENT);
	//execute adding
	if (sqlite3_step(newmachine_stmt) != SQLITE_DONE)
	{
		sqlite3_finalize(newmachine_stmt);
		throw SQLiteException("Failed to add new machine: " + std::string(sqlite3_errmsg(db)));
	}
	sqlite3_finalize(newmachine_stmt);
	nextid_file.WriteFile(++next_id);
	return next_id;
}

const std::string sqlite_db::RegisterUser(const user& usr)
{
	if (this->CheckUsername(usr.getUsername())) //if username already exists and used
		return "username already used";
	if (this->CheckEmail(usr.getEmail()))	//if email already exists and used
		return "email already user";
	sqlite3_stmt* newentry_stmt;
	std::string newentry_sql = "INSERT INTO users (\
			username, name, email, password_hash,\
			wrong_password_attempts, account_locked, current_ip_address,\
            current_host_machine_os, gender, birthdate,\
            status, visualization_mode, ephemeral_chat,\
            message_disappearance_timeout, sent_messages, received_messages, current_hostmachine_id, last_activity)\
			VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
	if (sqlite3_prepare_v2(db, newentry_sql.c_str(), -1, &newentry_stmt, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to add user, Pre-add: " + std::string(sqlite3_errmsg(db)));
	// Bind the parameters to the prepared statement
	sqlite3_bind_text(newentry_stmt, 1, usr.getUsername().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(newentry_stmt, 2, usr.getName().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(newentry_stmt, 3, usr.getEmail().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_blob(newentry_stmt, 4, usr.getPasswordHash().data(), usr.getPasswordHash().size(), SQLITE_TRANSIENT);
	sqlite3_bind_int(newentry_stmt, 5, 0);	//wrong attempts, initialized by 0
	sqlite3_bind_text(newentry_stmt, 6, usr.getCurrentIP().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(newentry_stmt, 7, usr.getHostMachineOS().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(newentry_stmt, 8, usr.getGender().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(newentry_stmt, 9, usr.getBirthdate().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(newentry_stmt, 10, usr.getStatus().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(newentry_stmt, 11, usr.getVisualization().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_int(newentry_stmt, 12, usr.getEphemeral() ? 1 : 0);
	sqlite3_bind_int(newentry_stmt, 13, usr.getMessagesTimeout());
	sqlite3_bind_int(newentry_stmt, 14, usr.getSentMessages());
	sqlite3_bind_int(newentry_stmt, 15, usr.getReceivedMessages());
	sqlite3_bind_int(newentry_stmt, 16, usr.getHostMachineID());
	sqlite3_bind_text(newentry_stmt, 17, hostmachine::getTimestamp().c_str(), -1, SQLITE_TRANSIENT);	//timestamp
	//execute adding
	if (sqlite3_step(newentry_stmt) != SQLITE_DONE)
	{
		sqlite3_finalize(newentry_stmt);
		throw SQLiteException("Failed to add user: " + std::string(sqlite3_errmsg(db)));
	}
	sqlite3_finalize(newentry_stmt);
	//initialze user blocklist
	sqlite3_stmt* blocklist_stmt;
	std::string blocklist_sql_query = "INSERT INTO block_lists (username, blocked_contacts) VALUES (?, ?);";
	if (sqlite3_prepare_v2(db, blocklist_sql_query.c_str(), -1, &blocklist_stmt, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to add user, Pre-add: " + std::string(sqlite3_errmsg(db)));
	// Bind the parameters to the prepared statement
	sqlite3_bind_text(blocklist_stmt, 1, usr.getUsername().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(blocklist_stmt, 2, "", -1, SQLITE_TRANSIENT);
	if (sqlite3_step(blocklist_stmt) != SQLITE_DONE)
	{
		sqlite3_finalize(blocklist_stmt);
		throw SQLiteException("Failed to add user: " + std::string(sqlite3_errmsg(db)));
	}
	sqlite3_finalize(blocklist_stmt);
	//this step is necessary, new entries need to be initialized. Then reset hostmachine properties
	this->UpdateUserHostMachine(user_lite(usr.getUsername(), "", "", 0, 0));
	return "USER ADDED";
}

user sqlite_db::GetUser(const user_lite& usr)
{
	return user::Builder().setUsername(usr.getUsername()).setName(this->GetName(usr.getUsername())).setVisualization(this->GetVisualizationMode(usr.getUsername())).
		setEphemeralChat(this->GetChatMode(usr.getUsername())).setMessagesTimeout(this->GetMessagesTimeout(usr.getUsername())).setSentMessages(this->GetSentMessages(usr.getUsername())).
		setReceivedMessages(this->GetReceivedMessages(usr.getUsername())).setStatus(this->GetUserStatus(usr.getUsername())).build();
}

const std::string sqlite_db::UpdateUserProperties(const user& usr)
{
	std::string sql_query = "UPDATE users SET status = '" + usr.getStatus() + "' WHERE username = '" + usr.getUsername() + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user, status update failed: " + std::string(sqlite3_errmsg(db)));
	sql_query = "UPDATE users SET visualization_mode = '" + usr.getVisualization() + "' WHERE username = '" + usr.getUsername() + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user, visualization update failed: " + std::string(sqlite3_errmsg(db)));
	sql_query = "UPDATE users SET ephemeral_chat = '" + std::to_string(usr.getEphemeral()) + "' WHERE username = '" + usr.getUsername() + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user, chat mode update failed: " + std::string(sqlite3_errmsg(db)));
	sql_query = "UPDATE users SET message_disappearance_timeout = '" + std::to_string(usr.getMessagesTimeout()) + "' WHERE username = '" + usr.getUsername() + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user, messages timeout update failed: " + std::string(sqlite3_errmsg(db)));
	sql_query = "UPDATE users SET sent_messages = '" + std::to_string(usr.getSentMessages()) + "' WHERE username = '" + usr.getUsername() + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user, messages sent update failed: " + std::string(sqlite3_errmsg(db)));
	sql_query = "UPDATE users SET received_messages = '" + std::to_string(usr.getReceivedMessages()) + "' WHERE username = '" + usr.getUsername() + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user, messages received update failed: " + std::string(sqlite3_errmsg(db)));
	return "USER UPDATED";
}

const std::string sqlite_db::UpdateUserHostMachine(const user_lite& usr)
{
	std::string sql_query = "UPDATE users SET current_ip_address = '" + usr.getCurrentIP() + "' WHERE username = '" + usr.getUsername() + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user, ip update failed: " + std::string(sqlite3_errmsg(db)));
	sql_query = "UPDATE users SET current_host_machine_os = '" + usr.getHostMachineOS() + "' WHERE username = '" + usr.getUsername() + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user, hostmachine os update failed: " + std::string(sqlite3_errmsg(db)));
	sql_query = "UPDATE users SET current_hostmachine_id = '" + std::to_string(usr.getHostMachineID()) + "' WHERE username = '" + usr.getUsername() + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user, hostmachine id update failed: " + std::string(sqlite3_errmsg(db)));
	return "USER UPDATED";
}

const std::vector<unsigned char> sqlite_db::GetPasswordHash(const std::string& usrname)
{
	std::any passwordhash_data;
	std::string sql_query = "SELECT password_hash FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &passwordhash_data, nullptr) != SQLITE_OK) //extract password hash
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract passwordhash error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<std::vector<unsigned char>>(passwordhash_data);
}

const void sqlite_db::UpdatePasswordHash(const std::string& usrname, const std::vector<unsigned char>& hash)
{
	std::string sql_query = "UPDATE users SET password_hash = ? WHERE username = '" + usrname + "';";
	sqlite3_stmt* updatehash_stmt;
	if (sqlite3_prepare_v2(db, sql_query.c_str(), -1, &updatehash_stmt, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update password hash, Pre-update: " + std::string(sqlite3_errmsg(db)));
	sqlite3_bind_blob(updatehash_stmt, 1, hash.data(), hash.size(), SQLITE_TRANSIENT);
	if (sqlite3_step(updatehash_stmt) != SQLITE_DONE)
	{
		sqlite3_finalize(updatehash_stmt);
		throw SQLiteException("Failed to update password hash: " + std::string(sqlite3_errmsg(db)));
	}
	sqlite3_finalize(updatehash_stmt);
	return;
}

const bool sqlite_db::CheckEmail(const std::string& email)
{
	sqlite3_stmt* checkemail_stmt;
	std::string checkemail_query = "SELECT COUNT(*) FROM users WHERE email = ?;";
	if (sqlite3_prepare_v2(db, checkemail_query.c_str(), -1, &checkemail_stmt, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to check email, s1 failed: " + std::string(sqlite3_errmsg(db)));
	sqlite3_bind_text(checkemail_stmt, 1, email.c_str(), -1, SQLITE_TRANSIENT);
	if (sqlite3_step(checkemail_stmt) != SQLITE_ROW)
		throw SQLiteException("Failed to check email, s2 failed: " + std::string(sqlite3_errmsg(db)));
	if (sqlite3_column_int(checkemail_stmt, 0) > 0)
	{
		sqlite3_finalize(checkemail_stmt);
		return true;	//email exists
	}
	sqlite3_finalize(checkemail_stmt);
	return false;	//email doesn't exist}
}

const bool sqlite_db::CheckUsername(const std::string& usrname)
{
	sqlite3_stmt* checkusername_stmt;
	std::string checkusername_query = "SELECT COUNT(*) FROM users WHERE username = ?;";
	if (sqlite3_prepare_v2(db, checkusername_query.c_str(), -1, &checkusername_stmt, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to check username, s1 failed: " + std::string(sqlite3_errmsg(db)));
	sqlite3_bind_text(checkusername_stmt, 1, usrname.c_str(), -1, SQLITE_TRANSIENT);
	if (sqlite3_step(checkusername_stmt) != SQLITE_ROW)
		throw SQLiteException("Failed to check username, s2 failed: " + std::string(sqlite3_errmsg(db)));
	if (sqlite3_column_int(checkusername_stmt, 0) > 0)
	{
		sqlite3_finalize(checkusername_stmt);
		return true;	//username exists
	}
	sqlite3_finalize(checkusername_stmt);
	return false;	//username doesn't exist}
}

const std::string sqlite_db::GetUserStatus(const std::string& usrname)
{
	if (!CheckUsername(usrname))
		return "INCORRECT USER";	//user doesn't exist
	std::any userstatus_data;
	std::string sql_query = "SELECT status FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &userstatus_data, nullptr) != SQLITE_OK) //extract password hash
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract status error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<std::string>(userstatus_data);
}

const std::string sqlite_db::GetUserIP(const std::string& usrname)
{
	std::any ipaddress_data;
	std::string sql_query = "SELECT current_ip_address FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &ipaddress_data, nullptr) != SQLITE_OK) //extract ip address
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract ip address error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<std::string>(ipaddress_data);
}

const unsigned long sqlite_db::GetHostMachineID(const std::string& usrname)
{
	std::any hostmachine_id_data;
	std::string sql_query = "SELECT current_hostmachine_id FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &hostmachine_id_data, nullptr) != SQLITE_OK) //extract hostmachine id
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract hostmachine id error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<unsigned long>(hostmachine_id_data);
	return 0;
}

int sqlite_db::GetLoginAttempts(const std::string& usrname)
{
	std::any loginattempts_data;
	std::string sql_query = "SELECT wrong_password_attempts FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &loginattempts_data, nullptr) != SQLITE_OK) //extract password hash
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Extract passwordhash error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<int>(loginattempts_data);
}

void sqlite_db::UpdateLoginAttempts(const std::string& usrname, const int& attempts)
{
	std::string sql_query = "UPDATE users SET wrong_password_attempts = '" + std::to_string(attempts) + "' WHERE username = '" + usrname + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to login attempts: " + std::string(sqlite3_errmsg(db)));
	return;
}

bool sqlite_db::CheckUserLock(const std::string& usrname)
{
	if (this->GetLoginAttempts(usrname) >= LOGIN_ATTEMPTS_POLICY)
		return true;
	return false;
}

std::string sqlite_db::GetLastActivity(const std::string& usrname)
{
	std::any timestamp_data;
	std::string sql_query = "SELECT last_activity FROM users WHERE username = '" + usrname + "';";
	Callback_Mutex.lock();	//lock mutex for callback execution
	if (sqlite3_exec(db, sql_query.c_str(), SQL_Callback, &timestamp_data, nullptr) != SQLITE_OK) //extract last activity timestamp
	{
		Callback_Mutex.unlock();
		throw SQLiteException("SQLite Get Last Activity error: " + std::string(sqlite3_errmsg(db)));
	}
	Callback_Mutex.unlock();	//unlock mutex after callback execution
	return std::any_cast<std::string>(timestamp_data);
	return std::string();
}

void sqlite_db::UpdateLastActivity(const std::string& usrname, const std::string& timestamp)
{
	std::string sql_query = "UPDATE users SET last_activity = '" + timestamp + "' WHERE username = '" + usrname + "';";
	if (sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK)
		throw SQLiteException("Failed to update user activity, timestamp update failed: " + std::string(sqlite3_errmsg(db)));
	return;
}

bool sqlite_db::BlockUser(const std::string& usrname, const std::string& contact)
{
	if (!CheckUsername(contact))
		return false;	//contact doesn't exist
	std::list<std::string> Block_List = this->GetBlockedUsers(usrname);
	auto found = std::find(Block_List.begin(), Block_List.end(), contact);
	if (found != Block_List.end())	//if contact already there
		return true;	//blocked already and return
	Block_List.push_back(contact);
	UpdateBlockedUsers(usrname, Block_List);	//added to the block list
	return true;
}

bool sqlite_db::UnBlockUser(const std::string& usrname, const std::string& contact)
{
	if (!CheckUsername(contact))
		return false;	//contact doesn't exist
	std::list<std::string> Block_List = this->GetBlockedUsers(usrname);
	auto found = std::find(Block_List.begin(), Block_List.end(), contact);
	if (found == Block_List.end())	//if contact not found
		return true;	//already unblocked
	Block_List.remove(contact);
	UpdateBlockedUsers(usrname, Block_List);	//added to the block list
	return true;
}

std::list<std::string> sqlite_db::GetBlockList(const std::string& usrname)
{
	return this->GetBlockedUsers(usrname);
}


