# Cactus-ModLoader
A fork-agnostic and cross-platform Mod Loader for LCE.

Join the discord
https://discord.gg/YFdVHmUvdm

# Scope
The scope of this project is to have a fork-agnostic and cross-platform Mod Loader for LCE

Goals: 

* Add custom block and item registration with custom textures 
* Event system
* Client and server modding using LUA scripting (already implemented)
* Allow for modding the UI
* Custom generation and dimensions
* Port Cactus ModLoader to Minecraft Java Edition
* String ID system for items and blocks
* More...

# Building
### Dependencies
This project requires Lua 5.4 and its developments headers for compiling 

Ubuntu
```bash
sudo apt install lua5.4 liblua5.4-dev
```

Arch Linux
```bash
sudo pacman -S lua
```

Fedora
```bash
sudo dnf install lua lua-devel
```

Windows: I suggest using the [vcpkg](https://vcpkg.io/en/) package manager to install the dependencies or you can download the pre-compiled binaries and headers on the [LuaBinaries](https://luabinaries.sourceforge.net/download.html) website.
```PowerShell
vcpkg install lua:x64-windows
```


# Implementing and building
Cactus ModLoader is made to be fork-agnostic so that it could be implemented into any fork of LCE (LCEMP, MinecraftConsoles, 4jcraft etc...)
I am currently working on a implementation of Cactus ModLoader for 4jcraft while developing and expending the mod loader
You can contribute to it on the [cml-implementation](https://github.com/MathiewMay/4jcraft-mmay/tree/feat/cml-implementation) branch of my 4jcraft fork

# Contribution policy
Submitting code to this repository authored by generative AI tools (LLMs, agentic coding tools, etc...) is strictly forbidden
Pull requests that are clearly vibe-coded or written by an LLM will be closed. 
Contributors are expected to both fully understand the code that they write and have the necessary skills to maintain it.
You should not contribute any LCE derived or copied code to the Cactus ModLoader project, that sould be contributed to the respective implementations

