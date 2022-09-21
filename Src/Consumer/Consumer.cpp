//
// ipc consumer process
// 
// Consumer
// 
// start Consumer.exe X N first
// start SharedMemSemphore.exe next
//

#include "../../../Common/Common/common.h"
using namespace common;
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
	sMsgData out;
	int cnt = 0;
	while (
		//(cnt++ < 10) && 
		queue.pop(out))
	{
		std::cout << out.name.c_str() << std::endl;
		Sleep(10);
	}

	std::cout << "finish consumer \n";
	return 1; 
}

