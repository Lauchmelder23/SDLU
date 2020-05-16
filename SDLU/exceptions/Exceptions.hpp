/**
 * @file Exceptions.hpp
 * @brief Provides utility and includes all exceptions
 * @author Lauchmelder23
 * @date 16.05.2020
*/
#pragma once

#include "ObjectCreationException.hpp"

#define THROW_IF( condition, exception ) ( condition ? throw exception : false)
#define THROW_IF_NOT( condition, exception ) ( THROW_IF(!condition, exception) )