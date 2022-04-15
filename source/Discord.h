#pragma once
#include <discord_register.h>;
#include <discord_rpc.h>;

class Discord {
public:
	void Initialize(const char* appid = "YOURIDHERE :)");
	void Shutdown();
	void Update(const char* state = "In-game");
};