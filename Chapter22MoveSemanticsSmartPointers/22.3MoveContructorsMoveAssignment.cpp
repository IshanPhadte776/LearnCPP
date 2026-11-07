//std::move turns lvalues to rvalues (static_cast) doesn't move anything
//hey, this variable is a rvalue now, feel free to steal its resources and its memory address

// Conceptual implementation of std::move:
template <typename T>
constexpr std::remove_reference_t<T>&& move(T&& arg) noexcept {
    return static_cast<std::remove_reference_t<T>&&>(arg);
}


// ANTI-PATTERN:
std::string getName() {
    std::string name{ "Alice" };
    return std::move(name); // BAD!
}
//this is bad, disables RVO