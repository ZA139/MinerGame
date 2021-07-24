#include "./BobWife.cpp"
#include "./MinerBob.cpp"
#include "./MessageSys/MessageMgr.h"
#include <pthread.h>
#include <unistd.h>
int main(void) {
	behaviac::Workspace::GetInstance()->SetFilePath("/data/charlesqliu/MiniMiner/extern/MiniGame/exported");
	behaviac::Workspace::GetInstance()->SetFileFormat(behaviac::Workspace::EFF_xml);
	pthread_t tMinerId;
	if (pthread_create(&tMinerId, NULL,MinerSpace::InitMiner, NULL) == -1) {
		perror("miner_create");
		exit(1);
	}
	pthread_t tWifeId;
	if (pthread_create(&tWifeId, NULL, WifeSpace::InitWife, NULL) == -1) {
		perror("wife_create");
		exit(1);
	}
	while (1) {
		MessageMgr::Instance().HandleMessageQueue();
		usleep(500000);
	}
	return 0;
}