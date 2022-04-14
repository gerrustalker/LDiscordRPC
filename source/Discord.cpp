#include "Discord.h";
#include <iostream>;
#include <chrono>;

/*namespace Discord {
    void Initialize() {
        DiscordEventHandlers eventhandlers;
        memset(&eventhandlers, 0, sizeof(eventhandlers));
        Discord_Initialize("963257446049153074", &eventhandlers, 1, "4000");
    }

    void Update() {
        DiscordRichPresence discordPresence;
        memset(&discordPresence, 0, sizeof(discordPresence));
        discordPresence.state = "In-game";
        discordPresence.details = "Playing Garry's Mod";
        discordPresence.startTimestamp = 1507665886;
        //discordPresence.largeImageText = "Garry's Mod";
        Discord_UpdatePresence(&discordPresence);
    }

    void Shutdown() {
        Discord_Shutdown();
    }
*/

void Discord::Initialize() {
    DiscordEventHandlers eventhandlers;
    memset(&eventhandlers, 0, sizeof(eventhandlers));
    Discord_Initialize("YOURIDHERE", &eventhandlers, 1, "4000");
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
    discordPresence.largeImageKey = "YOURIMAGEIDHERE";
    discordPresence.largeImageText = ">w<";
    //discordPresence.largeImageText = "Garry's Mod";
    Discord_UpdatePresence(&discordPresence);
};