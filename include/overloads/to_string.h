#ifndef TO_STRING_H
#define TO_STRING_H
#include <sstream>
#include <string>
#include <type_traits>

namespace mintest {
    // nullptr
    inline std::string to_string(std::nullptr_t) {
        return "nullptr";
    }

    inline std::string to_string(char ch) {
        return std::string(1, ch);
    }

    inline std::string to_string(unsigned char ch) {
        return std::to_string(static_cast<unsigned int>(ch));
    }

    inline std::string to_string(signed char ch) {
        return std::to_string(static_cast<int>(ch));
    }

    template <typename T>
    inline std::string to_string(T* ptr) {
        if (ptr == nullptr) return "nullptr";
        std::ostringstream oss;
        oss << static_cast<const void*>(ptr);
        return oss.str();
    }

    inline std::string to_string(bool val) {
        return (val) ? "true":"false";
    }

    template <typename T>
    inline std::enable_if_t<
        std::is_arithmetic_v<T>,
        std::string
    >
    to_string(T value) {
        return std::to_string(value);
    }

    // generic fallback
    template <typename T>
    inline std::enable_if_t<
        !std::is_arithmetic_v<T> &&
        !std::is_same_v<T, bool> &&
        !std::is_pointer_v<T>,
        std::string
    >
    to_string(const T& value) {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }
}

#endif
