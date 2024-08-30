
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
}

namespace RMC::rBitrage 
{
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
}


namespace RMC::rBitrage 
{
    class ImageAsset : public Asset<Image>
    {
        public:
            ImageAsset() : Asset()
            {
                
            }
            ImageAsset(std::string assetKey, Image image) : Asset(assetKey, image)
            {
            }
        
        private:

    };
}

namespace RMC::rBitrage 
{
    class SoundAsset : public Asset<Sound>
    {
        public:
            SoundAsset() : Asset()
            {
                
            }
            SoundAsset(std::string assetKey, Sound image) : Asset(assetKey, image)
            {
            }

        private:

    };
}