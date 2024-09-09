#pragma once
#include "client/rBitrage/systems/System.h"
#include "client/rBitrage/actors/Actor.h"
#include <vector>
#include <memory>
#include <algorithm>

namespace RMC::rBitrage 
{
    class Scene 
    {
        public:
            Scene()
            {

            }
            
            bool HasActor(Actor* actor)
            {
                 return std::find(_actors.begin(), _actors.end(),
                      std::make_shared<Actor*>(actor)) != _actors.end();
            }

            void AddActor(Actor* actor) 
            {
                if (HasActor(actor))
                {
                    std::cout << "AddActor() Failed" << std::endl;
                }

                _actors.push_back(std::make_shared<Actor*>(actor));
            }

            void RemoveActor(Actor* actor) 
            {
                if (!HasActor(actor))
                {
                    std::cout << "RemoveActor() Failed, no actor" << std::endl;
                }

                // _actors.erase
                //     (
                //         std::remove_if(_actors.begin(), _actors.end(),
                //         [&actor](const auto& ptr)
                //         { 
                //             return static_cast<Actor*>(ptr.get()) == actor;
                //         }),
                //         _actors.end()
                //     );
            }

            std::vector<std::shared_ptr<Actor*>> GetActors()
            {
               return _actors;
            }
        private:
            std::vector<std::shared_ptr<Actor*>> _actors;
    };
}
