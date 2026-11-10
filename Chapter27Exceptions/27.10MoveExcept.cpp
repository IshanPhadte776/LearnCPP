std::move_if_noexcept

MoveClass safe2{ std::move_if_noexcept(safe1) };

//its a std::move() but, we also move if and only if move constructor is maked as noexcept, then calls the move constructor, if not, won't call the move constructor