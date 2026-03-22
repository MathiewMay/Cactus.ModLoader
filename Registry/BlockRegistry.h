#pragma once

class BlockRegistry {
public:
    static int nextItemId();

    static int registerBlock(const std::wstring& modId, const std::string& name, const std::string& texturePath);
};
