# LDiscordRPC
**LDiscordRPC** aka Lenofag's [Discord RPC](https://github.com/discord/discord-rpc) (Rich Presence) for **Garry's Mod**


## [Download](https://github.com/gerrustalker/LDiscordRPC/releases)
## Preview
![DiscordRPC Preview (YES YOU CAN CHANGE THIS IMAGE)](https://github.com/gerrustalker/LDiscordRPC/blob/main/images/preview1.png)\
![Cool console tag](https://github.com/gerrustalker/LDiscordRPC/blob/main/images/consoletag.png)


## Installation
1. [Download](https://github.com/gerrustalker/LDiscordRPC/releases) the latest release
2. Put `gmsv_ldrpc_win32.dll` to `GarrysMod/garrysmod/lua/bin/` folder
3. Put `lua` folder to `Garrysmod/garrysmod/`

### bruh how do i change this image
~~You don't.~~\
You will need to [compile](#source-compiling) it yourself :)


## Source compiling
*Note: this was compiled in Visual Studio 2019*
###
You will need to change `Discord.cpp` to set your [Discord Application ID](https://discord.com/developers/applications/) and image key
* ID at line **30**
* Image at line **45**

### Dependencies:
* [DiscordRPC](https://github.com/Classic1338/DiscordRichPresence-) ([yes](https://www.unknowncheats.me/forum/general-programming-and-reversing/361227-adding-discord-rich-presence-cheat.html))
* [garrysmod-common](https://github.com/danielga/garrysmod_common) by [danielga](https://github.com/danielga/)

#### DiscordRPC:
1. Require `/include/`
2. Copy `/src/` folder to project (like [this](https://github.com/gerrustalker/LDiscordRPC/blob/main/images/discordrpcsrc.png))

#### garrysmod-common:
1. Download [premake5](https://premake.github.io/download)
2. Put premake5.exe to project folder
3. Open `cmd` in project folder, then write in `premake5.exe vs2019`
4. In new created folder named `project`, you will find your **solution file**