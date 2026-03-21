#pragma once

class BlockRegistry {
    public:
        static int registerBlock(const std::wstring& modId, const std::string& name, const std::string& texturePath);

        static void initIds();

        static void _registerBlocks();
};
