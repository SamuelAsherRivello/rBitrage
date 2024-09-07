#pragma once
#include <raylib.h>
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/types/Asset.h"
#include <unordered_map>
#include <string>
#include <iostream>

namespace RMC::rBitrage 
{
    class AssetLoaderSystem : public System 
    {
        public:
            AssetLoaderSystem(Game& game);
            ~AssetLoaderSystem() = default; //it's a good practice to include an empty destructor (= default) if your class doesn't perform any custom cleanup. 
            void OnInitialize() override;

            //
            template <typename T>
            bool HasAsset(const char *assetKey);

            template <typename T>
            void AddAsset(const char *assetPath, const char *assetKey);

            template <typename T>
            T GetAssetAsImage(const char *assetKey);

            template <typename T>
            T GetAssetAsSound(const char *assetKey);

            void LoadAllAssets();
            
        private:

            //TODO: Ideally we have one is with value of T or Asset<T>. I could not get it to work.
            //WORKAROUND: Separate list for each type. Not bad.
            std::unordered_map<std::string, ImageAsset> _imageAssetsByKey;  
            std::unordered_map<std::string, SoundAsset> _soundAssetsByKey;

           
    };

    template <typename T>
    void AssetLoaderSystem::AddAsset(const char *assetKey, const char *assetPath) 
    {
        if (HasAsset<T>(assetKey)) 
        { 
            std::cout << "ERROR: LoaderSystem::AddAsset() failed. Asset already exists in the map." << std::endl;
            return;
        }

        if (std::is_same<T, Image>::value) 
        {
            Image asset = LoadImage(assetPath);
             _imageAssetsByKey[std::string(assetKey)] = ImageAsset(std::string(assetKey), asset);
        }
        else if (std::is_same<T, Sound>::value) 
        {
            Sound asset = LoadSound(assetPath);
            _soundAssetsByKey[std::string(assetKey)] = SoundAsset(std::string(assetKey), asset);
        }
        else
        {
             std::cout << "ERROR: LoaderSystem::AddAsset() failed. Type T not supported." << std::endl;
            return;
        }


    }

    template <typename T>
    bool AssetLoaderSystem::HasAsset(const char *assetKey) 
    {
        if (std::is_same<T, Image>::value) 
        {
            return _imageAssetsByKey.find(assetKey) != _imageAssetsByKey.end();
        }
        else if (std::is_same<T, Sound>::value) 
        {
            return _soundAssetsByKey.find(assetKey) != _soundAssetsByKey.end();
        }
        else
        {
             std::cout << "ERROR: LoaderSystem::HasAsset() failed. Type T not supported." << std::endl;
            return false;
        }

       
    }


    //TODO: Remove "As Image" and work more generically
    template <typename T>
    T AssetLoaderSystem::GetAssetAsImage(const char *assetKey)
    {
        if (std::is_same<T, Image>::value) 
        {
            //TODO: use copy?
            //for now We do a copy since resizing (by user, a moment later) would break shared images. 
            Image copy = ImageCopy(_imageAssetsByKey[std::string(assetKey)].GetAsset());
            return copy;
        }
        else
        {
             std::cout << "ERROR: LoaderSystem::GetAssetCopy() failed. Type T not supported." << std::endl;
            return T();
        }
    }

    //TODO: Remove "As Sound" and work more generically
    template <typename T>
    T AssetLoaderSystem::GetAssetAsSound(const char *assetKey)
    {
        if (std::is_same<T, Sound>::value) 
        {
            //no copy needed?
            return _soundAssetsByKey[std::string(assetKey)].GetAsset();
        }
        else
        {
             std::cout << "ERROR: LoaderSystem::GetAssetCopy() failed. Type T not supported." << std::endl;
            return T();
        }
    }


} 
