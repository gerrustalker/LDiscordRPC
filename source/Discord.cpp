#include "Discord.h";
#include <iostream>;
#include <chrono>;

void Discord::Initialize(const char* appid) {
    DiscordEventHandlers eventhandlers;
    memset(&eventhandlers, 0, sizeof(eventhandlers));
    Discord_Initialize(appid, &eventhandlers, 1, "4000");
};

void Discord::Shutdown() {
    Discord_Shutdown();
};

void Discord::Update(const char* state) {
    static int64_t bigshit = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = state;
    discordPresence.details = "Playing Garry's Mod";
    discordPresence.startTimestamp = bigshit;
    discordPresence.largeImageKey = "smallmain";
    discordPresence.largeImageText = "Garry's Mod";
    discordPresence.smallImageKey = "bigmain";
    discordPresence.smallImageText = ">w<";
    Discord_UpdatePresence(&discordPresence);
};