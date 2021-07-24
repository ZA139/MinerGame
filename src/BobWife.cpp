#include"/data/charlesqliu/MiniMiner/extern/MiniGame/exported/behaviac_generated/types/internal/behaviac_agent_headers.h"
#include"./MessageSys/MessageMgr.h"
#include"./MessageSys/RelationShipMgr.h"
namespace WifeSpace {
	Wife* g_Wife;
	bool InitPlayer()
	{
		g_Wife = behaviac::Agent::Create<Wife>();

		bool bRet = g_Wife->btload("Wife");

		g_Wife->btsetcurrent("Wife");
		RelationShipMgr::Instance().RegWife(g_Wife);
		MessageMgr::Instance().RegAgent(g_Wife);
		return bRet;
	}
	void UpdateLoop()
	{

		int frames = 0;
		behaviac::EBTStatus status = behaviac::BT_RUNNING;

		while (status == behaviac::BT_RUNNING)
		{
			status = g_Wife->btexec();
		}
	}
	void CleanupPlayer()
	{

		behaviac::Agent::Destroy(g_Wife);
	}

	void CleanupBehaviac()
	{

		behaviac::Workspace::GetInstance()->Cleanup();
	}
	void* InitWife(void *arg) {
		InitPlayer();
		UpdateLoop();
		CleanupPlayer();
		CleanupBehaviac();
		return 0;
	}
}