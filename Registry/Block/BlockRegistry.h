#pragma once

class BlockRegistry {
public:
    static int nextItemId();

    static int registerBlock(const std::wstring& path, const std::string& id, const std::string& name, std::string modId, const std::string& texturePath);
};
