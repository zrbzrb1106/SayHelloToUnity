// SayHelloToUnity.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WinSock2.h>
#include <iostream>
#include <Ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")  //load ws2_32.dll

using namespace std;

int main()
{
	WSADATA wsaData;
	SOCKET sock;
	sockaddr_in servAddr;
	sockaddr fromAddr;
	int addrLen;


	WSAStartup(MAKEWORD(2, 2), &wsaData);

	sock = socket(PF_INET, SOCK_DGRAM, 0);
	memset(&servAddr, 0, sizeof(servAddr));

	servAddr.sin_family = PF_INET;
	inet_pton(PF_INET, "127.0.0.1", &(servAddr.sin_addr));
	servAddr.sin_port = htons(8888);

	addrLen = sizeof(fromAddr);	

	cout << "Input a String" << endl;

	while (1) {

		char buf[1024] = {};
		int i = 0;

		cin.getline(buf,'/t');
		sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&servAddr, sizeof(servAddr));
	
	}
    return 0;
}

