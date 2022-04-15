#include <cstdint>;
#include "GarrysMod/Lua/Interface.h";
#include "Discord.h";

Discord* discord;

using namespace GarrysMod::Lua;

LUA_FUNCTION(LDRPC_Init) {
	char const *id = LUA->GetString(1);
	if (id != NULL) discord->Initialize(id);
	else discord->Initialize();
	discord->Update("In-game");
	return 0;
}

LUA_FUNCTION(LDRPC_Update) {
	LUA->CheckString(1);
	char const *state = LUA->GetString(1);
	discord->Update(state);
	return 0;
}

LUA_FUNCTION(LDRPC_Shutdown) {
	discord->Shutdown();
	return 0;
}

GMOD_MODULE_OPEN() {
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	LUA->CreateTable();

	LUA->PushCFunction(LDRPC_Init);
	LUA->SetField(-2, "Initialize");

	LUA->PushCFunction(LDRPC_Update);
	LUA->SetField(-2, "Update");

	LUA->PushCFunction(LDRPC_Shutdown);
	LUA->SetField(-2, "Shutdown");

	LUA->SetField(-2, "LDRPC");
	LUA->Pop();

	return 0;
}

GMOD_MODULE_CLOSE() {
	return 0;
}