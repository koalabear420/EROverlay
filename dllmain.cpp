// dllmain.cpp : Defines the entry point for the DLL application.
#include "Common.hpp"
#include "D3DRenderer.hpp"
#include "Hooking.hpp"

void MainThread()
{
    using namespace ER;
    g_GameVariables = std::make_unique<GameVariables>();
    g_D3DRenderer = std::make_unique<D3DRenderer>();
    g_Hooking = std::make_unique<Hooking>();

    g_Hooking->Hook();

    while (g_Running)
    {
        if (GetAsyncKeyState(VK_INSERT) & 1) g_GameVariables->m_ShowMenu = !g_GameVariables->m_ShowMenu;
        if (GetAsyncKeyState(VK_DELETE) & 1) g_Running = false;
        std::this_thread::sleep_for(3ms);
        std::this_thread::yield();
    }

    std::this_thread::sleep_for(500ms);
    g_Hooking->Unhook();
    g_D3DRenderer.reset();
    std::this_thread::sleep_for(500ms);
    g_Hooking.reset();
    g_GameVariables.reset();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{

    using namespace ER;

    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        g_Module = hModule;
        _beginthread((_beginthread_proc_type)MainThread, 0, NULL);
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        g_Hooking->Unhook();
        FreeLibraryAndExitThread(hModule, TRUE);
    }
    return TRUE;
}

