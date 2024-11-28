#pragma once
#include "platform.h"

/*
 * Server connection status
 * 0: Server and other users are on same local network
 * 1: Server and other users are on Virtual Private Network (VPN)
 * 2: TBD
 */
#define SERVER 1U
#define LOCALSERVER_IP "192.168.."
//Path+file script for VPN setup before starting
#if(PLATFORM == LINUX)


#define TIME_FILE "/home/desoky/Fade_Project/C++_Projects/time"
#define TEMP_FILE "/home/desoky/Fade_Project/C++_Projects/temp"


#define ConnectVPN_script "/home/desoky/Fade_Project/C++_Projects/scripts/tailscale_run.sh"




#elif(PLATFORM == WINDOWS)
#define VPN_script ""



#endif
