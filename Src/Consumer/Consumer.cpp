//
// ipc consumer process
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
	while (queue.pop(out))
	{
		std::cout << out.name.c_str() << std::endl;
	}


	return 1; 
}

