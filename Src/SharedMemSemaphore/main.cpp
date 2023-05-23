// Inter-Process Communication with shared memory + semaphore + mutex
// 
// Producer
// 
// start Consumer.exe X N first
// start SharedMemSemphore.exe next
//
#include "stdafx.h"
//#include "../lib/shmqueue.h"

int main() 
{
	struct sMsgData
	{
		int n;
		float f;
		StrId name;
	};

	cShmQueue<sMsgData> queue("ipc_message");

	int cnt = 0;
	while (1)
	{
		sMsgData data = { cnt, 1.0f
			, common::format("name%d", cnt).c_str() };
		if (!queue.push(data))
		{
			Sleep(10);
			continue;
		}
		
		++cnt;
		std::cout << "push " << data.name.c_str() << "\n";
		Sleep(10);
	}

	std::cout << "finish producer\n";
	return 1;
}
