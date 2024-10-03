#pragma once

#include<stdio.h>
#include<memory>
#include<map>
#include<unordered_map>

namespace ly
{
template<typename T>
using unique = std::unique_ptr<T>;

template<typename T>
using shared = std::shared_ptr<T>;

template<typename T>
using weak = std::weak_ptr<T>;

template<typename T>
using list = std::vector<T>;

template<typename KeyType, typename valType, typename Pr = std::less<KeyType>>
using Map = std::map<KeyType, valType, Pr>;

template<typename KeyType, typename valType, typename Hasher = std::hash<KeyType>>
using Dictionary = std::unordered_map<KeyType, valType, Hasher>;

//a macro
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

}