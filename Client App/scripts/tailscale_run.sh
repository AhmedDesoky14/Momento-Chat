#!/bin/bash
#Bash script to connect to the Tailscale VPN server

#Tailscale Authentication Key, configure it
AUTH_KEY="tskey-auth-k8MSmSA7E921CNTRL-sapx7ddzMfN8hGUjVYXefNpEhCywMtcGY"
#USER="desoky"
#timeout for VPN connection time in seconds 
CONNECT_TIMEOUT=10

#Connect to server VPN
timeout $CONNECT_TIMEOUT tailscale up --authkey=$AUTH_KEY --operator=$USER 
#If connected successfully
if [ $? -eq 0 ]; then
	echo "connected_successfully"
	exit 0
else
	echo "Not Connected"
	exit 1
fi
