#pragma once
#include "Common.hpp"

namespace ER
{
	class GameVariables
	{
	public:
		explicit GameVariables();
		~GameVariables() noexcept = default;

		GameVariables(GameVariables const&) = delete;
		GameVariables(GameVariables&&) = delete;
		GameVariables& operator=(GameVariables const&) = delete;
		GameVariables& operator=(GameVariables&&) = delete;

		int m_GamePid{};
		HANDLE m_GameHandle{};
		HWND m_GameWindow{};
		int m_GameWidth;
		int m_GameHeight;
		LPCSTR m_GameTitle;
		LPCSTR m_ClassName;
		LPCSTR m_GamePath;

		IDXGISwapChain3* m_Swapchain{};
		bool m_ShowMenu{};
	};

	class GameFunctions
	{
	public:
		explicit GameFunctions();
		~GameFunctions() noexcept = default;
		GameFunctions(GameFunctions const&) = delete;
		GameFunctions(GameFunctions&&) = delete;
		GameFunctions& operator=(GameFunctions const&) = delete;
		GameFunctions& operator=(GameFunctions&&) = delete;


	};

	inline std::unique_ptr<GameVariables> g_GameVariables;
	inline std::unique_ptr<GameFunctions> g_GameFunctions;
}