// test_openssl.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <openssl\md5.h>

int md5_encrypt(const void* data, size_t len, unsigned char* md5)
{
	if (data == NULL || len <= 0 || md5 == NULL) {
		printf("Input param invalid!\n");
		return -1;
	}
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, data, len);
	MD5_Final(md5, &ctx);

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char data[20] = "abcdefg";
	size_t len = 20;
	char md5[20] = { 0 };

	int iret = md5_encrypt((const void*)data, len, (unsigned char*)md5);
	cout << data << endl;
	cout << md5 << endl;
	getchar();
	return 0;
}

