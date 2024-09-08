#pragma once
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/actors/Actor.h"
#include "3rdParty/tweeny/tweeny/tweeny.h"
#include <any>

namespace RMC::rBitrage 
{
    class TweenSystem : public System 
    {
        public:
            TweenSystem(Game& game);
            void OnInitialize() override;
            void OnFrameUpdate(float deltaTime) override;
            //
            template<typename... Ts> 
            inline tweeny::tween<Ts...> from(Ts... vs) ;

        private:
            //TODO: strong type here
            std::any _tween;

    };

    template<typename... Ts> 
    inline tweeny::tween<Ts...> TweenSystem::from(Ts... vs) 
    {
        tweeny::tween<Ts...> tween = tweeny::tween<Ts...>::from(vs...);

        //TODO: set _tween =
        return tween;
    }

} 
