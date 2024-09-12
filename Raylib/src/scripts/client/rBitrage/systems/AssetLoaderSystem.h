#pragma once
#include <raylib.h>
#include <unordered_map>
#include <string>
#include <iostream>
//
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/core/Game.h"
#include "client/rBitrage/types/Asset.h"
#include "client/rBitrage/utilities/Utilities.h"

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

            template <typename T>
            T GetAssetAsModel(const char *assetKey);

            template <typename T>
            T GetAssetAsTexture2D(const char *assetKey);

            void LoadAllAssets();
            
        private:

            //TODO: Ideally we have one is with value of T or Asset<T>. I could not get it to work.
            //WORKAROUND: Separate list for each type. Not bad.
            std::unordered_map<std::string, ImageAsset> _imageAssetsByKey;  
            std::unordered_map<std::string, SoundAsset> _soundAssetsByKey;
            std::unordered_map<std::string, ModelAsset> _modelAssetsByKey;
            std::unordered_map<std::string, Texture2DAsset> _texture2DAssetsByKey;

           
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
        else if (std::is_same<T, Model>::value) 
        {
            Model asset = LoadModel(assetPath);
            _modelAssetsByKey[std::string(assetKey)] = ModelAsset(std::string(assetKey), asset);
        }
        else if (std::is_same<T, Texture2D>::value) 
        {
            Texture2D asset = LoadTexture(assetPath);
            _texture2DAssetsByKey[std::string(assetKey)] = Texture2DAsset(std::string(assetKey), asset);
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
        if (Utilities::IsNullOrEmpty(assetKey))
        {
            std::cout << "ERROR: LoaderSystem::HasAsset() failed. assetKey must NOT be null or empty." << std::endl;
            return false;
        }

        if (std::is_same<T, Image>::value) 
        {
            return _imageAssetsByKey.find(assetKey) != _imageAssetsByKey.end();
        }
        else if (std::is_same<T, Sound>::value) 
        {
            return _soundAssetsByKey.find(assetKey) != _soundAssetsByKey.end();
        }
        else if (std::is_same<T, Model>::value) 
        {
            return _modelAssetsByKey.find(assetKey) != _modelAssetsByKey.end();
        }
        else if (std::is_same<T, Texture2D>::value) 
        {
            return _texture2DAssetsByKey.find(assetKey) != _texture2DAssetsByKey.end();
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
            return ImageCopy(_imageAssetsByKey[std::string(assetKey)].GetAsset());
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

    //TODO: Remove "As Model" and work more generically
    template <typename T>
    T AssetLoaderSystem::GetAssetAsModel(const char *assetKey)
    {
        if (std::is_same<T, Model>::value) 
        {
            //no copy needed?
            return _modelAssetsByKey[std::string(assetKey)].GetAsset();
        }
        else
        {
             std::cout << "ERROR: LoaderSystem::GetAssetAsModel() failed. Type T not supported." << std::endl;
            return T();
        }
    }

        //TODO: Remove "As Model" and work more generically
    template <typename T>
    T AssetLoaderSystem::GetAssetAsTexture2D(const char *assetKey)
    {
        if (std::is_same<T, Texture2D>::value) 
        {
            //no copy needed?
            return _texture2DAssetsByKey[std::string(assetKey)].GetAsset();
        }
        else
        {
             std::cout << "ERROR: LoaderSystem::GetAssetAsTexture2D() failed. Type T not supported." << std::endl;
            return T();
        }
    }
} 
