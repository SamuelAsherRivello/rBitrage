
#pragma once
#include <raylib.h>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>  

namespace RMC::rBitrage 
{
    /** 
    * Any subject and have a public event member(s) and invoke it.
    * Any observer can subscribe to the event.
    **/
    class Event
    {
        public:
            
            using Handler = std::function<void()>;

            void AddListener(const Handler& handler) 
            { 
                _listeners.push_back(handler); 
            }

            void RemoveListener(const Handler& handler) 
            {
                auto iterator = std::find_if(_listeners.begin(), _listeners.end(),
                    [&handler](const std::function<void()>& func){ return func.target<Handler>() == &handler; });
                
                if (iterator != _listeners.end()) {
                    _listeners.erase(iterator);
                }
            }

            void Invoke() 
            {
                for (const auto& listener : _listeners) 
                {
                    listener();
                }
            }

        private:
            std::vector<Handler> _listeners;

    };
}