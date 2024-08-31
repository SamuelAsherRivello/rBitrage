#pragma once
#include <raylib.h>
#include "System.h"
#include "Game.h"
#include <unordered_map>
#include <string>
#include <iostream>

namespace RMC::rBitrage 
{
    class LoaderSystem : public System 
    {
        public:
            LoaderSystem(Game& game);
            ~LoaderSystem() = default; //it's a good practice to include an empty destructor (= default) if your class doesn't perform any custom cleanup. 
            void OnInitialize() override;

            //
            template <typename T>
            bool HasAsset(const char *assetKey);

            template <typename T>
            void AddAsset(const char *assetPath, const char *assetKey);

            template <typename T>
            T GetAssetCopy(const char *assetKey);


        private:
            std::unordered_map<std::string, Image> _assetsByKey;  
            
    };

    template <typename T>
    void LoaderSystem::AddAsset(const char *assetKey, const char *assetPath) 
    {
        T asset = T();

        if (std::is_same<T, Image>::value) 
        {
            asset = LoadImage(assetPath);
        }
        else
        {
            std::cout << "LoaderSystem::AddAsset() failed. Type not supported." << std::endl;
            return;
        }

        if (HasAsset<T>(assetKey)) {  // 
            _assetsByKey[std::string(assetKey)] = asset;  // replace
        } else {
            _assetsByKey[std::string(assetKey)] = asset;  // add new
        }

    }

    template <typename T>
    bool LoaderSystem::HasAsset(const char *assetKey) 
    {
        return _assetsByKey.find(assetKey) != _assetsByKey.end();
    }

    template <typename T>
    T LoaderSystem::GetAssetCopy(const char *assetKey)
    {
        Image copy = ImageCopy(_assetsByKey[std::string(assetKey)]);
        return copy;
    }

} 
