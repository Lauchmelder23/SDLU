/**
 * @file ObjectCreationException.hpp
 * @brief An exception object to handle failed object creations
 * @author Lauchmelder23
 * @date 16.05.2020
 */
#pragma once
#include <exception>
#include <string>

namespace sdlu
{
    class ObjectCreationException : 
        virtual public std::exception
    {
    public:
        ObjectCreationException(std::string description) :
            m_pDescription(description)
        {
            // Empty
        }

        virtual const char* what() const throw()
        {
            return m_pDescription.c_str();
        }

    private:
        std::string m_pDescription;
    };
}