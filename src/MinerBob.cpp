#include"/data/charlesqliu/MiniMiner/extern/MiniGame/exported/behaviac_generated/types/internal/behaviac_agent_headers.h"
#include"./MessageSys/MessageMgr.h"
#include"./MessageSys/RelationShipMgr.h"
namespace MinerSpace {
	Miner* g_Miner;
	bool InitPlayer()
	{
		g_Miner = behaviac::Agent::Create<Miner>();

		bool bRet = g_Miner->btload("Miner");

		g_Miner->btsetcurrent("Miner");
		RelationShipMgr::Instance().RegMiner(g_Miner);
		MessageMgr::Instance().RegAgent(g_Miner);
		return bRet;
	}
	void UpdateLoop()
	{

		int frames = 0;
		behaviac::EBTStatus status = behaviac::BT_RUNNING;

		while (status == behaviac::BT_RUNNING)
		{
			status = g_Miner->btexec();
		}
	}
	void CleanupPlayer()
	{

		behaviac::Agent::Destroy(g_Miner);
	}

	void CleanupBehaviac()
	{

		behaviac::Workspace::GetInstance()->Cleanup();
	}
	void* InitMiner(void *arg) {
		InitPlayer();
		UpdateLoop();
		CleanupPlayer();
		CleanupBehaviac();
		return 0;
	}
}