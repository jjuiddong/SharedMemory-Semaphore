// Inter-Process Communication with shared memory + semaphore + mutex
#include "stdafx.h"
#include "../lib/shmqueue.h"


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
	while (++cnt < 100)
	{
		sMsgData data = { cnt, 1.0f
			, common::format("name%d", cnt).c_str() };
		queue.push(data);
		
		std::cout << "push " << data.name.c_str() << "\n";
		Sleep(1000);
	}

	return 1;
}
