/**
 * @file ObjectCreationException.hpp
 * @brief An exception object to handle failed object creations
 * @author Lauchmelder23
 * @date 16.05.2020
 */
#pragma once
#include <exception>

namespace sdlu
{
    class ObjectCreationException : 
        virtual public std::exception
    {
    public:
        ObjectCreationException(const char* description) :
            m_pDescription(description)
        {
            // Empty
        }

        virtual const char* what() const throw()
        {
            return m_pDescription;
        }

    private:
        const char* m_pDescription;
    };
}