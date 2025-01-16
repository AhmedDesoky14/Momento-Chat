#pragma once


#define TEMP_DIRECTORY "/home/desoky/Fade_Project/temp/"
#define KEYS_DIRECTORY "/home/desoky/Fade_Project/keys/"
#define SERVER_KEY "/home/desoky/Fade_Project/keys/server-key.pem"
#define CERTIFICICATES_DIRECTORY "/home/desoky/Fade_Project/certificates/"
#define NEXT_ID_FILE    "/home/desoky/Fade_Project/databases_server/next_id.txt"
#define DATABASE_PATH	"/home/desoky/Fade_Project/databases_server/test_database.db" 
#define MAIN_TABLE "CREATE TABLE IF NOT EXISTS users (\
            username TEXT NOT NULL UNIQUE,\
            name TEXT NOT NULL,\
            email TEXT NOT NULL UNIQUE,\
            password_hash BLOB NOT NULL,\
            wrong_password_attempts INTEGER DEFAULT 0,\
            current_ip_address TEXT NOT NULL,\
            current_host_machine_os TEXT NOT NULL,\
            gender TEXT NOT NULL,\
            birthdate TEXT NOT NULL,\
            status TEXT NOT NULL,\
            visualization_mode TEXT NOT NULL,\
            ephemeral_chat BOOLEAN DEFAULT 0,\
            message_disappearance_timeout INTEGER DEFAULT 0,\
            sent_messages INTEGER DEFAULT 0,\
            received_messages INTEGER DEFAULT 0,\
            current_hostmachine_id INTEGER UNIQUE NOT NULL,\
            last_activity TEXT NOT NULL);"
#define CERTIFICATES_TABLE "CREATE TABLE IF NOT EXISTS certificates (\
                            hostmachine_id INTEGER UNIQUE NOT NULL, certificate_path TEXT NOT NULL);"
#define BLOCK_TABLE "CREATE TABLE IF NOT EXISTS block_lists (\
            username TEXT NOT NULL UNIQUE, blocked_contacts TEXT);"

#define TIME_FILE "/home/desoky/Fade_Project/databases_server/time.txt"

constexpr int LOGIN_ATTEMPTS_POLICY = 3;

constexpr int SERIAL_NUMBER_SIZE = 128U; //128bits


