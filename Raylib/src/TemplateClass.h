#pragma once
#include <string>

namespace RMC::Templates 
{
    class TemplateClass 
    {
        public:
            TemplateClass(int age);
            void SetAge(int age);
            int GetAge() const;


        private:
            int _age;
            void _incrementAge();
    };
}