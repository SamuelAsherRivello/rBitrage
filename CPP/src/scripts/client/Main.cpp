#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <any>
#include <algorithm>  
#include <memory>

class Image {
    public:
        Image() {
        }
};

template <typename T>
class Asset 
{
    public:
        Asset(const char* key, const char* path, const T& value)
            : _key(key), _path(path), _value(value) 
        {

        }
        Asset(const char* key, const char* path)
            : _key(key), _path(path), _value(T()) 
        {

        }

        const char* getKey() const { return _key; }
        const char* getPath() const { return _path; }

        void setValue(const T& value) { _value = value; }
        const T& getValue() const { return _value; }

        std::type_info getType() const {
            return typeid(T);
        }

        virtual T Load() const {
            std::cout << "Loading asset: " << _path << std::endl;
            return T(); // Return a default instance of the type
        }

    private: 
        const char* _key;
        const char* _path;

    protected: 
        T _value;
}; 


class ImageAsset : public Asset<Image> {
public:
    ImageAsset(const char* key, const char* path)
        : Asset<Image>(key, path) 
    {
        // Constructor initializes base Asset with Image type
    }

    Image Load() const override {

        return this->getValue();
    }
};



class AssetLoader {
    public:

        template <typename T>
        void AddAsset(const char* key, const char* path)
        {
            _assets.emplace_back(key, path);
        }

        template <typename T>
        bool HasAsset(const char* key) 
        {
            for (auto& asset : _assets)
            {
                if (asset.getKey() == key)
                {
                    return true;
                }
            }
            return false;
        }

        template <typename T>
        Asset<T> GetAsset(const char* key) 
        {
            if (!HasAsset<T>(key))
            {
                throw std::invalid_argument( "GetAsset failed." );
            }
            for (auto& asset : _assets)
            {
                if (asset.getKey() == key)
                {
                    //#workaround for strong typing...
                    Asset<T> foundAsset = Asset<T>(asset.getKey(), asset.getPath());
                    foundAsset.Load();
                    return foundAsset;
                }
            }
            throw std::invalid_argument( "GetAsset failed." );
        }

        void LoadAllAssets()
        {
            for (auto& a : _assets)
            {
                a.Load();
            }
        }

    private:
        std::vector<Asset<std::any>> _assets;
};


int main ()
{ 
    
    Asset<int> asset1("my_key", "/some/path", 42);
    Asset<const char*> asset2("my_key", "/some/path", "hello2"); 

    //workflow
    AssetLoader assetLoader = AssetLoader();
    bool has1 = assetLoader.HasAsset<int>("my_key");
    assetLoader.AddAsset<int>("my_key", "/some/path");
    bool has2 = assetLoader.HasAsset<int>("my_key");

    //Asset<int> assetGotten = 

    std::cout << "asset1 key: " << asset1.getKey() << std::endl;
    std::cout << "asset1 path: " << asset1.getPath() << std::endl;

    assetLoader.AddAsset<int>("my-start-key", "/some/start/path");
    assetLoader.GetAsset<int>("my-start-key");
    Asset<int> startGot = assetLoader.GetAsset<int>("my_key");
    assetLoader.LoadAllAssets();

    std::cout << "assetGotten: " << startGot.getKey() << std::endl;


    return 0;
}
