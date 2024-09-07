#include "client\templates\TemplateClass.h"

/**
 * Naming And Casing 
 * 
 * PascalCase 
 * 
 *      - Class Names ( ex. MyNameIs )
 *      - Class Public Members
 *      - Class Public Static Members
 *      - Folder Names
 *      - Enum Names
 *      - Struct Names
 * 
 * CamelCase With "_" 
 * 
 *      - Class Private Members ( ex. _myNameIs )
 *      - Class Private Static Members
 * 
 * CamelCase Without "_" 
 * 
 *      - Local Variables ( ex. myNameIs )
 * 
 */


namespace RMC::Templates 
{
    /**
     * Constructor to initialize the age.
     * @param age The initial age to set.
     */
    TemplateClass::TemplateClass(int age) : _age(age) 
    {

    }


    /**
     * Sets the age.
     * @param age The new age to set.
     */
    void TemplateClass::SetAge(int age) 
    {
        this->_age = age;
    }


    /**
     * Gets the age.
     * @return The current age.
     */
    int TemplateClass::GetAge() const 
    {
        return this->_age;
    }


    /**
     * Increments the age by one.
     */
    void TemplateClass::_incrementAge() 
    {
        this->_age++;
    }
}
