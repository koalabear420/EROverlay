#pragma once
#include "Common.hpp"

namespace ER {

	class Hooking
	{
		public:
			explicit Hooking();
			~Hooking() noexcept;
			Hooking(Hooking const&) = delete;
			Hooking(Hooking&&) = delete;
			Hooking& operator=(Hooking const&) = delete;
			Hooking& operator=(Hooking&&) = delete;

			void Hook();
			void Unhook();

			void FindHooks();

			static void __fastcall HookInput(uint64_t a1, uint64_t a2);

			// Hook Pointers

			void* m_OriginalInputHandler{};
			uint64_t m_InputHandler{};
	};

	inline std::unique_ptr<Hooking> g_Hooking;
}

