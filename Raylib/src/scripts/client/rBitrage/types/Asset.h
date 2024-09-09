
#pragma once
#include <raylib.h>
#include <string>


//TODO: Collapse all classes into 1 when I figure out how to store Image **OR** Sound as 'value'
namespace RMC::rBitrage 
{
    class AssetBase
    {
        public:
        
            AssetBase() : AssetBase(""){}

            AssetBase(std::string assetKey)
            {
                this->_assetKey = assetKey;
            }

            std::string GetAssetKey()
            {
                return _assetKey;
            }
           

        private:
         std::string _assetKey;

    };


    template <typename T>
    class Asset : public AssetBase
    {
        public:
            Asset () : AssetBase()
            {
                
            }

            Asset(std::string assetKey, T asset) : AssetBase(assetKey)
            {
                this->_asset = asset;
            }
        
            T GetAsset()
            {
                return _asset;
            }

        private:
            T _asset;
    };

    class ImageAsset : public Asset<Image>
    {
        public:
            ImageAsset() : Asset()
            {
                
            }
            ImageAsset(std::string assetKey, Image asset) : Asset(assetKey, asset)
            {
            }
        
        private:

    };

    class SoundAsset : public Asset<Sound>
    {
        public:
            SoundAsset() : Asset()
            {
                
            }
            SoundAsset(std::string assetKey, Sound asset) : Asset(assetKey, asset)
            {
            }

        private:

    };

    class ModelAsset : public Asset<Model>
    {
        public:
            ModelAsset() : Asset()
            {
                
            }
            ModelAsset(std::string assetKey, Model asset) : Asset(assetKey, asset)
            {
            }

        private:

    };

    class Texture2DAsset : public Asset<Texture2D>
    {
        public:
            Texture2DAsset() : Asset()
            {
                
            }
            Texture2DAsset(std::string assetKey, Texture2D asset) : Asset(assetKey, asset)
            {
            }

        private:

    };
}