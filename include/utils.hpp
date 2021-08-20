#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "fwd.hpp"

#include <type_traits>
#include <cstring>

namespace qb{
namespace details
{
template<typename T>
using remove_cvr_t = std::remove_cv_t<std::remove_reference_t<T>>;
template<typename T>
constexpr inline std::size_t getSize(T && t){
    if constexpr(std::rank_v<remove_cvr_t<T>> != 0){
        return std::rank_v<remove_cvr_t<T>>;
    } else if constexpr(std::is_same_v<T, const char*&>) {
        return std::strlen(t);
    } else if constexpr(std::is_same_v<remove_cvr_t<T>, std::string>) {
        return t.size();
    } else{
        assert(false);
    }
}
template <class T>
inline bool has(std::string &s, T&& m){
    return s.find(std::forward<T&&>(m)) != std::string::npos;
}
template <class T>
inline bool startsWith(std::string &s, T&& m){
    for (int i = 0; i < getSize(m); i++)
    {
        if(s[i] != m[i]) return false;
    }
    return true;
}
template <class T>
inline std::size_t findStartsWith(std::string &s, T&& m){
    for (int i = 0; i < getSize(m); i++)
    {
        if(s[i] != m[i]) return std::string::npos;
    }
    return getSize(m);
}
} // namespace details
void bind(Cyan::MiraiBot& bot);
}
#endif 